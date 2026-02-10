// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <types.h>
#include <vga.h>

#define VGA_MEM_ ((volatile ubyte_t *)0xA0000)

void
vga_pixel_draw(ushort_t x, ushort_t y, enum vga_color color) {
    VGA_MEM_[y * VGA_RES_WIDTH + x] = color;
}
