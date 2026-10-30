// graphite_hook.h - Inline Hooking (C)
// Adapted from Pegasus (libk) reverse-engineered native code
// Features: ARM32 inline hook, trampoline, cache clearing

#ifndef GRAPHITE_HOOK_H
#define GRAPHITE_HOOK_H

#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
    #define HOOK_EXPORT __declspec(dllexport)
#else
    #define HOOK_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Inline hook installation
HOOK_EXPORT int inline_hook_install(void *target, void *hook, void **trampoline);

// Cache clearing
HOOK_EXPORT void clear_instruction_cache(void *start, void *end);

// Process injection helpers
HOOK_EXPORT int ptrace_attach(int pid);
HOOK_EXPORT int ptrace_detach(int pid);

// ELF symbol resolution
HOOK_EXPORT void* resolve_symbol(const char *lib_path, const char *symbol_name);

#ifdef __cplusplus
}
#endif

#endif
