#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key) {
    char *solution = (char *)malloc(strlen(text) + 1);
    strcpy(solution, text);
    
    for (int i = 0; text[i] != '\0'; i++) {
        if(islower(text[i])) {
            solution[i] = (text[i] - 'a' + shift_key) % 26 + 'a';
        } else if (isupper(text[i])) {
            solution[i] = (text[i] - 'A' + shift_key) % 26 + 'A';
        }
    }

    return solution;
}