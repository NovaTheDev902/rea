/*
 * coruna_gadget_scanner.h — ARM64 gadget scanner for KASLR defeat
 *
 * 31 patterns implemented in src/coruna_gadget_scanner.c (verified Sept
 * 2026 by counting CORUNA_GADGET_PATTERNS): 10 exact-match (all-0xFF mask)
 * + 21 masked (any non-0xFF mask byte, including partial masks like 0xF8).
 * Use coruna_gadget_fixed_count()/coruna_gadget_wildcard_count() rather
 * than hardcoding the split.
 */
#ifndef CORUNA_GADGET_SCANNER_H
#define CORUNA_GADGET_SCANNER_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t       bytes[16];
    uint8_t       mask[16];
    size_t        length;
    const char   *name;
} coruna_gadget_pattern_t;

size_t coruna_gadget_pattern_count(void);
size_t coruna_gadget_fixed_count(void);
size_t coruna_gadget_wildcard_count(void);
bool   coruna_gadget_match(const uint8_t *addr, const coruna_gadget_pattern_t *p);
const uint8_t *coruna_gadget_scan(const uint8_t *base, size_t size,
                                    const coruna_gadget_pattern_t *p);
int    coruna_gadget_scan_all(const uint8_t *base, size_t size,
                                const coruna_gadget_pattern_t **matched,
                                const uint8_t **match_addr);

#endif /* CORUNA_GADGET_SCANNER_H */
