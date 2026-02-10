// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

void bios_tt_output(char c) {
    __asm volatile("movb %0, %%al\n\t"
                   "movb $0x0E, %%ah\n\t"
                   "int $0x10"
                   :
                   : "r"(c)
                   : "ax");
}
