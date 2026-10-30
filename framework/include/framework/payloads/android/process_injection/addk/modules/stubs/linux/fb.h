#ifndef LINUX_FB_H_STUB
#define LINUX_FB_H_STUB

#include <stdint.h>

struct fb_var_screeninfo {
    uint32_t xres;
    uint32_t yres;
    uint32_t bits_per_pixel;
};

#define FBIOGET_VSCREENINFO 0x4600

#endif
