// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _BIOS_VGA_H
#define _BIOS_VGA_H

// A thin wrapper around BIOS interruption 0x10.
// Switches to new given VGA mode.
// 
// Parameters:
// - mode: A new VGA mode.
// 
// Returns:
// - None
void bios_vga_mode_switch(unsigned char mode);

#endif
