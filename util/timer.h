#ifndef CLOCK_H
#define CLOCK_H

#include <time.h>

typedef struct {
    struct timespec begin;
    struct timespec end;
} timer;

int timer_get_precision(long* sec, long* nsec)
{
    struct timespec res;

    if (clock_getres(CLOCK_MONOTONIC, &res) == -1) {
        return -1;
    }

    *sec  = res.tv_sec;
    *nsec = res.tv_nsec;

    return 0;
}

int timer_start(timer* timer)
{
    return clock_gettime(CLOCK_MONOTONIC, &timer->begin);
}

int timer_stop(timer* timer)
{
    return clock_gettime(CLOCK_MONOTONIC, &timer->end);
}

void timer_get_elapsed(timer* timer, long* sec, long* nsec)
{
    *sec  = timer->end.tv_sec - timer->begin.tv_sec;
    *nsec = timer->end.tv_sec - timer->begin.tv_sec;

    if (*nsec < 0) {
        *sec--;
        *nsec += 1000000000L;
    }
}

#endif
