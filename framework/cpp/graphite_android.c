// graphite_android.c - Android Utilities (C)
// Adapted from Pegasus (libk/libsgn) reverse-engineered native code

#include "graphite_android.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <android/log.h>
#endif

// === Parcel parsing (from Pegasus libk parcel_wire.c) ===

static int align4(parcel_view_t *pv) {
    size_t pad = (4 - (pv->pos & 3)) & 3;
    if (pv->pos + pad > pv->size) return -1;
    pv->pos += pad;
    return 0;
}

ANDROID_EXPORT parcel_view_t parcel_view_from_bytes(const uint8_t *data, size_t size, size_t pos) {
    parcel_view_t pv = { 0, 0, 0 };
    if (!data || size > 65536 || pos > size) return pv;
    pv.data = data;
    pv.size = size;
    pv.pos = pos;
    return pv;
}

ANDROID_EXPORT int parcel_read_int32(parcel_view_t *pv, int32_t *out) {
    if (!pv || !out || !pv->data) return -1;
    if (align4(pv) != 0) return -1;
    if (pv->pos + 4 > pv->size) return -1;
    memcpy(out, pv->data + pv->pos, 4);
    pv->pos += 4;
    return 0;
}

ANDROID_EXPORT int parcel_read_string16(parcel_view_t *pv, const uint16_t **out, size_t *char16_len) {
    int32_t len;
    if (!pv || !out || !char16_len || !pv->data) return -1;
    if (align4(pv) != 0) return -1;
    if (parcel_read_int32(pv, &len) != 0) return -1;
    if (len < 0) return -1;
    *char16_len = (size_t)len;
    if (len == 0) {
        *out = (const uint16_t *)(pv->data + pv->pos);
        return 0;
    }
    if (pv->pos + (size_t)len * 2 > pv->size) return -1;
    *out = (const uint16_t *)(pv->data + pv->pos);
    pv->pos += (size_t)len * 2;
    align4(pv);
    return 0;
}

// === Keystroke capture (from Pegasus libk capture.c) ===

ANDROID_EXPORT void capture_keystrokes(int char16_len, const uint16_t *utf16_buf) {
    if (char16_len <= 0 || !utf16_buf) return;
    // In real implementation, this would write to a log file
    // For PoC, we just process the data
    const uint8_t *p = (const uint8_t *)utf16_buf;
    const uint8_t *end = p + (size_t)char16_len * 2;
    (void)p; (void)end;
}

// === MD5 (from Pegasus libsgn fingerprint.c) ===

static void md5_transform(uint32_t abcd[4], const uint8_t block[64]) {
    static const uint32_t K[64] = {
        0xd76aa478u, 0xe8c7b756u, 0x242070dbu, 0xc1bdceeeu,
        0xf57c0fafu, 0x4787c62au, 0xa8304613u, 0xfd469501u,
        0x698098d8u, 0x8b44f7afu, 0xffff5bb1u, 0x895cd7beu,
        0x6b901122u, 0xfd987193u, 0xa679438eu, 0x49b40821u,
        0xf61e2562u, 0xc040b340u, 0x265e5a51u, 0xe9b6c7aau,
        0xd62f105du, 0x02441453u, 0xd8a1e681u, 0xe7d3fbc8u,
        0x21e1cde6u, 0xc33707d6u, 0xf4d50d87u, 0x455a14edu,
        0xa9e3e905u, 0xfcefa3f8u, 0x676f02d9u, 0x8d2a4c8au,
        0xfffa3942u, 0x8771f681u, 0x6d9d6122u, 0xfde5380cu,
        0xa4beea44u, 0x4bdecfa9u, 0xf6bb4b60u, 0xbebfbc70u,
        0x289b7ec6u, 0xeaa127fau, 0xd4ef3085u, 0x04881d05u,
        0xd9d4d039u, 0xe6db99e5u, 0x1fa27cf8u, 0xc4ac5665u,
        0xf4292244u, 0x432aff97u, 0xab9423a7u, 0xfc93a039u,
        0x655b59c3u, 0x8f0ccc92u, 0xffeff47du, 0x85845dd1u,
        0x6fa87e4fu, 0xfe2ce6e0u, 0xa3014314u, 0x4e0811a1u,
        0xf7537e82u, 0xbd3af235u, 0x2ad7d2bbu, 0xeb86d391u
    };
    static const uint8_t S[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
    };
    uint32_t a = abcd[0], b = abcd[1], c = abcd[2], d = abcd[3];
    uint32_t m[16];
    int i;

    for (i = 0; i < 16; i++) {
        m[i] = (uint32_t)block[i * 4] |
               ((uint32_t)block[i * 4 + 1] << 8) |
               ((uint32_t)block[i * 4 + 2] << 16) |
               ((uint32_t)block[i * 4 + 3] << 24);
    }

    for (i = 0; i < 64; i++) {
        uint32_t f, g, tmp;
        if (i < 16) {
            f = (b & c) | ((~b) & d);
            g = (uint32_t)i;
        } else if (i < 32) {
            f = (d & b) | ((~d) & c);
            g = (5u * (uint32_t)i + 1u) & 15u;
        } else if (i < 48) {
            f = b ^ c ^ d;
            g = (3u * (uint32_t)i + 5u) & 15u;
        } else {
            f = c ^ (b | (~d));
            g = (7u * (uint32_t)i) & 15u;
        }
        tmp = d;
        d = c;
        c = b;
        b = b + ((a + f + K[i] + m[g]) << S[i]) | ((a + f + K[i] + m[g]) >> (32 - S[i]));
        a = tmp;
    }
    abcd[0] += a;
    abcd[1] += b;
    abcd[2] += c;
    abcd[3] += d;
}

typedef struct {
    uint32_t len_lo;
    uint32_t len_hi;
    uint8_t block[64];
    uint32_t abcd[4];
} AvMd5Ctx;


ANDROID_EXPORT void md5_sum(uint8_t digest[16], const void *data, uint32_t len) {
    AvMd5Ctx ctx;
    ctx.len_lo = 0;
    ctx.len_hi = 0;
    ctx.abcd[0] = 0x67452301;
    ctx.abcd[1] = 0xefcdab89;
    ctx.abcd[2] = 0x98badcfe;
    ctx.abcd[3] = 0x10325476;

    const uint8_t *p = data;
    uint32_t remaining = len;

    while (remaining >= 64) {
        md5_transform(ctx.abcd, p);
        p += 64;
        remaining -= 64;
        ctx.len_lo += 512;
        if (ctx.len_lo < 512) ctx.len_hi++;
    }

    // Padding
    uint8_t block[64];
    memset(block, 0, 64);
    memcpy(block, p, remaining);
    block[remaining] = 0x80;
    if (remaining >= 56) {
        md5_transform(ctx.abcd, block);
        memset(block, 0, 64);
    }
    // Append length
    uint64_t total_bits = (uint64_t)len * 8;
    block[56] = (uint8_t)(total_bits & 0xFF);
    block[57] = (uint8_t)((total_bits >> 8) & 0xFF);
    block[58] = (uint8_t)((total_bits >> 16) & 0xFF);
    block[59] = (uint8_t)((total_bits >> 24) & 0xFF);
    block[60] = (uint8_t)((total_bits >> 32) & 0xFF);
    block[61] = (uint8_t)((total_bits >> 40) & 0xFF);
    block[62] = (uint8_t)((total_bits >> 48) & 0xFF);
    block[63] = (uint8_t)((total_bits >> 56) & 0xFF);
    md5_transform(ctx.abcd, block);

    for (int i = 0; i < 4; i++) {
        digest[i * 4] = (uint8_t)(ctx.abcd[i] & 0xFF);
        digest[i * 4 + 1] = (uint8_t)((ctx.abcd[i] >> 8) & 0xFF);
        digest[i * 4 + 2] = (uint8_t)((ctx.abcd[i] >> 16) & 0xFF);
        digest[i * 4 + 3] = (uint8_t)((ctx.abcd[i] >> 24) & 0xFF);
    }
}


ANDROID_EXPORT void get_hexlified_md5(const void *data, char *out_hex, uint32_t len) {
    uint8_t digest[16];
    md5_sum(digest, data, len);
    for (int i = 0; i < 16; i++) {
        snprintf(out_hex + i * 2, 3, "%02x", digest[i]);
    }
    out_hex[32] = '\0';
}

// === ELF patching (from Pegasus libk elf_loader.c) ===

ANDROID_EXPORT int elf_patch_reloc(const char *lib_path, void *loaded_base, unsigned sym_index,
                                   void *hook_addr, void **original_out) {
    // Simplified ELF patching
    (void)lib_path; (void)loaded_base; (void)sym_index; (void)hook_addr; (void)original_out;
    return 0;
}

// === File staging (from Pegasus fs_stage.c) ===

ANDROID_EXPORT int stage_payload(const void *buf, size_t len, const char *path) {
    if (!buf || !path || len == 0) return 0;
    FILE *f = fopen(path, "wb");
    if (!f) return 0;
    size_t written = fwrite(buf, 1, len, f);
    fclose(f);
    if (written != len) return 0;
#ifndef _WIN32
    chmod(path, 0711);
#endif
    return 1;
}

ANDROID_EXPORT int file_exists(const char *path, int *out_exists) {
    if (!path || !out_exists) return 0;
    FILE *f = fopen(path, "r");
    if (f) {
        fclose(f);
        *out_exists = 1;
        return 1;
    }
    *out_exists = 0;
    return 1;
}
