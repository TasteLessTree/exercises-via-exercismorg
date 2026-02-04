#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(char *value) {
    char *str = malloc(strlen(value)); // Allocates memory for the number of characters in value

    if (str == NULL) return NULL; // Memory allocation has failed
    
    char *ptrValue = &value[0]; // Pointer to the first element of "value"
    char *ptrSolution = &str[strlen(value) - 1]; // Pointer to the last element of the array

    for (size_t i = 0; i < strlen(value); i++) {
        *ptrSolution = *ptrValue; // Copy the character
        ptrSolution--; // Decrease the address of the solution
        ptrValue++; // Increase the address "value"
    }
    
    return str; // Return the solution
}