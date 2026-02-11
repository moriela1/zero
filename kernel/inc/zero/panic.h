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

[[noreturn]]
void
zero_panic(const char *msg);

#endif
