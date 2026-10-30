#ifndef LIBK_PARCEL_WIRE_H
#define LIBK_PARCEL_WIRE_H

#include <stddef.h>
#include <stdint.h>

/*
 * Minimal Android Parcel wire reader for libk IME hook rebuild.
 * Ghidra FUN_00015618 @ 0x15618 — no libbinder required for parse logic.
 *
 * Layout view into android::Parcel (ARM32, AOSP ~4.x–6.x typical):
 *   offset 4:  mData      (uint8_t *)
 *   offset 8:  mDataSize  (size_t)
 *   offset 12: mDataPos   (size_t)
 * Verify against target API if linking on device.
 */
typedef struct {
    const uint8_t *data;
    size_t size;
    size_t pos;
} parcel_view_t;

parcel_view_t parcel_view_from_binder_parcel(void *android_parcel);

/* Direct buffer view — use for tests and when mData is already extracted */
parcel_view_t parcel_view_from_bytes(const uint8_t *data, size_t size, size_t pos);

int parcel_enforce_interface(parcel_view_t *pv, const char *iface);
int parcel_read_int32(parcel_view_t *pv, int32_t *out);
int parcel_read_string16(parcel_view_t *pv, const uint16_t **out, size_t *char16_len);

#endif
