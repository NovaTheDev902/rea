/*
 * Ghidra decompiler types — verbatim reversal layer.
 * Do not substitute uint32_t/uint64_t here; names must match Ghidra output.
 */
#ifndef CORUNA_GHIDRA_VERBATIM_H
#define CORUNA_GHIDRA_VERBATIM_H

#include <stdint.h>

typedef unsigned char      undefined;
typedef unsigned char      undefined1;
typedef unsigned char      undefined2;
typedef unsigned char      undefined3;
typedef unsigned int       undefined4;
typedef unsigned int       undefined5;
typedef unsigned long long undefined6;
typedef unsigned long long undefined7;
typedef unsigned long long undefined8;
typedef unsigned long long undefined9;
typedef unsigned long long undefined10;
typedef unsigned long long undefined11;
typedef unsigned long long undefined12;
typedef unsigned long long undefined13;
typedef unsigned long long undefined14;
typedef unsigned long long undefined15;
typedef unsigned long long undefined16;
typedef unsigned char      byte;
typedef unsigned int       uint;
typedef unsigned long      ulong;
typedef void               code;
typedef unsigned long long qword;
typedef unsigned long long memory_object_size_t;
typedef unsigned int       task_suspension_token_t;
typedef unsigned long long vm_address_t;
typedef unsigned long long pthread_t;
typedef void              *pthread_attr_t;

struct __darwin_pthread_handler_rec {
    void *__routine;
    void *__arg;
    struct __darwin_pthread_handler_rec *__next;
};

typedef struct { uint8_t b[16]; } __ghidra_bytes16;

#endif /* CORUNA_GHIDRA_VERBATIM_H */
