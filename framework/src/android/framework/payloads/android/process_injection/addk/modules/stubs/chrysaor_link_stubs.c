/*
 * Host lab link stubs - satisfy symbols declared in native/stubs headers for
 * MSYS2/host gcc link tests only. Not used for NDK/device builds.
 */
#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/mount.h>
#include <sys/wait.h>
#include <dlfcn.h>
#include "android_lab.h"

#include <unistd.h>

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset)
{
    (void)addr;
    (void)len;
    (void)prot;
    (void)flags;
    (void)fd;
    (void)offset;
    return (void *)0x1000;
}

int munmap(void *addr, size_t len)
{
    (void)addr;
    (void)len;
    return 0;
}

int mprotect(void *addr, size_t len, int prot)
{
    (void)addr;
    (void)len;
    (void)prot;
    return 0;
}

int waitpid(pid_t pid, int *status, int options)
{
    (void)pid;
    (void)status;
    (void)options;
    return 0;
}

int mount(const char *src, const char *tgt, const char *fstype, unsigned long flags, const void *data)
{
    (void)src;
    (void)tgt;
    (void)fstype;
    (void)flags;
    (void)data;
    return 0;
}

int umount(const char *target)
{
    (void)target;
    return 0;
}

int chown(const char *path, unsigned uid, unsigned gid)
{
    (void)path;
    (void)uid;
    (void)gid;
    return 0;
}

#ifndef _CHRYSAOR_GETUID_STUB
#define _CHRYSAOR_GETUID_STUB
unsigned getuid(void)
{
    return 0;
}
#endif

#ifndef _CHRYSAOR_READLINK_STUB
#define _CHRYSAOR_READLINK_STUB
ssize_t readlink(const char *path, char *buf, size_t bufsiz)
{
    (void)path;
    (void)buf;
    (void)bufsiz;
    return -1;
}
#endif

void *dlopen(const char *path, int mode)
{
    (void)path;
    (void)mode;
    return (void *)1;
}

void *dlsym(void *handle, const char *symbol)
{
    (void)handle;
    (void)symbol;
    return (void *)0;
}

int dlclose(void *handle)
{
    (void)handle;
    return 0;
}

int stat(const char *path, struct stat *buf)
{
    (void)path;
    if (buf)
        buf->st_blksize = 0x100;
    return -1;
}

int fstat(int fd, struct stat *buf)
{
    (void)fd;
    if (buf)
        buf->st_size = 0;
    return 0;
}

png_structp png_create_write_struct(const char *a, void *b, void *c, void *d)
{
    (void)a;
    (void)b;
    (void)c;
    (void)d;
    static png_struct s;
    return &s;
}

png_infop png_create_info_struct(png_structp png)
{
    (void)png;
    static png_info i;
    return &i;
}

void png_destroy_write_struct(png_structp *png, png_infop *info)
{
    (void)png;
    (void)info;
}

void png_init_io(png_structp png, FILE *fp)
{
    (void)png;
    (void)fp;
}

void png_set_IHDR(png_structp png, png_infop info, unsigned w, unsigned h, int bd,
                  int ct, int interlace, int comp, int filter)
{
    (void)png;
    (void)info;
    (void)w;
    (void)h;
    (void)bd;
    (void)ct;
    (void)interlace;
    (void)comp;
    (void)filter;
}

void png_set_rows(png_structp png, png_infop info, png_bytepp rows)
{
    (void)png;
    (void)info;
    (void)rows;
}

void png_write_png(png_structp png, png_infop info, int transforms, void *params)
{
    (void)png;
    (void)info;
    (void)transforms;
    (void)params;
}
