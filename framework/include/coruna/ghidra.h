/*
 * Ghidra decompiler artifact types shared across Coruna dylib rebuilds.
 */
#ifndef CORUNA_GHIDRA_H
#define CORUNA_GHIDRA_H

#include <stdint.h>

typedef struct { uint8_t b[16]; } __ghidra_bytes16;
typedef struct { uint64_t v0; uint64_t v1; } ghidra_pair64;

#endif /* CORUNA_GHIDRA_H */
