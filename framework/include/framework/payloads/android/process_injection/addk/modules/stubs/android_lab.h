/* Minimal Android/Linux stubs for native recode syntax checks (not shippable). */
#ifndef CHRYSAOR_NATIVE_STUBS_H
#define CHRYSAOR_NATIVE_STUBS_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <setjmp.h>
#include <sys/types.h>

typedef struct { unsigned long uregs[18]; } pt_regs;

#define PTRACE_ATTACH 16
#define PTRACE_DETACH 17
#define PTRACE_GETREGS 12
#define PTRACE_SETREGS 13
#define PTRACE_POKETEXT 4
#define PTRACE_PEEKTEXT 1

static inline long ptrace(int req, pid_t pid, void *addr, void *data) {
    (void)req; (void)pid; (void)addr; (void)data;
    return 0;
}

#define PROT_READ  1
#define PROT_WRITE 2
#define PROT_EXEC  4
#define MAP_PRIVATE 0x02
#define MAP_ANONYMOUS 0x20
#define MAP_SHARED 1

struct fb_var_screeninfo { uint32_t xres, yres, bits_per_pixel; };
#define FBIOGET_VSCREENINFO 0x4600

#define ANDROID_LOG_INFO 4
#define ANDROID_LOG_WARN 5
static inline int __android_log_print(int prio, const char *tag, const char *fmt, ...) {
    (void)prio; (void)tag; (void)fmt;
    return 0;
}

typedef struct png_struct_def {
    jmp_buf jmpbuf;
} png_struct;
typedef struct png_info_def {
    int dummy;
} png_info;
typedef struct png_struct_def *png_structp;
typedef struct png_info_def *png_infop;
typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef png_byte **png_bytepp;
#define PNG_LIBPNG_VER_STRING "1.6.0"
#define PNG_COLOR_TYPE_RGB 2
#define PNG_INTERLACE_NONE 0
#define PNG_COMPRESSION_TYPE_DEFAULT 0
#define PNG_FILTER_TYPE_DEFAULT 0
#define PNG_TRANSFORM_IDENTITY 0

png_structp png_create_write_struct(const char *, void *, void *, void *);
png_infop png_create_info_struct(png_structp);
void png_destroy_write_struct(png_structp *, png_infop *);
void png_init_io(png_structp, FILE *);
void png_set_IHDR(png_structp, png_infop, unsigned, unsigned, int, int, int, int, int);
void png_set_rows(png_structp, png_infop, png_bytepp);
void png_write_png(png_structp, png_infop, int, void *);
#define png_jmpbuf(png_ptr) ((png_ptr)->jmpbuf)

#endif
