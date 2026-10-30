/*
 * libsgn filesystem module — remount, file existence, executable write
 * Ghidra: remount_filesystem @ 0x0001211c, write_buffer_as_executable @ 0x0001225c,
 *         file_exists @ 0x000122b0
 */

#include <fcntl.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <unistd.h>

int remount_filesystem(const char *target)
{
    if (!target) return -1;
    return mount(target, target, NULL, MS_REMOUNT, NULL);
}

int file_exists(const char *path)
{
    struct stat st;
    if (!path) return 0;
    return (stat(path, &st) == 0) ? 1 : 0;
}

int write_buffer_as_executable(const char *path, const void *data, size_t len)
{
    int fd; ssize_t written;
    if (!path || !data || len == 0) return -1;
    fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0711);
    if (fd < 0) return -1;
    written = write(fd, data, len);
    close(fd);
    if ((size_t)written != len) return -1;
    chmod(path, 0711);
    return 0;
}
