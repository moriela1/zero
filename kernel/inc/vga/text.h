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

#endif
