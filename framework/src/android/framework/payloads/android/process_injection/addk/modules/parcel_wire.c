/*
 * Android Parcel wire-format reader — libk rebuild helper
 * Evidence: Ghidra FUN_00015618 parcel read sequence
 */

#include "parcel_wire.h"

#include <string.h>

enum {
    PARCEL_OFF_DATA = 4,
    PARCEL_OFF_SIZE = 8,
    PARCEL_OFF_POS = 12,
};

static int align4(parcel_view_t *pv)
{
    size_t pad = (4 - (pv->pos & 3)) & 3;
    if (pv->pos + pad > pv->size)
        return -1;
    pv->pos += pad;
    return 0;
}

parcel_view_t parcel_view_from_binder_parcel(void *android_parcel)
{
    parcel_view_t pv = { 0, 0, 0 };
    const uint8_t *base;
    const uint8_t *data;
    size_t sz;
    size_t pos;

    if (!android_parcel)
        return pv;

    base = (const uint8_t *)android_parcel;
    data = *(const uint8_t *const *)(base + PARCEL_OFF_DATA);
    sz = *(const size_t *)(base + PARCEL_OFF_SIZE);
    pos = *(const size_t *)(base + PARCEL_OFF_POS);

    if (!data || sz > 65536 || pos > sz)
        return pv;

    pv.data = data;
    pv.size = sz;
    pv.pos = pos;
    return pv;
}

parcel_view_t parcel_view_from_bytes(const uint8_t *data, size_t size, size_t pos)
{
    parcel_view_t pv = { 0, 0, 0 };

    if (!data || size > 65536 || pos > size)
        return pv;

    pv.data = data;
    pv.size = size;
    pv.pos = pos;
    return pv;
}

int parcel_enforce_interface(parcel_view_t *pv, const char *iface)
{
    const uint16_t *utf16;
    size_t n;
    size_t i;
    size_t iface_len;

    if (!pv || !iface || !pv->data)
        return -1;

    pv->pos = 0;
    if (parcel_read_string16(pv, &utf16, &n) != 0)
        return -1;

    iface_len = strlen(iface);
    if (n != iface_len)
        return -1;

    for (i = 0; i < n; i++) {
        if ((char)utf16[i] != iface[i])
            return -1;
    }
    return 0;
}

int parcel_read_int32(parcel_view_t *pv, int32_t *out)
{
    if (!pv || !out || !pv->data)
        return -1;
    if (align4(pv) != 0)
        return -1;
    if (pv->pos + 4 > pv->size)
        return -1;
    memcpy(out, pv->data + pv->pos, 4);
    pv->pos += 4;
    return 0;
}

int parcel_read_string16(parcel_view_t *pv, const uint16_t **out, size_t *char16_len)
{
    int32_t len;

    if (!pv || !out || !char16_len || !pv->data)
        return -1;
    if (align4(pv) != 0)
        return -1;
    if (parcel_read_int32(pv, &len) != 0)
        return -1;
    if (len < 0)
        return -1;

    *char16_len = (size_t)len;
    if (len == 0) {
        *out = (const uint16_t *)(pv->data + pv->pos);
        return 0;
    }

    if (pv->pos + (size_t)len * 2 > pv->size)
        return -1;
    *out = (const uint16_t *)(pv->data + pv->pos);
    pv->pos += (size_t)len * 2;
    align4(pv);
    return 0;
}
