// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <bios.h>

[[noreturn]]
void panic(const char *msg) {
    __asm__ volatile("cli\n"); // Disable interruptions

    bios_vga_mode_switch(0x03); // Automatically return to text mode

    bios_tt_str_output("\n=============== KERNEL PANIC ===================\n");
    bios_tt_str_output(msg);
    bios_tt_str_output("\n================================================\n");

    for (;;)
        __asm__ volatile("hlt\n"); // Halt
}
