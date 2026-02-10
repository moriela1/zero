// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _MEM_FAR_PTR_H
#define _MEM_FAR_PTR_H

#include <types.h>

// Represents the x86 far pointer, which is used to access more
// than 64kb.
struct mem_farptr {
    ushort_t seg;
    ushort_t off;
};

// Gets the value of the far pointer.
//
// Parameters:
// - p: A far pointer.
//
// Returns:
// - None
ubyte_t mem_far_read(struct mem_farptr *p);

// Writes it into far pointer, using raw assembly.
//
// Parameters:
// - p: A far pointer.
//
// Returns:
// - None
void mem_far_write(struct mem_farptr *p, ubyte_t value);

#endif
