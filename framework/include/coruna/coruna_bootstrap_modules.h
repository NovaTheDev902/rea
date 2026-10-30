/*
 * coruna_bootstrap_modules.h — Bootstrap record module contracts
 *
 * 0x50000: Raw arm64 helper loader (entry4_type0x05.bin)
 * 0xA0000: Anti-forensics cleanup module (entry4_type0x0a.dylib)
 * 0xF0000: TweakLoader (loads embedded __SBTweak)
 *
 * Source: yuzhouheike/iOS-Coruna-Reconstruction (full chain analysis)
 */
#ifndef CORUNA_BOOTSTRAP_MODULES_H
#define CORUNA_BOOTSTRAP_MODULES_H

#include <stdint.h>
#include <stdbool.h>
#include <coruna/coruna_record_contracts.h>

/* ==================== 0x50000 Manual Loader (entry4_type0x05.bin) ==================== */

/*
 * entry4_type0x05.bin is 24,844 bytes of raw arm64 position-independent code.
 * It is NOT a stripped Mach-O and NOT a plain data blob.
 *
 * Structure:
 *   offset 0x0:    tiny init stub that writes 3 internal function pointers
 *                  into a caller-supplied struct:
 *                    ctx + 0x30 = 0x1024  (load external image bytes)
 *                    ctx + 0x38 = 0x3334  (resolve symbol from loaded image)
 *                    ctx + 0x130 = 0x340c (unload/finalize loaded image)
 *   offset 0x24-0x1a8: direct syscall veneers using svc #0x80
 *                      with errno normalization
 *   offset 0x1ac-0x1023: large reserved zero-filled block
 *   offset 0x1024: large loader routine
 *
 * Loader routine (0x1024) behavior:
 *   - Walks backward by page until it finds MH_MAGIC_64 (0xFEEDFACF)
 *   - Accepts FAT magic 0xCAFEBABE / 0xBEBAFECA
 *   - Iterates FAT slices and Mach-O load commands
 *   - Uses helper routines at 0x3334 and 0x340c for symbol resolution
 *
 * Bootstrap contract from live call sites:
 *   - bootstrap copies 0x50000 to rx_base + vm_page_size
 *   - calls entry stub through PAC trampoline
 *   - entry stub writes 3 helper callbacks into bootstrap context
 *   - bootstrap uses those callbacks to load record 0x80000
 */
typedef struct {
    uint64_t load_image;    /* +0x30 in context: load external image bytes */
    uint64_t resolve_sym;   /* +0x38 in context: resolve symbol from loaded image */
    uint64_t unload_image;  /* +0x130 in context: unload/finalize loaded image */
} coruna_loader_50000_callbacks_t;

#define CORUNA_LOADER_50000_SIZE         24844
#define CORUNA_LOADER_50000_INIT_OFFSET  0x0
#define CORUNA_LOADER_50000_SYSCALL_BASE 0x24
#define CORUNA_LOADER_50000_LOAD_ROUTINE 0x1024
#define CORUNA_LOADER_50000_RESOLVE      0x3334
#define CORUNA_LOADER_50000_UNLOAD       0x340c

/* ==================== 0xA0000 Anti-Forensics Cleanup ==================== */

/*
 * entry4_type0x0a.dylib (50,344-158,162 bytes depending on iOS version).
 * Exports _startsc at 0x78f0.
 *
 * _startsc(ctx, session_handle, control_block):
 *   - ctx header word must be 4, version >= 6
 *   - Reads record-count threshold from ctx + 160
 *   - Requires count >> 3 >= 0x44B
 *   - Calls ctx + 128 to set up session
 *
 *   control_block (optional):
 *     byte  +0x0: enable flag. 0 = run cleanup, nonzero = skip
 *     dword +0x4: age threshold in seconds for time-filtered deletion
 *
 *   If session_handle == 0 on entry, calls ctx + 136 and ctx + 144 to release
 *   on exit.
 *
 * Cleanup targets (when enabled, calls setsid() first):
 *
 *   Recursive directory deletion (sub_6F70):
 *     /private/var/mobile/Library/Caches/com.apple.suggestd/WebKit
 *     /private/var/db/diagnostics/Persist
 *     /private/var/db/diagnostics/Signpost
 *     /private/var/db/diagnostics/Special
 *     /private/var/db/analyticsd/aggregates/Daily
 *     /private/var/db/analyticsd/aggregates/90Day
 *     /private/var/db/analyticsd/aggregates/Never
 *
 *   Targeted file deletion by name prefix (sub_72A8):
 *     /private/var/log/com.apple.xpc.launchd/launchd.log
 *     /private/var/db/diagnostics/logdata.statistics
 *     /private/var/mobile/Library/Logs/AppleSupport/general
 *     /private/var/mobile/Library/Logs/CrashReporte_/com.apple.WebKit.WebContent*
 *     /private/var/mobile/Library/Logs/CrashReporte_/ExcUserFault_com.apple.WebKit.WebContent*
 *     /private/var/mobile/Library/Logs/CrashReporte_/JetsamEvent*
 *     /private/var/mobile/Library/Logs/CrashReporte_/com.apple.WebKit.GPU-*
 *
 *   Flat directory age-filtered scan (sub_7658):
 *     /private/var/mobile/Library/Logs/CrashReporte_/
 *
 * Helper functions:
 *   sub_6F70(path, remove_root, age_threshold): recursive tree deletion
 *   sub_72A8(dir, prefix, suffix, age_threshold): prefix-matched file deletion
 *   sub_7658(dir, age_threshold): flat directory scan with age filter
 *   sub_7238(path): single file unlink with chmod 0755
 */
#define CORUNA_CLEANUP_RECORD_THRESHOLD  0x44B

/* ==================== 0xF0000 TweakLoader ==================== */

/*
 * The 0xF0000 record is a Mach-O image (TweakLoader.dylib) that:
 *   1. Validates the Mach-O magic (FAT/thin/64-bit)
 *   2. Resolves _last or _end symbol
 *   3. Extracts embedded __SBTweak Mach-O
 *   4. Patches dyld lib-validation
 *   5. dlopen("/tmp/actual.dylib")
 *   6. Calls next_stage_main
 *
 * sub_21188: validator/loader
 *   - Accepts FAT magic: 0xBEBAFECA, 0xCAFEBABE
 *   - Accepts thin magic: 0xFEEDFACE, 0xFEEDFACF
 *   - Accepts CIGAM (byte-swapped): 0xCEFAEDFE, 0xCFFAEDFE
 *   - Requires size >= 0x21
 *
 * sub_20024: symbol resolution
 *   - resolve _last
 *   - if missing, resolve _end
 *   - if neither exists, loading fails
 *
 * sub_1FE70: helper
 *   - fetches 0xF0000
 *   - obtains task/mapping context
 *   - packages loaded image with task port and mode flags
 */
#define CORUNA_TWEAKLOADER_MIN_SIZE  0x21
#define CORUNA_TWEAKLOADER_TMP_PATH  "/tmp/actual.dylib"

/* ==================== 0x80000 Orchestrator (_start, _startl, _startr) ==================== */

/*
 * The 0x80000 record is the orchestrator dylib (entry0_type0x08).
 * Two size variants: 228,928 bytes (377bed) and 196,864 bytes (e9f89858).
 *
 * Exports: _start, _startl, _startr, _startm
 *
 * _start:
 *   - Patches 7 callback slots in bootstrap context
 *     (ctx + 40, +48, +56, +176, +288, +296, +304)
 *   - Resolves _driver from record 0x90000
 *   - Validates object header (word 0x0002, version >= 2)
 *   - Resolves _startl from record 0x80000
 *   - Calls _startl(ctx, driver_obj)
 *
 * _startl:
 *   - Creates record store session via sub_1C954
 *   - Gets kernel version triple via driver +0x20 method
 *   - Registers 3 string records: 0x70003, 0x70004, 0x70006
 *   - Creates 0x38-byte thread pack
 *   - Spawns sub_71F8 on new pthread (detached unless ctx+1478 forces joinable)
 *
 * Thread pack layout:
 *   +0x00 driver object
 *   +0x08 mode byte (inverted from ctx + 1478)
 *   +0x10 kernel version buffer
 *   +0x18 kernel version buffer size
 *   +0x20 0x70003 string handle
 *   +0x28 0x70004 string handle
 *   +0x30 0x70006 string handle
 *
 * _startr:
 *   - Pulls record 0x70005 from record store
 *   - Requires size >= 0x18, magic 0xDEADD00F
 *   - Uses byte at offset 0x4 as mode flag
 *   - Uses TTL from offset 0x8
 *   - Continues into sub_6BA0 (e9f89858) / sub_8E84 (377bed)
 */

/* ==================== 0x90000 Driver Object ==================== */

/*
 * The 0x90000 record is the main driver dylib (entry1_type0x09).
 * Exports _driver.
 *
 * _driver:
 *   - Allocates 0x50-byte vtable-backed object (header word 0x20002 = version 2.2)
 *   - Installs 8 vtable methods (offsets +0x10 through +0x48)
 *   - _driver(obj) initializes a 0x1D60-byte state object
 *
 * Vtable methods (e9f89858 variant):
 *   +0x10 sub_60B0: destructor/free (zeroes all five 128-bit blocks, then free)
 *   +0x18 sub_60E8: create/init state object via sub_331EC
 *   +0x20 sub_6138: main dispatcher
 *   +0x28 sub_6190: teardown via sub_340FC
 *   +0x30 sub_6174: teardown/release helper
 *   +0x38 sub_61AC: cached status reader (offset +6424)
 *   +0x40 sub_61F0: batch dispatcher
 *   +0x48 sub_6324: kernel version triple - parses xnu-MAJOR.MINOR.PATCH
 *
 * State init sequence (sub_31BA0, ~500 lines):
 *   1. Environment gating (kernel version checks)
 *   2. Anti-analysis (Corellium, sandbox, CPU family)
 *   3. CPU family -> capability flags
 *   4. State inheritance from shared memory (3 version-dependent paths)
 *   5. IOSurface trigger (CVE-2023-41974)
 *   6. Kernel R/W primitives build
 *   7. Privilege escalation (cs_blob, AMFI bypass)
 *   8. Sandbox bypass
 *   9. Rootfs remount
 */
#define CORUNA_DRIVER_OBJECT_SIZE  0x50
#define CORUNA_DRIVER_HEADER       0x20002   /* version 2.2 */
#define CORUNA_STATE_OBJECT_SIZE    0x1D60
#define CORUNA_STATUS_FIELD_OFFSET  6424     /* +0x1918 in state */

/* ==================== 0x90001 Auxiliary Helper Driver ==================== */

/*
 * The 0x90001 record is an auxiliary helper driver (entry5_type0x09).
 * Also exports _driver. Used only in the fallback/helper mapping path
 * inside bootstrap.dylib:sub_5FEC.
 *
 * Interface object from _driver:
 *   +0x10 sub_7714: free outer object
 *   +0x18 sub_7794: create/init session object via sub_3F5E4
 *   +0x20 sub_78B8: destroy/cleanup session object via sub_3FBE4
 *   +0x28 sub_7808: command dispatcher via sub_3F758
 *   +0x30 sub_7868: secondary state operation
 *   +0x38 sub_7908: read cached status at session + 6424
 *   +0x40 sub_7994: batch dispatcher
 *   +0x48 sub_7AFC: kernel version triple
 *
 * Command dispatch in sub_3F758:
 *   13            -> sub_3C034(task_self, 0)        - setup
 *   22            -> same with caller-supplied task port
 *   38            -> sub_3BEC4(task_self)            - version-specific setup
 *   0x40000010    -> sub_2E0B0                       - read
 *   0x4000001B    -> sub_3C354 (gated)                - state setting
 *   0xC000001B    -> sub_3CA24 (gated)                - readback/query
 *
 * The 0x90001 path is the auxiliary helper-driver dispatch, used before
 * the main 0x80000/0x90000 exploit path. It manages task/vm_map/pmap
 * state and publishes the helper region through dyld_all_image_infos.jitInfo.
 */

#endif /* CORUNA_BOOTSTRAP_MODULES_H */
