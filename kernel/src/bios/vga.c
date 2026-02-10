// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

void bios_vga_mode_switch(unsigned char mode) {
    __asm__ volatile("movb $0x00, %%ah\n\t"
                     "movb %0, %%al\n\t"
                     "int $0x10"
                     :
                     : "r"(mode)
                     : "ax");
}
