// License: BSD 3-Clause License

// Header for platform-independent thread managing

#ifndef BT_THREAD_H
#define BT_THREAD_H

#include <stdint.h>
#include "Timer.h"
#include "Lock.h"

#define BT_DEQUE_RESERVE_INCREASE 16

typedef void (*FHandler)(struct SContext* context, struct SThread* thread);

struct SJobStatistics {
    TTimePoint min;
    TTimePoint max;
    TTimePoint average;
    int64_t iter;
};

struct SJob {
    FHandler function;
    struct SJobStatistics statistics;
    enum {
        BT_JOB_WORKING,
        BT_JOB_STANDBY,
        BT_JOB_FINISHED,
    } status;
};

struct SJobDeque{
    struct SJob* functions;
    size_t front;
    size_t back;
    size_t numElements;
    size_t reservedElements;
};

struct SThread{
    struct SLock lock;
    void* osThread;
    struct SJobDeque deque;
};

void JobDequeInit(struct SJobDeque* deque);
void JobDequePushBack(struct SJobDeque* deque, struct SJob task);
void JobDequePushFront(struct SJobDeque* deque, struct SJob task);
struct SJob JobDequePopBack(struct SJobDeque* deque);
struct SJob JobDequePopFront(struct SJobDeque* deque);
void JobDequeReserveMore(struct SJobDeque* deque);
void JobDequeReserveLess(struct SJobDeque* deque);
struct SJob* JobDequeGetFront(struct SJobDeque* deque);
struct SJob* JobDequeGetBack(struct SJobDeque* deque);
void JobDequeDestroy(struct SJobDeque* deque);



#endif

