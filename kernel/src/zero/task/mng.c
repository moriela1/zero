// Copyright 2026 dywoq
//
// This code is published under Apache License 2.0:
// http://www.apache.org/licenses/LICENSE-2.0
//
// The repository:
// https://github.com/dywoq/zero

#include <types.h>
#include <zero/err.h>
#include <zero/panic.h>
#include <zero/task/mng.h>
#include <zero/task/task.h>

static zero_tid tasks_count_ = 0;
static zero_tid task_current_ = 0;
static struct zero_task tasks_[ZERO_TASK_MNG_MAX] = {};

static void
task_run_(struct zero_task *task) {
    // Push registers
    __asm volatile("pushf\n"
                   "pusha\n"
                   :
                   :
                   : "memory");
    // Run task
    task_current_ = task->tid;
    task->ptr(task->tid);

    // Go to pop label if it's blocked or yielded
    // (since zero_task_mng_yield sets the current task state to READY).
    if (task->state == ZERO_TASK_BLOCKED || task->state == ZERO_TASK_READY) {
        goto pop;
    }

    // Mark it as done and sort array.
    task->state = ZERO_TASK_DONE;
    for (int i = task->tid; i < tasks_count_ - 1; i++) {
        tasks_[i] = tasks_[i + 1];
        tasks_[i].tid = i;
    }
    // Decrease count
    tasks_count_--;
    task_current_ = 0;
    goto pop;

pop:
    // Pop them
    __asm volatile("popa\n"
                   "popf\n"
                   :
                   :
                   : "memory");
    return;
}

enum zero_err
zero_task_mng_add(zero_task_ptr ptr, bool unblock_trigger) {
    if (tasks_count_ >= ZERO_TASK_MNG_MAX) {
        return ZERO_ERR_TASK_OVERFLOW;
    }
    tasks_[tasks_count_].tid = tasks_count_;
    tasks_[tasks_count_].state = ZERO_TASK_READY;
    tasks_[tasks_count_].ptr = ptr;
    tasks_[tasks_count_].unblock_trigger = unblock_trigger;
    tasks_count_++;
    return ZERO_ERR_OK;
}

void
zero_task_mng_loop() {
    // Ignore empty tasks stack
    if (tasks_count_ == 0) {
        return;
    }
    for (int i = 0; i < tasks_count_; i++) {
        struct zero_task *t = &tasks_[i];
        if (t->state == ZERO_TASK_BLOCKED && t->unblock_trigger) {
            t->state = ZERO_TASK_READY;
        }
        if (t->state == ZERO_TASK_READY) {
            task_run_(t);
        }
    }
}

void
zero_task_mng_yield() {
    tasks_[task_current_].state = ZERO_TASK_READY;
}

void
zero_task_mng_block() {
    tasks_[task_current_].state = ZERO_TASK_BLOCKED;
}
