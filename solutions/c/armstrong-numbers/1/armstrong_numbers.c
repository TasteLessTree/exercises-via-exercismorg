#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate) {
    int sum = 0;
    
    // Allocate memory for the string
    int length = snprintf(NULL, 0, "%d", candidate);
    char *str = malloc(length + 1);
    snprintf(str, length + 1, "%d", candidate);

    for (int i = 0; i < length; i++) {
        int digit = str[i] - '0';
        sum += (int)pow((double)digit, (double)length);
    }
    
    free(str);

    if (candidate == sum) return true;
    
    return false;
}