// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <types.h>
#include <vga/color.h>
#include <vga/pixel.h>

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
vga_gm_rect_draw(ushort_t x, ushort_t y, ushort_t width, ushort_t height, enum vga_color color) {
    for (ushort_t j = 0; j < height; j++) {
        for (ushort_t i = 0; i < width; i++) {
            vga_pixel_draw(x + i, y + j, color);
        }
    }
}
