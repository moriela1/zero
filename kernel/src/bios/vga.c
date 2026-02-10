// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <bios.h>
#include <types.h>

void bios_vga_mode_switch(unsigned char mode) {
    __asm__ volatile("movb $0x00, %%ah\n\t"
                     "movb %0, %%al\n\t"
                     "int $0x10"
                     :
                     : "r"(mode)
                     : "ax");
}

void bios_vga_text_fill_screen(byte_t c, enum bios_vga_color fg, enum bios_vga_color bg) {
    ushort_t attr = (bg << 4) | (fg & 0x0F);
    ushort_t cell = ((ushort_t)attr << 8) | (ubyte_t)c;

    for (int i = 0; i < BIOS_VGA_SCREEN_WIDTH_TEXT * BIOS_VGA_SCREEN_HEIGHT_TEXT; i++) {
        ((volatile ushort_t *)0xB8000)[i] = cell;
    }
}
