#include <stdio.h>
#include <math.h>

#include "grains.h"

// Number of grains on a given square
uint64_t square(uint8_t index) {
    // It doubles because they are the powers of 2, 2^(index -1)
    // if index is 1 (the first square) 2^0 = 1
    // if index is 3 2^2 = 4 ...
    index--;
    return pow(2, index);
}

uint64_t total(void) {
    // The total would be our function square with the numbers from 1 to 64 as arguments
    int total = 0;

    for (int i = 1; i <= 64; i++) {
        total += square(i);
    }

    return total;
}