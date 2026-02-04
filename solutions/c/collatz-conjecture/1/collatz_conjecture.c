#include "collatz_conjecture.h"

int steps(int start) {
    int steps = 0;

    if (start <= 0) {
        steps = -1;
    } else {
        while(start > 1) {
            if (start % 2 == 0) {
                start = start / 2;
                steps++;
            } else {
                start = (start * 3) + 1;
                steps++;
            }
        
            if (start == 1)
                break;
        }
    }

    return steps;
}