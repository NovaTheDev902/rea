/*
 * coruna_rootfs.h — Root filesystem remount chain
 *
 * From NadSec analysis of dump.bin:
 *   "Complete rootfs remount chain:
 *    1. Identify root partition (/dev/disk0s1s1)
 *    2. Manipulate APFS root snapshot
 *    3. Mount writable copy at OTA path
 *    4. Create RAM disks for temporary storage
 *    5. posix_spawn of system tools (mount_apfs, newfs_hfs)
 *    6. Remount root filesystem read-write"
 */
#ifndef CORUNA_ROOTFS_H
#define CORUNA_ROOTFS_H

#include <stdint.h>
#include <stdbool.h>
#include <coruna/coruna_driver.h>

/* Root partition */
#define CORUNA_ROOTFS_PARTITION     "/dev/disk0s1s1"
#define CORUNA_ROOTFS_OTA_PATH       "/private/var/MobileSoftware/mnt1"
#define CORUNA_ROOTFS_SNAPSHOT_NAME "orig-fs"

/* APFS snapshot operations */
int coruna_rootfs_find_snapshot(const char *snapshot, char *out_path, size_t out_len);
int coruna_rootfs_create_ramdisk(const char *mount_point, size_t size_mb);
int coruna_rootfs_mount_apfs(const char *source, const char *target);
int coruna_rootfs_make_hfs(const char *device, const char *mount_point);
int coruna_rootfs_remount_rw(const char *path);

/* Complete chain */
int coruna_rootfs_full_remount(const coruna_kernel_rw_t *rw,
                                 coruna_rootfs_t *rootfs);

#endif /* CORUNA_ROOTFS_H */
