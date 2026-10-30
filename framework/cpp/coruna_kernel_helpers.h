/* coruna_kernel_helpers.h - Reversed Coruna kernel helper primitives.
 * Source: Spyware_Research/Framework/kernel/coruna_kernel.c (Ghidra-reversed). */
#ifndef CORUNA_KERNEL_HELPERS_H
#define CORUNA_KERNEL_HELPERS_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

static inline bool coruna_ldrex_pass(void *addr, size_t size) { (void)addr; (void)size; return true; }
static inline bool coruna_ldrexp_clear(void) { return true; }
static inline uint64_t coruna_u64_pack(uint32_t hi, uint32_t lo) { return ((uint64_t)hi << 32) | (uint64_t)lo; }
static inline uint64_t coruna_u64_pack71(uint64_t hi7, uint8_t lo) { return (hi7 << 8) | (uint64_t)lo; }
static inline uint64_t coruna_u64_pack14(uint8_t hi, uint64_t lo) { return ((uint64_t)hi << 32) | (uint32_t)lo; }
static inline uint64_t coruna_cat(uint64_t hi, uint64_t lo) { return (hi << 32) | (uint32_t)lo; }

#endif /* CORUNA_KERNEL_HELPERS_H */