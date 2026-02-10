// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _VGA_COLOR_H
#define _VGA_COLOR_H

#include <types.h>

// Represents the VGA color, which is used to draw pixels.
enum vga_color : ushort_t {
    VGA_BLACK = 0,
    VGA_DARK_BLUE = 1,
    VGA_DARK_GREEN = 2,
    VGA_DARK_RED = 4,
    VGA_DARK_PINK = 5,
    VGA_DARK_BROWN = 6,
    VGA_GRAY = 7,
    VGA_DARK_GRAY = 8,
    VGA_LIGHT_BLUE = 9,
    VGA_LIGHT_GREEN = 0x0A,
    VGA_LIGHT_RED = 0x0C,
    VGA_LIGHT_PINK = 0x0D,
    VGA_LIGHT_YELLOW = 0x0E,
    VGA_WHITE = 0x0F
};

#endif
