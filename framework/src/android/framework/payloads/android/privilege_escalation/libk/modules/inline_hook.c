/*
 * libk inline hook installer — full algorithm from Ghidra FUN_00014984
 */

#include "strings.h"

#include <dlfcn.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LIBK_LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LIBK_LOG_TAG, __VA_ARGS__)

#define PAGE_ALIGN(x) ((uintptr_t)(x) & ~0xfffu)
#define HOOK_PAGE_SIZE 0xc00

extern void ime_binder_hook_callback(int transaction_code, void *parcel);

/*
 * Ghidra FUN_0001494c @ 0x1494c — transact hook wrapper.
 * IPCThreadState::transact(this, handle, code, data, reply, flags)
 *   param_3 = code, param_4 = Parcel const& (as pointer)
 */
typedef int (*transact_fn)(void *thiz, int handle, unsigned code, void *data,
                           void *reply, unsigned flags);

static transact_fn g_orig_transact;

static int transact_hook(void *thiz, int handle, unsigned code, void *data,
                         void *reply, unsigned flags)
{
    ime_binder_hook_callback((int)code, data);
    if (g_orig_transact)
        return g_orig_transact(thiz, handle, code, data, reply, flags);
    return -1;
}

/* ARM32 branch: LDR pc, [pc, #-4] pattern used in Ghidra trampoline template */
static const uint32_t k_branch_template[2] = { 0xe51ff004, 0x00000000 };

static void clear_cache(void *start, void *end)
{
    __builtin___clear_cache((char *)start, (char *)end);
}

static int inline_hook_install(const char *lib_path, const char *symbol_name,
                               void *hook_fn, void **trampoline_out)
{
    void *handle;
    uint8_t *target;
    uint8_t *patch_site;
    uint8_t saved[8];
    void *trampoline;
    uintptr_t page;
    int rc;

    handle = dlopen(lib_path, RTLD_NOW);
    if (!handle) {
        LOGW("dlopen failed: %s", lib_path);
        return -1;
    }

    target = (uint8_t *)dlsym(handle, symbol_name);
    if (!target) {
        LOGW("dlsym failed: %s", symbol_name);
        return -1;
    }

    /* Ghidra: align target if Thumb (addr % 4 == 1) */
    patch_site = target;
    if (((uintptr_t)target & 1u) == 1)
        patch_site = target - 1;

    page = PAGE_ALIGN(patch_site);
    rc = mprotect((void *)page, HOOK_PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC);
    if (rc != 0)
        return -1;

    memcpy(saved, patch_site, 8);

    trampoline = malloc(16);
    if (!trampoline)
        return -1;

    page = PAGE_ALIGN(trampoline);
    if (mprotect((void *)page, HOOK_PAGE_SIZE, PROT_READ | PROT_WRITE | PROT_EXEC) != 0) {
        free(trampoline);
        return -1;
    }

    /* Trampoline: saved 8 bytes + branch to target+8 */
    memcpy(trampoline, saved, 8);
    ((uint32_t *)trampoline)[2] = k_branch_template[0];
    ((uint32_t *)trampoline)[3] = (uint32_t)(uintptr_t)(patch_site + 8);
    clear_cache(trampoline, (uint8_t *)trampoline + 16);

    /* Patch target: 8-byte branch to hook_fn (template + hook address) */
    ((uint32_t *)patch_site)[0] = k_branch_template[0];
    ((uint32_t *)patch_site)[1] = (uint32_t)(uintptr_t)hook_fn;
    clear_cache(patch_site, patch_site + 8);

    if (trampoline_out)
        *trampoline_out = (uint8_t *)trampoline + 1; /* Ghidra: *param_4 = __dest + 1 (Thumb) */

    LOGI("hook installed at %p -> %p", patch_site, hook_fn);
    return 0;
}

int install_ime_hooks(void)
{
    void *trampoline = NULL;
    int rc;

    rc = inline_hook_install(
        LIBK_HOOK_LIB,
        LIBK_HOOK_SYMBOL,
        (void *)transact_hook,
        &trampoline);

    if (rc < 0) {
        LOGW("install failed: %s", strerror(errno));
        return -1;
    }

    g_orig_transact = (transact_fn)trampoline;
    return 0;
}
