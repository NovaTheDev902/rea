#ifndef SYS_WAIT_H_STUB
#define SYS_WAIT_H_STUB

#include <sys/types.h>

#ifndef WUNTRACED
#define WUNTRACED 2
#endif
#ifndef WIFSTOPPED
#define WIFSTOPPED(status) (((status) & 0xff) == 0x7f)
#endif
#ifndef WSTOPSIG
#define WSTOPSIG(status) (((status) >> 8) & 0xff)
#endif
#ifndef SIGTRAP
#define SIGTRAP 5
#endif

int waitpid(pid_t pid, int *status, int options);

#endif
