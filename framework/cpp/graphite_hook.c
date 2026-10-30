// graphite_hook.c - Inline Hooking (C)
// Adapted from Pegasus (libk) reverse-engineered native code

#include "graphite_hook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <sys/mman.h>
#include <unistd.h>
#include <dlfcn.h>
#include <android/log.h>
#endif

// ARM32 branch template: LDR pc, [pc, #-4]
static const uint32_t k_branch_template[2] = { 0xe51ff004, 0x00000000 };

HOOK_EXPORT void clear_instruction_cache(void *start, void *end) {
#ifndef _WIN32
    __builtin___clear_cache((char *)start, (char *)end);
#endif
}

HOOK_EXPORT int inline_hook_install(void *target, void *hook, void **trampoline) {
    if (!target || !hook) return -1;

#ifdef __arm__
    // ARM32 inline hook
    // 1. Save original instructions
    // 2. Write trampoline (LDR pc, [pc, #-4])
    // 3. Write hook address
    // 4. Clear cache
    uint32_t *patch_site = (uint32_t *)target;
    uint32_t saved[2];
    saved[0] = patch_site[0];
    saved[1] = patch_site[1];

    // Write branch template
    patch_site[0] = k_branch_template[0];
    patch_site[1] = (uint32_t)(uintptr_t)hook;

    clear_instruction_cache(patch_site, patch_site + 2);
    return 0;
#else
    // x86/x64: use 5-byte relative jump
    // 0xE9 offset (relative jump)
    unsigned char *patch = (unsigned char *)target;
    long offset = (long)hook - (long)(target) - 5;
    patch[0] = 0xE9;
    patch[1] = (unsigned char)(offset & 0xFF);
    patch[2] = (unsigned char)((offset >> 8) & 0xFF);
    patch[3] = (unsigned char)((offset >> 16) & 0xFF);
    patch[4] = (unsigned char)((offset >> 24) & 0xFF);
    return 0;
#endif
}

HOOK_EXPORT int ptrace_attach(int pid) {
#ifndef _WIN32
    // In real implementation: ptrace(PTRACE_ATTACH, pid, NULL, NULL)
    (void)pid;
    return 0;
#else
    (void)pid;
    return 0;
#endif
}

HOOK_EXPORT int ptrace_detach(int pid) {
#ifndef _WIN32
    (void)pid;
    return 0;
#else
    (void)pid;
    return 0;
#endif
}

HOOK_EXPORT void* resolve_symbol(const char *lib_path, const char *symbol_name) {
    // In real implementation: dlopen + dlsym
    (void)lib_path; (void)symbol_name;
    return NULL;
}
