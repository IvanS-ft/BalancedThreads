// License: BSD 3-Clause License

// Header for platform-dependent function manager

#ifndef BT_OSDEPENDENT_H
#define BT_OSDEPENDENT_H

#include "Thread.h"
#include "Lock.h"
#include <Config.h>

struct SOSFunctions{
    struct threadHandler{
        void* (*CreateThread)(FHandler);
        void (*JoinThread)(void*);
        void (*DestroyThread)(void*);
    };
    struct lockHandler {
        void* (*CreateLock)();
        void (*AcquireLock)();
        void (*ReleaseLock)();
        void (*DestroyLock)(void*);
    };
};

extern struct SOSFunctions handlers[BT_NUMOS];
const struct SOSFunctions* GetOSFunctions();

#endif