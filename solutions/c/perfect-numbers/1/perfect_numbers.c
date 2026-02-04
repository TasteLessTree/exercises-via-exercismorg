#include "perfect_numbers.h"

int classify_number(int num) {
    if (num <= 0)
        return ERROR;
    
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (num == sum)
        return PERFECT_NUMBER;
    if (num < sum)
        return ABUNDANT_NUMBER;
    if (num > sum)
        return DEFICIENT_NUMBER;
    else
        return ERROR;
}