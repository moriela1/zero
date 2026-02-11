// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <types.h>
#include <vga/color.h>
#include <vga/res.h>

volatile ubyte_t *vram = (ubyte_t *)0xB8000;

void
vga_text_draw(ubyte_t row, ubyte_t col, char ch, enum vga_color color) {
    auto offset = (row * VGA_RES_WIDTH + col) * 2;
    vram[offset] = ch;
    vram[offset + 1] = color;
}
