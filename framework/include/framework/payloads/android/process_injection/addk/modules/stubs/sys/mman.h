#ifndef SYS_MMAN_H_STUB
#define SYS_MMAN_H_STUB

#include <stddef.h>
#include <sys/types.h>

#define PROT_READ  1
#define PROT_WRITE 2
#define PROT_EXEC  4
#define MAP_PRIVATE 0x02
#define MAP_SHARED  1
#define MAP_FAILED ((void *)-1)

void *mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
int munmap(void *addr, size_t len);
int mprotect(void *addr, size_t len, int prot);

#endif
