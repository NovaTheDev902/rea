/*
 * libk bootstrap — DSO entry called by addk after inject
 * Ghidra: init @ 0x14c78
 */

#include <android/log.h>

#define LOG_TAG "libk"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

static int hooks_installed;

extern int install_ime_hooks(void); /* FUN_00014c44 → inline_hook.c */

/*
 * Exported symbol — addk passes "init" as argv[3]; dlsym resolves this.
 */
int init(void *unused)
{
    (void)unused;

    LOGI("libk init");

    if (hooks_installed) {
        LOGI("hooks already installed");
        return 0;
    }

    hooks_installed = 1;
    LOGI("installing IME hooks");

    if (install_ime_hooks() < 0) {
        LOGI("hook install failed");
        return -1;
    }

    LOGI("hooks installed");
    return 0;
}
