// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <bios.h>

void _start(void) {
    __asm__ volatile("cli\n"
                     "xorw %%ax, %%ax\n"
                     "movw %%ax, %%ds\n"
                     "movw %%ax, %%es\n"
                     "movw $0x1900, %%ax\n"
                     "movw %%ax, %%ss\n"
                     "movw $0x3FFF, %%sp\n"
                     "sti\n"
                     :
                     :
                     : "ax", "memory");

    bios_tt_str_output("Loading system...\n");

    while (1)
        ;
}
