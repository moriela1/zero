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

void
vga_text_draw_str(ubyte_t row, ubyte_t col, const char *str, enum vga_color color) {
    ubyte_t cur_row = row;
    ubyte_t cur_col = col;
    for (const char *p = str; *p != '\0'; ++p) {
        char ch = *p;
        if (ch == '\n') {
            cur_row++;
            cur_col = col;
            continue;
        }
        vga_text_draw(cur_row, cur_col, ch, color);
        cur_col++;
        if (cur_col >= VGA_RES_WIDTH) {
            cur_row++;
            cur_col = col;
        }
    }
}

ubyte_t
vga_color_make(enum vga_color fg, enum vga_color bg) {
    return (bg << 4) | (fg & 0x0F);
}

void
vga_text_clear(enum vga_color fg, enum vga_color bg) {
    ubyte_t attr = vga_color_make(fg, bg);
    for (int i = 0; i < VGA_RES_WIDTH * VGA_RES_HEIGHT; ++i) {
        vram[i*2]     = ' ';  
        vram[i*2 + 1] = attr;
    }
}
