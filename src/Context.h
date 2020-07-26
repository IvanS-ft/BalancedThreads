// License: BSD 3-Clause License

// Header for the context

#ifndef BT_CONTEXT_H
#define BT_CONTEXT_H
#define BT_INTERNAL
#include "BalancedThreads.h"
#include "Lock.h"
#include <string.h>

struct SContext {
    struct SLock jobsLock;
    size_t numJobs;

};

#endif