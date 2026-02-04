#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "clock.h"

clock_t clock_create(int hour, int minute) {
    clock_t clock;

    int total_minutes = hour * 60 + minute;

    // 1440 == minutes per day (60 * 24)
    total_minutes = ((total_minutes % 1440) + 1440) % 1440;

    int norm_hour = total_minutes / 60;
    int norm_minute = total_minutes % 60;
    snprintf(clock.text, MAX_STR_LEN, "%02d:%02d", norm_hour, norm_minute);
    
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    int hour;
    int minute;
    sscanf(clock.text, "%d:%d", &hour, &minute);

    return clock_create(hour, minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    int hour;
    int minute;
    sscanf(clock.text, "%d:%d", &hour, &minute);

    return clock_create(hour, minute - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
    return strcmp(a.text, b.text) == 0;
}