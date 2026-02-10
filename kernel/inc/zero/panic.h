// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _ZERO_PANIC_H
#define _ZERO_PANIC_H

// Causes a kernel panic, switching to VGA 0x03 mode and disabling interruptions.
// Doesn't return.
// Prints a message into the screen.
//
// Parameters:
// - msg: A message to print.
//
// Returns:
// - None
[[noreturn]] void zero_panic(const char *msg);

#endif
