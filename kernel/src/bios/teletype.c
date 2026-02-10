// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

void bios_tt_output(char c) {
    __asm__ volatile("movb %0, %%al\n\t"
                     "movb $0x0E, %%ah\n\t"
                     "int $0x10"
                     :
                     : "r"(c)
                     : "ax");
}

void bios_tt_str_output(const char *str) {
    for (const char *p = str; *p != '\0'; ++p) {
        char c = *p;
        if (c == '\n') {
            bios_tt_output('\r');
            bios_tt_output('\n');
            continue;
        }
        bios_tt_output(c);
    }
}
