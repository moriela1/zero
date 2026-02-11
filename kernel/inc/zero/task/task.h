// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _ZERO_TASK_TASK_H
#define _ZERO_TASK_TASK_H

#include <types.h>

// A type alias for task ID.
typedef ushort_t zero_tid;

// A function pointer, which is executed by task manager.
typedef void (*zero_task_ptr)(zero_tid);

// A task state, changed by the task manager every time.
enum zero_task_state : ubyte_t {
    ZERO_TASK_READY,
    ZERO_TASK_DONE,
    ZERO_TASK_BLOCKED,
};

// Represents a task, which can work with others asynchronously.
// It ran only by the task manager, and must be not managed manually.
struct zero_task {
    zero_tid tid;
    zero_task_ptr ptr;
    enum zero_task_state state;
    bool unblock_trigger;
};

#endif
