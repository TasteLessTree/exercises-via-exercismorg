#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "isogram.h"

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) {
        return false;
    }

    // Allocate memory for the string
    int len = strlen(phrase) + 1; // Inlcudes '\0'
    char *str = (char *)malloc(len * sizeof(char));

    // Coping the string, including '\0'
    for (int i = 0; i < len; i++) {
        str[i] = tolower(phrase[i]);
    }

    str[len] = '\0';

    // Sort the array
    bubble_sort(str, len);

    // Compare the chars
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len - 1; j++) {
            if (str[i] == ' ' || str[i] == '-') {
                continue;
            }
            if (str[i] == str[j]) {
                free(str);
                return false;
            }
        }
    }
    return true;
}

void bubble_sort(char arr[], int length) {
    char temp;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            char *ptr = &arr[j];
            char *ptr_temp = &arr[j + 1];

            if (*ptr > *ptr_temp) {
                temp = *ptr;
                *ptr = *ptr_temp;
                *ptr_temp = temp;            
            } 
        }
    }
}