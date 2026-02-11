// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _ZERO_PANIC_H
#define _ZERO_PANIC_H

#include <types.h>

// Panics, printing a message into the screen and halting.
// The max rows of panic message is 10.
//
// Parameters:
// - msg: A panic message.
[[noreturn]]
void
zero_panic(const char *msg);

#endif
