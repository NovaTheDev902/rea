/*
 * addk ptrace helpers — rebuild spec from Ghidra implant fns
 * Addresses: attach 0x9128, get/setregs, cont, detach, call, poke/peek
 */

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/user.h>

#ifndef PTRACE_GETREGS
#define PTRACE_GETREGS 12
#define PTRACE_SETREGS 13
#endif

typedef struct {
    unsigned long uregs[18];
} pt_regs;

static void die(int code, const char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(code);
}

void ptrace_attach(pid_t pid)
{
    long rc;
    int status;

    rc = ptrace(PTRACE_ATTACH, pid, NULL, NULL);
    if (rc < 0)
        die(0x0f, "ptrace attach failed");

    waitpid(pid, &status, 0);

    /* PTRACE_SYSCALL sync — optional on emulators lacking it (ENOSYS) */
    rc = ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
    if (rc < 0) {
        if (errno != ENOSYS)
            die(0x13, "ptrace syscall sync failed");
        return;
    }

    waitpid(pid, &status, 0);
}

void ptrace_getregs(pid_t pid, pt_regs *regs)
{
    if (ptrace(PTRACE_GETREGS, pid, NULL, regs) < 0)
        die(0x1a, "ptrace getregs failed");
}

void ptrace_setregs(pid_t pid, pt_regs *regs)
{
    if (ptrace(PTRACE_SETREGS, pid, NULL, regs) < 0)
        die(0x20, "ptrace setregs failed");
}

void ptrace_cont(pid_t pid)
{
    if (ptrace(PTRACE_CONT, pid, NULL, NULL) < 0)
        die(0x26, "ptrace cont failed");
}

void ptrace_detach(pid_t pid)
{
    if (ptrace(PTRACE_DETACH, pid, NULL, NULL) < 0)
        die(0x2c, "ptrace detach failed");
}

void poke_text(pid_t pid, uint8_t *addr, void *buf, size_t len)
{
    size_t aligned = (len & ~3u) + 4;
    void *copy = calloc(1, aligned);
    int i;

    if (!copy)
        die(0x77, "poke_text alloc failed");

    memcpy(copy, buf, len);
    for (i = 0; (size_t)i < len; i += 4) {
        if (ptrace(PTRACE_POKETEXT, pid, addr + i, *(long *)((char *)copy + i)) < 0)
            die(0x7f, "poke_text failed");
    }
    free(copy);
}

void peek_text(pid_t pid, size_t addr, void *buf, size_t len)
{
    size_t i;
    long word;

    for (i = 0; i < len; i += 4) {
        word = ptrace(PTRACE_PEEKTEXT, pid, (void *)(addr + i), NULL);
        memcpy((char *)buf + i, &word, 4);
    }
}

/*
 * Call remote function with ARM32 register convention.
 * Ghidra @ 0x9320: r0-r3 for first 4 args, stack for rest, pc = addr.
 */
void ptrace_call(pid_t pid, uint32_t addr, uint32_t *params, uint32_t nparams, pt_regs *regs)
{
    uint32_t i;
    int status;

    for (i = 0; i < nparams && i < 4; i++)
        regs->uregs[i] = params[i];

    if (nparams > 4) {
        regs->uregs[13] -= (nparams - 4) * 4;
        poke_text(pid, (uint8_t *)regs->uregs[13], params + 4, (nparams - 4) * 4);
    }

    regs->uregs[15] = addr;
    if (addr & 1) {
        regs->uregs[15] &= ~1u;
        regs->uregs[16] |= 0x20; /* Thumb */
    } else {
        regs->uregs[16] &= ~0x20u;
    }
    regs->uregs[14] = 0;

    ptrace_setregs(pid, regs);
    ptrace_cont(pid);

    do {
        waitpid(pid, &status, WUNTRACED);
    } while (!WIFSTOPPED(status) || WSTOPSIG(status) != SIGTRAP);
}
