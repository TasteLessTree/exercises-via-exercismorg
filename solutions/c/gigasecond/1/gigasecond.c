#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size) {
    // Add 1 gigasecond to input (1,000,000,000)
    // '1e9' can be seen as '10^9' (ten to the power of nine)
    time_t future_seconds = input + 1e9;
    
    // Conver input to UTC (Coordinated Universal Time)
    struct tm *utc_time = gmtime(&future_seconds);

    // Formating the output
    strftime(output, size, "%Y-%m-%d %H:%M:%S", utc_time);
}