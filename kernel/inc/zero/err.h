// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _ZERO_ERR_H
#define _ZERO_ERR_H

#include <types.h>

// A error enumeration with codes.
// It's the main way to report failures in functions.
enum zero_err : ushort_t {
    ZERO_ERR_OK = 0,
    ZERO_ERR_TASK_OVERFLOW = 1,
};

#endif
