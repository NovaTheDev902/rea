/*
 * libsgn device fingerprint — ETH0 MAC + FFmpeg-named MD5
 * Ghidra: av_md5_* @ 0x000030a8 … get_mac_address @ 0x000032f0
 */

#include "fingerprint.h"
#include "strings.h"

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

static uint32_t md5_rotl(uint32_t x, uint32_t n)
{
    return (x << n) | (x >> (32u - n));
}

static void md5_transform(uint32_t abcd[4], const uint8_t block[64])
{
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
        b = b + md5_rotl(a + f + K[i] + m[g], S[i]);
        a = tmp;
    }
    abcd[0] += a;
    abcd[1] += b;
    abcd[2] += c;
    abcd[3] += d;
}

void av_md5_init(AvMd5 *ctx)
{
    ctx->len_lo = 0;
    ctx->len_hi = 0;
    ctx->abcd[0] = 0x67452301u;
    ctx->abcd[1] = 0xefcdab89u;
    ctx->abcd[2] = 0x98badcfeu;
    ctx->abcd[3] = 0x10325476u;
}

void av_md5_update(AvMd5 *ctx, const void *data, uint32_t len)
{
    const uint8_t *p = data;
    uint32_t used = ctx->len_lo & 63u;
    uint32_t room;

    ctx->len_lo += len;
    if (ctx->len_lo < len)
        ctx->len_hi++;

    if (used) {
        room = 64u - used;
        if (len < room) {
            memcpy(ctx->block + used, p, len);
            return;
        }
        memcpy(ctx->block + used, p, room);
        md5_transform(ctx->abcd, ctx->block);
        p += room;
        len -= room;
    }
    while (len >= 64u) {
        md5_transform(ctx->abcd, p);
        p += 64;
        len -= 64u;
    }
    if (len)
        memcpy(ctx->block, p, len);
}

void av_md5_final(AvMd5 *ctx, uint8_t digest[16])
{
    uint8_t pad[8];
    uint32_t used;
    uint64_t bits;
    int i;

    bits = ((uint64_t)ctx->len_hi << 32) | (uint64_t)ctx->len_lo;
    bits <<= 3;
    pad[0] = (uint8_t)bits;
    pad[1] = (uint8_t)(bits >> 8);
    pad[2] = (uint8_t)(bits >> 16);
    pad[3] = (uint8_t)(bits >> 24);
    pad[4] = (uint8_t)(bits >> 32);
    pad[5] = (uint8_t)(bits >> 40);
    pad[6] = (uint8_t)(bits >> 48);
    pad[7] = (uint8_t)(bits >> 56);

    used = ctx->len_lo & 63u;
    ctx->block[used++] = 0x80;
    if (used > 56u) {
        memset(ctx->block + used, 0, 64u - used);
        md5_transform(ctx->abcd, ctx->block);
        used = 0;
    }
    memset(ctx->block + used, 0, 56u - used);
    memcpy(ctx->block + 56, pad, 8);
    md5_transform(ctx->abcd, ctx->block);

    for (i = 0; i < 4; i++) {
        digest[i * 4]     = (uint8_t)ctx->abcd[i];
        digest[i * 4 + 1] = (uint8_t)(ctx->abcd[i] >> 8);
        digest[i * 4 + 2] = (uint8_t)(ctx->abcd[i] >> 16);
        digest[i * 4 + 3] = (uint8_t)(ctx->abcd[i] >> 24);
    }
}

void av_md5_sum(uint8_t digest[16], const void *data, uint32_t len)
{
    AvMd5 ctx;

    av_md5_init(&ctx);
    av_md5_update(&ctx, data, len);
    av_md5_final(&ctx, digest);
}

void get_hexlified_md5(const void *data, char *out_hex, uint32_t len)
{
    uint8_t digest[16];
    int i;

    memset(digest, 0, sizeof(digest));
    av_md5_sum(digest, data, len);
    for (i = 0; i < 16; i++) {
        snprintf(out_hex, 3, LIBSGN_MD5_BYTE_FMT, (unsigned)digest[i]);
        out_hex += 2;
    }
    *out_hex = '\0';
}

void get_random_hexlified_md5(char *out_hex)
{
    unsigned char rnd[8];
    int fd;
    ssize_t n;
    time_t now;

    fd = open(LIBSGN_URANDOM, O_RDONLY);
    n = (fd >= 0) ? read(fd, rnd, sizeof(rnd)) : -1;
    if (fd >= 0)
        close(fd);

    if (n == (ssize_t)sizeof(rnd)) {
        get_hexlified_md5(rnd, out_hex, (uint32_t)sizeof(rnd));
        return;
    }
    now = time(NULL);
    get_hexlified_md5(&now, out_hex, (uint32_t)sizeof(now));
}

void get_mac_address(char *out_mac)
{
    FILE *fp;
    char line[20];
    unsigned b0, b1, b2, b3, b4, b5;

    memset(line, 0, sizeof(line));
    fp = fopen(LIBSGN_ETH0_ADDR, "r");
    if (!fp)
        return;
    fread(line, 1, 19, fp);
    if (sscanf(line, LIBSGN_ETH0_SCAN, &b0, &b1, &b2, &b3, &b4, &b5) == 6)
        snprintf(out_mac, 19, LIBSGN_MAC_FMT, b0, b1, b2, b3, b4, b5);
    fclose(fp);
}
