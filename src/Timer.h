// License: BSD 3-Clause License

// Header for the timer

#ifndef BT_TIMER_H
#define BT_TIMER_H

#include <stdint.h>

// Measured in nanoseconds
typedef int64_t TTimePoint;

void TimerCurrent(TTimePoint* timePoint);

#endif
