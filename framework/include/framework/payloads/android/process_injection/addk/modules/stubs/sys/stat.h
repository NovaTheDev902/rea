#ifndef SYS_STAT_H_STUB
#define SYS_STAT_H_STUB

#include <sys/types.h>

struct stat {
    off_t st_size;
    long st_blksize;
};

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);

#endif
