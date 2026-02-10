// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <bios.h>

[[noreturn]]
void zero_panic(const char *msg) {
    __asm__ volatile("cli\n");                                          // Disable interruptions
    bios_vga_mode_switch(0x03);                                         // Automatically return to text mode
    bios_vga_text_fill_screen(' ', BIOS_VGA_WHITE, BIOS_VGA_LIGHT_RED); // Set foreground and background color

    // Print title
    int width = BIOS_VGA_SCREEN_WIDTH_TEXT - 12;
    for (int i = 0; i < width; i++) {
        bios_tt_output('_');
        if (i == width / 2) {
            bios_tt_str_output("KERNEL PANIC");
            continue;
        }
    }

    // Print message
    bios_tt_str_output("\n");
    bios_tt_str_output(msg);
    bios_tt_str_output("\n\n");

    // Print ending line
    width = BIOS_VGA_SCREEN_WIDTH_TEXT;
    for (int i = 0; i < width; i++) {
        bios_tt_output('_');
    }

    for (;;)
        __asm__ volatile("hlt\n"); // Halt
}
