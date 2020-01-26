#ifndef CLOCK_H
#define CLOCK_H

#include <time.h>

typedef struct {
    struct timespec begin;
    struct timespec end;
} Timer;

typedef enum {
    SPAN_NSEC,
    SPAN_USEC,
    SPAN_MSEC,
    SPAN_SEC
} Span;

int timer_start(Timer *timer)
{
    return timespec_get(&timer->begin, TIME_UTC);
}

int timer_stop(Timer *timer)
{
    return timespec_get(&timer->end, TIME_UTC);
}

double timer_get_span(Timer *timer, Span span)
{
    long sec  = timer->end.tv_sec - timer->begin.tv_sec;
    long nsec = timer->end.tv_nsec - timer->begin.tv_nsec;

    if (nsec < 0) {
        sec--;
        nsec += 1000000000L;
    }

    double time;

    switch (span) {
        case SPAN_NSEC:
        time = sec * 1000000000 + nsec;
        break;
        case SPAN_USEC:
        time = sec * 1000000 + (double)nsec / 1000;
        break;
        case SPAN_MSEC:
        time = sec * 1000 + (double)nsec / 1000000;
        break;
        default:
        time = sec + (double)nsec / 1000000000;
        break;
    }

    return time;
}

#endif
