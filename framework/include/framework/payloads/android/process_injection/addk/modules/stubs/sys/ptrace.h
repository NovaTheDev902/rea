#ifndef SYS_PTRACE_H_STUB
#define SYS_PTRACE_H_STUB

#include <sys/types.h>

#define PTRACE_TRACEME   0
#define PTRACE_ATTACH    16
#define PTRACE_DETACH    17
#define PTRACE_SYSCALL   24
#define PTRACE_GETREGS   12
#define PTRACE_SETREGS   13
#define PTRACE_POKETEXT  4
#define PTRACE_PEEKTEXT  1
#define PTRACE_CONT      7

static inline long ptrace(int request, pid_t pid, void *addr, void *data)
{
    (void)request;
    (void)pid;
    (void)addr;
    (void)data;
    return 0;
}

#endif
