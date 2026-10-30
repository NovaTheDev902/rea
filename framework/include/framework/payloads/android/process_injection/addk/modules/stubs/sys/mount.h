#ifndef SYS_MOUNT_H_STUB
#define SYS_MOUNT_H_STUB

#define MS_RDONLY  1
#define MS_REMOUNT 0x2000

int mount(const char *src, const char *tgt, const char *fstype, unsigned long flags, const void *data);
int umount(const char *target);

#endif
