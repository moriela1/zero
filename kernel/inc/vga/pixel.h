// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _VGA_PIXEL_H
#define _VGA_PIXEL_H

#include <types.h>
#include <vga/color.h>

// Draws a pixel directly to VGA memory, using:
//      VGA[y * VGA_RES_WIDTH + x] = color;
//
// Parameters:
// - x: A X position.
// - y: A Y position.
// - color: Given color.
//
// Returns:
// - None
void
vga_pixel_draw(ushort_t x, ushort_t y, enum vga_color color);

#endif
