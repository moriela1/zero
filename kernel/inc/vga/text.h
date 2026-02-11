// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _VGA_TEXT_H
#define _VGA_TEXT_H

#include <types.h>
#include <vga/color.h>

// Draws a character to specific row and column, with given color.
//
// Parameters:
// - row, col: A character position.
// - ch: Given character.
// - color: Given color.
//
// Returns:
// - None
//
// Parameters:
// - None
void
vga_text_draw(ubyte_t row, ubyte_t col, char ch, enum vga_color color);

// Draws a immutable string to specific row and column, with given color.
//
// Parameters:
// - row, col: A character position.
// - str: Given string.
// - color: Given color.
//
// Returns:
// - None
//
// Parameters:
// - None
void
vga_text_draw_str(ubyte_t row, ubyte_t col, const char *str, enum vga_color color);

// Returns a combined color with foreground and background.
//
// Parameters:
// - fg: A foreground color.
// - bg: A background color.
ubyte_t
vga_color_make(enum vga_color fg, enum vga_color bg);

// Cleans the whole screen with foreground and background color.
//
// Parameters:
// - fg: A foreground color.
// - bg: A background color.
void
vga_text_clear(enum vga_color fg, enum vga_color bg);

#endif
