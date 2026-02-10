// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <mem/far_ptr.h>
#include <types.h>

ubyte_t mem_far_read(struct mem_farptr *p) {
    ubyte_t val;
    __asm__ volatile("push %%es\n\t"
                     "movw %1, %%ax\n\t"        // load segment into ax
                     "movw %%ax, %%es\n\t"      // set ES
                     "movw %2, %%di\n\t"        // load offset into di
                     "movb %%es:(%%di), %0\n\t" // read byte from far pointer
                     "pop %%es\n\t"
                     : "=r"(val)
                     : "r"(p->seg), "r"(p->off)
                     : "ax", "di", "memory");
    return val;
}

void mem_far_write(struct mem_farptr *p, ubyte_t value) {
    __asm__ volatile("push %%es\n\t"
                     "movw %0, %%ax\n\t"        // load segment into ax
                     "movw %%ax, %%es\n\t"      // set ES
                     "movw %1, %%di\n\t"        // load offset into di
                     "movb %2, %%es:(%%di)\n\t" // write byte to far pointer
                     "pop %%es\n\t"
                     :
                     : "r"(p->seg), "r"(p->off), "r"(value)
                     : "ax", "di", "memory");
}
