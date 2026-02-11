// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _VGA_GM_H
#define _VGA_GM_H

#include <types.h>
#include <vga/color.h>

// Draws a filled rectangle on VGA.
//
// Parameters:
// - x, y: top-left corner of the rectangle
// - width, height: size of the rectangle
// - color: color to fill
//
// Returns:
// - None
void
vga_gm_rect_draw(ushort_t x, ushort_t y, ushort_t width, ushort_t height, enum vga_color color);

#endif
