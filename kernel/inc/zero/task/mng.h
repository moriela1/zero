// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#ifndef _ZERO_TASK_MNG_H
#define _ZERO_TASK_MNG_H

#include <types.h>
#include <zero/err.h>
#include <zero/task/task.h>

#define ZERO_TASK_MNG_MAX 128

// Pushes a new task to the underlying task.
//
// Parameters:
// - ptr: A function pointer.
// - unblock_trigger: A task trigger, which is the only flag
//   the task manager relies on to unblock task.
//
// Returns:
// - A possible error (ZERO_ERR_OK or non-zero one).
//
// Errors:
// - ZERO_ERR_TASK_OVERFLOW: If the stack reached ZERO_TASK_MNG_MAX.
enum zero_err
zero_task_mng_add(zero_task_ptr ptr, bool unblock_trigger);

// Iterates over a tasks stack and runs them.
//
// When the task is ran, the task manager pushes/pops flags and general-purpose registers
// before/after running the function pointer.
//
// Switches to the next task if task yielded or blocked.
//
// If the current task is blocked but its trigger is true, the function marks it as ready,
// and runs it.
//
// Parameters: None
//
// Returns: None
void
zero_task_mng_loop();

// Marks the current task as READY, telling the task manager to run other task.
//
// WARNING: Your function pointer must return after this call,
// because the task manager can't know whether you call `zero_task_mng_yield` or not
// until you return.
//
// Parameters: None
//
// Returns: None
void
zero_task_mng_yield();

// Blocks the current task, switching to the next one.
//
// WARNING: Your function pointer must return after this call,
// because the task manager can't know whether you call `zero_task_mng_block` or not
// until you return.
//
// Parameters: None
//
// Returns: None
void
zero_task_mng_block();

#endif
