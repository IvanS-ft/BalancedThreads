// License: BSD 3-Clause License

// Header for the error manager


#ifndef BT_ERROR_H
#define BT_ERROR_H

#include <stdint.h>
#include <Config.h>

enum EErrorType {
    SUCCESS,
};

struct SError {
    enum EErrorType errorCode;
#ifdef BT_DEBUG
    const char* problematicFunc;
    size_t line;
    const char* why; //Reasoning behind the error
#endif
};

extern struct SError threadsError[BT_MAXTHREADS + 1];

// Gets the error in the current thread
// Params:
//   - context: if nullptr, then get the error for main thread, otherwise for the current thread
struct SError ErrorGet(void* context);

const char* ErrorStr(struct SError err);

#endif


