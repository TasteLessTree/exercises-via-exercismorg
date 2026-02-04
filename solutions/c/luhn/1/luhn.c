#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "luhn.h"

bool luhn(const char *num) {
    if (!num) return false;

    // Make a copy without spaces and check for digits
    size_t length = strlen(num);
    char *cleaned_num = malloc(length + 1);

    // Malloc has failed
    if (!cleaned_num) return false;

    size_t j = 0;
    for (size_t i = 0; i < length; i++) {
        if (num[i] == ' ') continue;

        if (!isdigit((unsigned char)num[i])) {
            free(cleaned_num);
            return false; // Invalid char
        }

        cleaned_num[j++] = num[i];
    }
    cleaned_num[j] = '\0';

    if (j <= 1) {
        free(cleaned_num);
        return false;
    }

    int sum = 0;
    bool double_digit = false;

    for (int i = (int)j - 1; i >= 0; --i) {
        int digit = cleaned_num[i] - '0';

        if (double_digit) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }

        sum += digit;
        double_digit = !double_digit;
    }

    free(cleaned_num);
    return (sum % 10 == 0);
}