/*
 * Coruna Kernel Exploit — _driver Function
 *
 * Based on the NadSec/Rat5ak pre-reversed analysis of dump.bin (CVE-2023-41974).
 * This header documents the 6-phase exploitation sequence of the _driver
 * function (29,972 bytes / 7,493 ARM64 instructions) reconstructed from
 * the public analysis.
 *
 * Source: dump.bin (matteyeux memory capture, iPhone X / iOS 16.6)
 *   SHA-256: 3b52e3b489948ae491a44faf24a9634e4c959408b321b9c36c367324874a05dc
 * Analysis: github.com/Rat5ak/CORUNA_TECHNICAL_ANALYSIS (NadSec)
 *
 * Our equivalent: coruna_kernel_79e8.c (entry1_type0x9_kernel.dylib, 333KB, 648 funcs)
 *
 * The 6-phase sequence reconstructed from the pre-reversed analysis:
 */
#ifndef CORUNA_DRIVER_H
#define CORUNA_DRIVER_H

#include <stdint.h>
#include <stdbool.h>

/* ==================== PHASE 1: Environment Fingerprinting ==================== */

/*
 * Before triggering anything, the exploit checks for analysis environments:
 *   - /usr/libexec/corelliumd (Corellium virtual device)
 *   - "developer_mode_status" sysctl
 *   - Kernel version parsing (xnu-%d.%d.%d~%d pattern)
 *   - SoC identification (T8020=A12, T8120=A16) for offset table selection
 * If on an analysis environment, the exploit exits.
 */
typedef struct {
    char     hw_model[64];          /* "iPhone10,3" etc. */
    char     kernel_version[64];    /* "xnu-7195.50.7~1" etc. */
    uint32_t soc_type;             /* 0x8020=A12, 0x8120=A16 */
    bool     is_corellium;         /* anti-Corellium check */
    bool     is_developer_mode;    /* developer mode check */
    bool     safe_to_proceed;       /* result of all checks */
} coruna_env_t;

/* ==================== PHASE 2: IOSurface Trigger ==================== */

/*
 * Trigger CVE-2023-41974 (IOSurfaceRoot use-after-free):
 *   1. dlopen(IOSurface.framework)
 *   2. IOServiceMatching("IOSurfaceRoot")
 *   3. IOServiceOpen -> get connection
 *   4. Create surface with kIOSurfaceIsGlobal/Width/Height
 *   5. IOConnectCallMethod / IOConnectTrap6 -> trigger vulnerability
 *
 * Heap shaping: surface dimensions control kernel allocation size.
 */
typedef struct {
    uint32_t surface_id;
    uint32_t width;
    uint32_t height;
    uint32_t is_global;            /* kIOSurfaceIsGlobal */
    void    *iosurface_handle;     /* dlopen handle */
    int      connection;           /* IOServiceOpen connection */
} coruna_iosurface_t;

/* ==================== PHASE 3: Kernel R/W Primitives ==================== */

/*
 * After triggering the IOSurface vulnerability, build kernel read/write:
 *   - mach_vm_read_overwrite -> kernel read
 *   - mach_vm_write -> kernel write
 *   - ARM64 gadget scanner (20 fixed + 20 wildcard byte patterns)
 *   - Defeat KASLR via info leak
 */
typedef struct {
    uint64_t (*read)(uint64_t addr, void *buf, size_t len);
    int      (*write)(uint64_t addr, const void *buf, size_t len);
    bool     (*gadget_scan)(const uint8_t *pattern, size_t len,
                             const uint8_t *mask);
} coruna_kernel_rw_t;

/* ==================== PHASE 4: Privilege Escalation ==================== */

/*
 * With kernel R/W established, escalate privileges:
 *   - task_get_special_port / task_set_special_port
 *   - host_security_set_task_token (highly privileged)
 *   - Forge entitlements via cs_blob manipulation
 *   - IOServiceSetAuthorizationID -> impersonate entitlements
 *   - Inject task_for_pid-allow (ultimate privilege entitlement)
 */
typedef struct {
    uint32_t host_priv_port;
    uint32_t task_special_port;
    uint64_t original_cs_blob;
    uint64_t forged_cs_blob;
    bool     has_task_for_pid;
} coruna_priv_esc_t;

/* ==================== PHASE 5: Sandbox & AMFI Bypass ==================== */

/*
 * Bypass sandbox and AMFI:
 *   - sandbox_check with SANDBOX_CHECK_NO_REPORT
 *   - Patch AMFI (AppleMobileFileIntegrity) in kernel memory
 *   - Inject task_for_pid-allow entitlement
 *
 * References to:
 *   - com.apple.security.sandbox
 *   - com.apple.driver.AppleMobileFileIntegrity (AMFI)
 */
typedef struct {
    bool     sandbox_bypassed;
    bool     amfi_patched;
    bool     has_task_for_pid_allow;
} coruna_sandbox_bypass_t;

/* ==================== PHASE 6: Root Filesystem Remount ==================== */

/*
 * Complete rootfs remount chain:
 *   1. Identify root partition: /dev/disk0s1s1
 *   2. Manipulate APFS root snapshot: <snapshot>-fs
 *   3. Mount writable copy at OTA path: /private/var/MobileSoftware/mnt1
 *   4. Create RAM disks for temporary storage
 *   5. posix_spawn of system tools: mount_apfs, newfs_hfs
 *   6. Remount root filesystem read-write
 */
typedef struct {
    char     root_partition[64];   /* "/dev/disk0s1s1" */
    char     snapshot_name[64];    /* APFS snapshot */
    char     ota_mount[128];       /* "/private/var/MobileSoftware/mnt1" */
    bool     rootfs_writable;
    bool     apfs_snapshot_manipulated;
} coruna_rootfs_t;

/* ==================== ARM64 Gadget Scanner ==================== */

/*
 * The exploit scans kernel memory for 39 ARM64 instruction patterns
 * (20 fixed-byte + 19 wildcard) to defeat KASLR and locate critical
 * kernel structures without symbols.
 *
 * Fixed-byte patterns: exact byte sequences
 * Wildcard patterns: byte sequences with wildcard bytes
 *
 * Examples of patterns used (from NadSec analysis):
 *   - LDP X29, X30, [SP, #offset]  (function prologues)
 *   - RET instruction sequences
 *   - PACIBSP / PACIASP (PAC auth)
 *   - BLR X9 (indirect calls)
 *   - Various control flow patterns
 */
typedef struct {
    uint8_t bytes[16];    /* up to 16 bytes */
    uint8_t mask[16];     /* 0xFF = match, 0x00 = wildcard */
    size_t   length;
    const char *name;
} coruna_gadget_pattern_t;

/* Top 10 functions by size (from NadSec analysis):
 *   1. _driver         at 0x7514    29,972 bytes  - main exploit orchestrator
 *   2. (unranked)      at 0x1E2AC   11,340 bytes  - IOSurface/heap manipulation
 *   3. (unranked)      at 0x15794   10,656 bytes  - kernel R/W setup
 *   4. (unranked)      at 0x37764    7,868 bytes  - helper
 *   ... 9 functions exceed 2KB
 *   ... 587 of 649 functions in __text (remaining 62 in stubs/__DATA)
 *
 * Function size stats:
 *   Smallest:           4 bytes
 *   Largest:        29,972 bytes
 *   Average:          412 bytes
 *   Median:           180 bytes
 */

/* ==================== Import Categorization ==================== */

/*
 * 265 imports categorized by subsystem (from NadSec analysis):
 *   Mach/VM:           82 (kernel memory, ports, threads)
 *   CoreFoundation:    41 (dictionary, data, string for IOKit)
 *   IOKit/Kernel:      30 (driver interaction, IOSurface, IOConnect)
 *   FileSystem:        30 (mount/unmount, file I/O, dlopen/dlsym)
 *   String/Data:       18 (memcpy, strcmp, snprintf)
 *   Process/Thread:    12 (posix_spawn, getpid, seteuid)
 *   Network:            3 (socket, connect, setsockopt)
 *   Other:             30 (sandbox, processor info, NECP, misc)
 *   TOTAL:            265
 */

/* ==================== Segment Map ==================== */

/*
 * Memory layout (from NadSec analysis):
 *   __TEXT.__text       0x7514     237,176 bytes  (587 of 649 functions)
 *   __TEXT.__stubs      0x4138C      2,928 bytes  (244 x 12 lazy stubs)
 *   __TEXT.__cstring    0x41EFC      3,460 bytes  (153 strings)
 *   __TEXT.__const      0x42C80      2,892 bytes  (read-only constants)
 *   __TEXT.__unwind_info  ...        ...          (ARM64 unwind)
 *   __DATA_CONST        ...          ...          (GOT, CFString)
 *   __DATA.__la_symbol_ptr  ...      ...          (lazy binding)
 *   __DATA.__got        ...          ...          (264 entries)
 *   __DATA.__auth_got   ...          ...          (PAC-authenticated)
 *   __DATA.__data       ...          ...          (initialized data)
 *   __LINKEDIT          ...          ...          (symbol table, etc.)
 */

/* ==================== Public API ==================== */

typedef struct {
    /* Phase 1 */
    int  (*env_check)(coruna_env_t *env);
    /* Phase 2 */
    int  (*iosurface_trigger)(const coruna_env_t *env, coruna_iosurface_t *io);
    /* Phase 3 */
    int  (*kernel_rw_init)(const coruna_env_t *env, coruna_kernel_rw_t *rw);
    int  (*gadget_scan)(const coruna_kernel_rw_t *rw, uint64_t *result);
    /* Phase 4 */
    int  (*priv_esc)(const coruna_kernel_rw_t *rw, coruna_priv_esc_t *priv);
    /* Phase 5 */
    int  (*sandbox_amfi_bypass)(const coruna_kernel_rw_t *rw,
                                  coruna_sandbox_bypass_t *bypass);
    /* Phase 6 */
    int  (*rootfs_remount)(const coruna_kernel_rw_t *rw,
                            coruna_rootfs_t *rootfs);
} coruna_driver_ops_t;

extern const coruna_driver_ops_t *coruna_driver_get_ops(void);

#endif /* CORUNA_DRIVER_H */
