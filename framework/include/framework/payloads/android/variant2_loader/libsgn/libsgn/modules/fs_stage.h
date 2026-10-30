#ifndef LIBSGN_FS_STAGE_H
#define LIBSGN_FS_STAGE_H

#include <stddef.h>

/* remount_filesystem @ 0x0000211c — match path in /proc/mounts, remount */
int remount_filesystem(const char *mount_path, unsigned extra_flags);

/* write_buffer_as_executable @ 0x0000225c — unlink, write, chmod 0711 */
int write_buffer_as_executable(const void *buf, size_t len, const char *path);

/*
 * file_exists @ 0x000022b0
 * Returns 1 if existence was determined (ENOENT counts as determined).
 * *out_exists is 1 when the path is present, 0 when absent.
 */
int file_exists(const char *path, int *out_exists);

/*
 * main @ 0x00001f1c staging branch:
 *   no /system/csk → write app-data .coldboot_init
 *   else → write, csk cat to OBB, chmod 0711, unlink temp
 */
int stage_coldboot_payload(const void *buf, size_t len);

#endif
