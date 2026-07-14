#include "all_your_base.h"

size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length){
    if (input_length == 0) {
        return 0;
    }
    
    if (input_base < 2 || output_base < 2) {
        return 0;
    }
    
    for (size_t i = 0; i < input_length; i++) {
        if (digits[i] < 0 || digits[i] >= input_base) {
            return 0;
        }
    }

    uint64_t decimal_value = 0;
    for (size_t i = 0; i < input_length; i++) {
        decimal_value = decimal_value * input_base + digits[i];
    }

    if (decimal_value == 0) {
        digits[0] = 0;
        return 1;
    }

    int8_t temp[DIGITS_ARRAY_SIZE];
    size_t output_length = 0;

    while (decimal_value > 0) {
        temp[output_length] = (int8_t) (decimal_value % output_base);
        decimal_value /= output_base;
        output_length++;
    }

    for (size_t i = 0; i < output_length; i++) {
        digits[i] = temp[output_length - 1 - i];
    }
    
    return output_length;
}