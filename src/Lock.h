// License: BSD 3-Clause License

// Header for platform-independent lock

#ifndef BT_LOCK_H
#define BT_LOCK_H

struct SLock{
    void* osLock; // Dynamically allocated pointer to lock
};

void LockInit(struct SLock* lock);
void LockDestroy(struct SLock* lock);
void LockAcquire(struct SLock* lock);
void LockRelease(struct SLock* lock);

#endif
