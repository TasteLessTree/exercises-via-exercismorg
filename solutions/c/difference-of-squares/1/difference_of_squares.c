#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int number) {
    unsigned int result = 0;
    unsigned int num_sqrd = 0;

    for (unsigned int i = number; i > 0; i--) {
        num_sqrd = i * i;

        result += num_sqrd;
    }

    return result;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int result = 0;

    for (unsigned int i = number; i > 0; i--) {
        result += i;
    }

    return result * result;
}

unsigned int difference_of_squares(unsigned int number) {
    return square_of_sum(number) - sum_of_squares(number);
}