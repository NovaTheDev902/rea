// graphite_inject.h - Process Injection (C)
// Adapted from Pegasus (addk) reverse-engineered native code
// Features: ptrace-based process injection, remote mmap, ELF loading

#ifndef GRAPHITE_INJECT_H
#define GRAPHITE_INJECT_H

#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
    #define INJECT_EXPORT __declspec(dllexport)
#else
    #define INJECT_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Process injection
INJECT_EXPORT int inject_process(int pid, const char *library_path,
                                const char *function_name, void *param,
                                size_t param_size);

// Remote module address resolution
INJECT_EXPORT void* get_library_addr(int pid, const char *module_name);
INJECT_EXPORT void* get_remote_module_addr(int pid, const char *module_name,
                                          void *local_symbol);

// ELF patching
INJECT_EXPORT int elf_patch_reloc(const char *lib_path, void *loaded_base,
                                  unsigned sym_index, void *hook_addr,
                                  void **original_out);

// File staging
INJECT_EXPORT int stage_payload(const void *buf, size_t len, const char *path);
INJECT_EXPORT int file_exists(const char *path, int *out_exists);

#ifdef __cplusplus
}
#endif

#endif
