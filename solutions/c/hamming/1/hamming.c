#include "hamming.h"
#include <string.h>

int compute(const char *lhs, const char *rhs) {
    int distance = 0;

    if (strlen(lhs) == strlen(rhs)) {
        for (size_t i = 0; i < strlen(lhs); i++) {
            char currentLetter = lhs[i];

            for (size_t j = i; j <= i; j++) {
                if (currentLetter != rhs[j]) {
                    distance++;
                    break;
                }
            }
        }
    } else {
        distance = -1;
    }
    
    return distance;
}