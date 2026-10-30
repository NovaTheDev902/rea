#ifndef LIBSGN_FINGERPRINT_H
#define LIBSGN_FINGERPRINT_H

#include <stddef.h>
#include <stdint.h>

/* FFmpeg-derived AVMD5 layout used by av_md5_* @ 0x000030a8+ */
typedef struct AvMd5 {
    uint32_t len_lo;
    uint32_t len_hi;
    uint8_t  block[64];
    uint32_t abcd[4];
} AvMd5;

void av_md5_init(AvMd5 *ctx);
void av_md5_update(AvMd5 *ctx, const void *data, uint32_t len);
void av_md5_final(AvMd5 *ctx, uint8_t digest[16]);
void av_md5_sum(uint8_t digest[16], const void *data, uint32_t len);

/* get_hexlified_md5 @ 0x00003234 — writes 32 hex chars + NUL */
void get_hexlified_md5(const void *data, char *out_hex, uint32_t len);

/* get_random_hexlified_md5 @ 0x00003294 */
void get_random_hexlified_md5(char *out_hex);

/* get_mac_address @ 0x000032f0 — compact ETH0 hex into 12+NUL */
void get_mac_address(char *out_mac);

#endif
