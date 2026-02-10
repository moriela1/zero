// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _BIOS_VGA_H
#define _BIOS_VGA_H

#include <types.h>

static constexpr int BIOS_VGA_SCREEN_WIDTH_TEXT = 80;
static constexpr int BIOS_VGA_SCREEN_HEIGHT_TEXT = 25;

// Represents the VGA color, that can be applied to background or foreground.
enum bios_vga_color {
    BIOS_VGA_BLACK = 0,
    BIOS_VGA_BLUE = 1,
    BIOS_VGA_GREEN = 2,
    BIOS_VGA_CYAN = 3,
    BIOS_VGA_RED = 4,
    BIOS_VGA_MAGENTA = 5,
    BIOS_VGA_BROWN = 6,
    BIOS_VGA_LIGHT_GRAY = 7,
    BIOS_VGA_DARK_GRAY = 8,
    BIOS_VGA_LIGHT_BLUE = 9,
    BIOS_VGA_LIGHT_GREEN = 10,
    BIOS_VGA_LIGHT_CYAN = 11,
    BIOS_VGA_LIGHT_RED = 12,
    BIOS_VGA_LIGHT_MAGENTA = 13,
    BIOS_VGA_YELLOW = 14,
    BIOS_VGA_WHITE = 15,
};

// A thin wrapper around BIOS interruption 0x10.
// Switches to new given VGA mode.
//
// Parameters:
// - mode: A new VGA mode.
//
// Returns:
// - None
void bios_vga_mode_switch(unsigned char mode);

// Fills screen with c, setting new foreground and background.
// It works only if current VGA mode is 0x03.
// 
// Parameters:
// - c: A character to fill the screen.
// - fg: A new foreground color.
// - bg: A new background color.
// 
// Returns:
// - None
void bios_vga_text_fill_screen(byte_t c, enum bios_vga_color fg, enum bios_vga_color bg);

#endif
