// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <vga.h>
#include <vga/color.h>

[[noreturn, gnu::section(".kernel_init")]] void
_start();

void
_start() {
    while (1)
        ;
}
