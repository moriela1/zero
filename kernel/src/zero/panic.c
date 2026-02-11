// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include "vga/res.h"
#include <types.h>
#include <vga.h>

void
zero_panic(const char *msg) {
    vga_text_clear(VGA_WHITE, VGA_RED);

    ubyte_t row = 1;
    ubyte_t col = 1;

    // Draw title
    vga_text_draw_str(row, col + (VGA_RES_WIDTH / 2) - 8, "KERNEL PANIC", VGA_WHITE);

    // Draw message
    row += 2;
    vga_text_draw_str(row, col, msg, VGA_WHITE);

    // Draw more description
    row += 10;
    vga_text_draw_str(
        row,
        col,
        "Try to reload system to prevent issue.\n"
        "If issue persists, write about it in https://github.com/dywoq/zero/issues.\n"
        "\n"
        "- Go to this page.\n"
        "- Click on `New issue`.\n"
        "- There, you can write title and description.\n"
        "- Click on `Create`.\n",
        VGA_WHITE
    );

    row += 10;
    vga_text_draw_str(row, col + (VGA_RES_WIDTH / 2) - 24, "Zero: A protected mode, text mode OS - 2026", VGA_WHITE);

    while (1) {
        __asm volatile("hlt\n");
    }
}
