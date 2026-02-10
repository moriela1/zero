// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _BIOS_TELETYPE_H
#define _BIOS_TELETYPE_H

// A thin wrapper around BIOS interruption 0x10,
// which prints a single character into the screen.
//
// Parameters:
// - c: A character to print.
//
// Returns:
// - None
void bios_tt_output(char c);

// Iterates over given immutable string,
// printing every character with bios_tt_output.
//
// If it encounters \n, the function prints \r and \n.
//
// Parameters:
// - str: A string to print.
//
// Returns:
// - None
void bios_tt_str_output(const char *str);

#endif
