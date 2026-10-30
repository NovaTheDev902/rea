/*
 * coruna_types.h — recovered layout types for Coruna native rebuild.
 *
 * Offsets verified by cross-referencing entry0_type0x8_implant.dylib Ghidra
 * extract (_start / _startl / FUN_000107ec / FUN_00010178) and
 * analyze_ctx_offsets.py frequency scan (90 unique byte offsets, max 0x5f0).
 */
#ifndef CORUNA_TYPES_H
#define CORUNA_TYPES_H

#include <stdint.h>
#include <stddef.h>

#define CORUNA_IMPLANT_CTX_SIZE 0x648u

#define CORUNA_ERR_BASE       0xad000u
#define CORUNA_ERR_INVALID    (CORUNA_ERR_BASE | 0x01u)
#define CORUNA_ERR_NOMEM      (CORUNA_ERR_BASE | 0x09u)
#define CORUNA_ERR_NOTSUP     (CORUNA_ERR_BASE | 0x0au)
#define CORUNA_ERR_THREAD     (CORUNA_ERR_BASE | 0x0bu)
#define CORUNA_ERR_IO         (CORUNA_ERR_BASE | 0x11u)
#define CORUNA_ERR_BAD_MAGIC  (CORUNA_ERR_BASE | 0x14u)

struct coruna_implant_ctx;

typedef void (*coruna_host_callback_fn)(struct coruna_implant_ctx *ctx,
                                        int code, int value, int tag);

typedef int64_t (*coruna_bump_consume_fn)(struct coruna_implant_ctx *ctx, uint64_t size);
typedef void (*coruna_icache_flush_fn)(struct coruna_implant_ctx *ctx,
                                       int64_t addr, uint32_t size);
typedef uint64_t (*coruna_bzero_hook_fn)(uint64_t ctx, void *buf, size_t len);
typedef uint64_t (*coruna_kern_alloc_fn)(struct coruna_implant_ctx *ctx, uint32_t size);

/*
 * Implant host context — 0x648 bytes passed into _start / _startl.
 *
 * Layout groups:
 *   0x000–0x020  host-provided opaque slots (restored after hook pass)
 *   0x028–0x038  implant hook installs (cmd dispatch + kernel I/O)
 *   0x048–0x138  kernel staging buffer + hook table tail
 *   0x078–0x0a8  C2 config path strings (server / port / interval)
 *   0x5c0–0x5f0  boot flags + host logging callback
 */
typedef struct coruna_implant_ctx {
    /* ---- Host vtable head (saved across temporary hook install) ---- */
    uint64_t            host_slot_0;           /* 0x000 */
    uint64_t            host_slot_1;           /* 0x008 */
    uint64_t            host_slot_2;           /* 0x010 */
    uint64_t            host_slot_3;           /* 0x018 */
    uint64_t            host_slot_4;           /* 0x020 */

    /* ---- Temporary hook table (_start installs when !func_table_installed) */
    coruna_bump_consume_fn  hook_bump_consume; /* 0x028  FUN_00010218 */
    void                   *hook_cmd_dispatch; /* 0x030  FUN_0000a38c */
    void                   *hook_kernel_sym;   /* 0x038  FUN_0000c6f0 */

    uint8_t             pad_040[0x48 - 0x40];

    /* Kernel blob cursor (FUN_00010218 / FUN_00010178 / FUN_000100e8) */
    void               *kbuf_cursor;           /* 0x048 */
    uint32_t            kbuf_remain;           /* 0x050 */
    uint8_t             pad_054[0x58 - 0x54];

    uint64_t            kern_slot_58;          /* 0x058 */
    uint64_t            kern_slot_60;          /* 0x060 */
    uint64_t            kern_slot_68;          /* 0x068 */
    uint8_t             pad_070[0x78 - 0x70];

    /* C2 configuration keys (FUN_000107ec / _startl FUN_0000863c) */
    char               *config_server;         /* 0x078 */
    uint64_t            kern_slot_80;          /* 0x080 */
    uint64_t            kern_slot_88;          /* 0x088  buffer base */
    uint64_t            kern_slot_90;          /* 0x090  buffer size field */
    uint64_t            kern_slot_98;          /* 0x098 */

    char               *config_port;           /* 0x0a0 */
    char               *config_interval;       /* 0x0a8 */

    coruna_bzero_hook_fn    hook_bzero;        /* 0x0b0  FUN_00010248 */
    uint8_t             pad_0b8[0xc0 - 0xb8];
    uint64_t            host_slot_c0;          /* 0x0c0 */
    uint32_t            host_u32_c4;           /* 0x0c4 */
    uint8_t             pad_0c8[0xe8 - 0xc8];

    /* Saved host tail + implant hooks (restored in _start epilogue) */
    uint64_t            host_slot_e8;          /* 0x0e8  idx 0x1d */
    uint64_t            host_slot_f0;          /* 0x0f0  idx 0x1e */
    uint64_t            host_slot_f8;          /* 0x0f8  idx 0x1f */
    uint64_t            host_slot_100;         /* 0x100  idx 0x20 */
    uint64_t            host_slot_108;         /* 0x108  idx 0x21 */
    uint64_t            host_slot_110;         /* 0x110  idx 0x22 */
    uint64_t            host_slot_118;         /* 0x118  idx 0x23 */
    coruna_icache_flush_fn  hook_icache_flush; /* 0x120  FUN_000100e8 */
    coruna_kern_alloc_fn    hook_kern_alloc;   /* 0x128  FUN_00010178 */
    void                   *hook_kernel_aux;   /* 0x130  FUN_0000c8b0 */
    uint32_t           *kbuf_cas_lock;         /* 0x138 */

    /* Runtime / IPC / dyld state (FUN_00019c8c, FUN_0001a078, FUN_0000a38c) */
    void               *chain_head;            /* 0x140  intrusive list */
    void               *ipc_state;             /* 0x148  +0x20 int block */
    uint64_t            runtime_150;           /* 0x150 */
    uint64_t            runtime_158;           /* 0x158 */
    uint64_t            runtime_160;           /* 0x160 */
    uint64_t            image_slide;           /* 0x168  ASLR slide delta */
    void               *task_info;             /* 0x170  +0x10 count */
    uint64_t            runtime_178;           /* 0x178 */
    uint64_t            runtime_180;           /* 0x180 */
    void               *dylib_info;            /* 0x188  loader metadata */
    uint64_t            runtime_190;           /* 0x190 */
    void               *bundle_cfg;            /* 0x198  +8/+0xc fields */
    uint64_t            runtime_1a0;           /* 0x1a0 */
    void               *range_table;           /* 0x1a8  0x10-byte entries */
    void               *module_hdr;            /* 0x1b0  +0x38 size */
    void               *name_index;            /* 0x1b8 */
    uint16_t            state_flags;           /* 0x1c0  bits 7/8 used */
    uint8_t             bypass_flag;           /* 0x1c2 */
    uint8_t             slot_1c3;              /* 0x1c3 */
    uint8_t             pad_1c4[0x5c0 - 0x1c4];

    /* ---- Boot / listener flags (_start, _startl, FUN_000107ec) ---- */
    uint8_t             loader_copy_flag;      /* 0x5c0 */
    uint8_t             dual_boot_flag;        /* 0x5c1 */
    uint8_t             func_table_installed;  /* 0x5c2 */
    uint8_t             pad_5c3;               /* 0x5c3 */
    uint8_t             exploit_loaded;        /* 0x5c4  0 = first-load path */
    uint8_t             slot_a38c_flag;        /* 0x5c5 */
    uint8_t             async_join;            /* 0x5c6  join listener thread */
    uint8_t             slot_d450_flag;        /* 0x5c7 */
    uint8_t             pad_5c8[0x5d0 - 0x5c8];

    uint64_t            runtime_5d0;           /* 0x5d0 */
    uint64_t            runtime_5d8;           /* 0x5d8 */

    uint32_t           *status_out;            /* 0x5e0  param_1[0xbc]; *status_out = 5 */
    uint8_t             pad_5e4[0x5eb - 0x5e4];

    uint8_t             host_log_enabled;      /* 0x5eb */
    uint8_t             conn_active;           /* 0x5ec */
    uint8_t             pad_5ed[0x5f0 - 0x5ed];

    coruna_host_callback_fn host_callback;     /* 0x5f0  param_1[0xbe] */

    uint8_t             tail_5f8[CORUNA_IMPLANT_CTX_SIZE - 0x5f8];
} coruna_implant_ctx_t;

/* Layout checks (Darwin build): sizeof == 0x648; hook_bump @ 0x28; host_callback @ 0x5f0 */

typedef struct coruna_driver_params {
    int16_t             kind;       /* must be 2 for kernel driver */
    int16_t             version;    /* must be >= 2 */
    uint8_t             pad[0x38 - 4];
} coruna_driver_params_t;

/* Persist dylib singleton state (_end in entry2_type0xf_persist.dylib). */
typedef struct coruna_persist_state {
    uint64_t            vsyslog_fn;            /* 0x00  dlsym vsyslog */
    uint8_t             pad_08[0x58 - 0x08];
    uint64_t            runtime_58;            /* 0x58 */
    uint8_t             tail[0x200 - 0x60];  /* grows with more recovery */
} coruna_persist_state_t;

static void coruna_host_log(coruna_implant_ctx_t *ctx,
                            int code, int value, int tag)
{
    if (ctx && ctx->host_log_enabled && ctx->host_callback)
        ctx->host_callback(ctx, code, value, tag);
}

#endif /* CORUNA_TYPES_H */
