/*
 * coruna_record_contracts.h — Coruna record ID contracts and container format
 *
 * Source: Cross-referenced from:
 *   - yuzhouheike/iOS-Coruna-Reconstruction (full chain analysis)
 *   - khanhduytran0/coruna ANALYSIS.md (decryption pipeline)
 *   - Our Ghidra decompilation of the 23 dylibs
 *
 * This header documents the stable record ID contracts used by Coruna's
 * native bootstrap to load the post-exploitation modules.
 */
#ifndef CORUNA_RECORD_CONTRACTS_H
#define CORUNA_RECORD_CONTRACTS_H

#include <stdint.h>
#include <stdbool.h>

/* ==================== 0xF00DBEEF Container Format ==================== */

/*
 * The Coruna C2 server serves encrypted payload bundles in a custom
 * container format. Each container has a magic header and a list of
 * records, each identified by a 32-bit record ID.
 */
#define CORUNA_CONTAINER_MAGIC   0xF00DBEEFu  /* big-endian F00DBEEF */
#define CORUNA_PAYLOAD_MAGIC      0x0BEDF00Du  /* compressed payload header */

typedef struct {
    uint32_t magic;          /* 0xF00DBEEF */
    uint32_t total_size;     /* total container size */
    uint16_t entry_count;    /* number of records */
    uint16_t reserved;       /* padding */
    uint8_t  padding[8];     /* alignment */
    /* Followed by entry_count ContainerEntry records */
} coruna_container_header_t;

typedef struct {
    uint32_t record_id;       /* e.g. 0x80000, 0x90000 */
    uint32_t flags;           /* usually 3 in modern sets */
    uint32_t data_offset;     /* offset to data in container */
    uint32_t size;            /* actual byte count */
} coruna_container_entry_t;

/* ==================== Record IDs (16 defined below) ==================== */

/* Stage 1B - Anti-forensics cleanup */
#define CORUNA_RECORD_0x10000   0x10000  /* loaded image (sub_6BA0 path) */
#define CORUNA_RECORD_0x30000   0x30000  /* loaded image (sub_BA2C path) */
#define CORUNA_RECORD_0x40000   0x40000  /* data blob input to _starti */

/* Helper path (bootstrap only) */
#define CORUNA_RECORD_0x50000   0x50000  /* raw arm64 helper loader blob (entry4_type0x05.bin) */

/* String records (URLs/paths) */
#define CORUNA_RECORD_0x70000   0x70000  /* main URL */
#define CORUNA_RECORD_0x70001   0x70001  /* selected path */
#define CORUNA_RECORD_0x70002   0x70002  /* prefix32 sideband */
#define CORUNA_RECORD_0x70003   0x70003  /* C2 config string (driver sel 0x70003) */
#define CORUNA_RECORD_0x70004   0x70004  /* C2 config string (sel 0x70004) */
#define CORUNA_RECORD_0x70005   0x70005  /* TTL config (mode flag, magic 0xDEADD00F) */
#define CORUNA_RECORD_0x70006   0x70006  /* C2 config string (sel 0x70006) */

/* Native dylib records */
#define CORUNA_RECORD_0x80000   0x80000  /* orchestrator dylib (entry0_type0x08) */
#define CORUNA_RECORD_0x90000   0x90000  /* main driver dylib (entry1_type0x09) */
#define CORUNA_RECORD_0x90001   0x90001  /* auxiliary helper driver (entry5_type0x09) */
#define CORUNA_RECORD_0xA0000   0xA0000  /* anti-forensics cleanup dylib (entry4_type0x0a) */
#define CORUNA_RECORD_0xF0000   0xF0000  /* TweakLoader dylib (loads embedded __SBTweak) */

/* ==================== 0x70005 TTL config layout ==================== */

typedef struct {
    uint32_t magic;          /* 0xDEADD00F */
    uint8_t  mode_byte;      /* byte 0x4: boolean mode flag */
    uint8_t  padding[3];
    uint32_t ttl_seconds;    /* 0x15180 (86400) typically */
    uint32_t interval;       /* 0x7d0 (2000) typically */
    uint32_t field_10;       /* =1 */
    uint32_t field_14;       /* =1 */
    uint32_t field_18;       /* =2 */
    uint32_t string_offset;  /* =0x24 */
    uint32_t string_length;  /* =0xc */
    char     trailing[64];   /* e.g. "SpringBoard" */
} coruna_record_0x70005_t;

/* ==================== 0x12345678 Selector Blob ==================== */

#define CORUNA_SELECTOR_MAGIC   0x12345678u

typedef struct {
    uint32_t magic;          /* 0x12345678 */
    uint32_t field_04;       /* observed 3 */
    char     base_path[256]; /* base URL, starts at offset 0x8 */
    uint32_t count;          /* number of selector records */
} coruna_selector_header_t;

typedef struct {
    uint32_t selector_key;    /* OS + platform + arch selector */
    uint8_t  prefix32[32];   /* opaque per-payload sideband */
    char     filename[64];   /* payload filename */
} coruna_selector_record_t;

/* ==================== Shared Buffer Protocol (JS <-> native) ==================== */

/*
 * The JS Stage3_VariantB and native bootstrap.dylib communicate via a
 * shared memory buffer. The protocol uses a 32-bit opcode followed by
 * a variable-length payload.
 */
#define CORUNA_BRIDGE_OP_REQUEST          1   /* native -> JS: fetch by hash */
#define CORUNA_BRIDGE_OP_REQUEST_SECOND   7   /* request with secondary string */
#define CORUNA_BRIDGE_OP_SUCCESS          3   /* JS -> native: success response */
#define CORUNA_BRIDGE_OP_FAILURE          4   /* JS -> native: failure response */

typedef struct {
    volatile uint32_t opcode;   /* see CORUNA_BRIDGE_OP_* */
    uint8_t          bytes[];   /* variable-length payload */
} coruna_bridge_buffer_t;

/* Offset constants (relative to bytes[]) */
#define CORUNA_BRIDGE_OFFSET_SIZE          0x0   /* 32-bit size */
#define CORUNA_BRIDGE_OFFSET_PAYLOAD       0x4   /* payload bytes */
#define CORUNA_BRIDGE_OFFSET_SECONDARY     0x7FFFFC  /* secondary string */
#define CORUNA_BRIDGE_OFFSET_OPCODE        0x0   /* relative to start of buffer */

#endif /* CORUNA_RECORD_CONTRACTS_H */
