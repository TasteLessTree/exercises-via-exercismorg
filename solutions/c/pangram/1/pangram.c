#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#include "pangram.h"

bool is_pangram(const char *sentence) {
    bool seen[26] = { false };

    if (sentence == NULL) return false;

    for (int i = 0; sentence[i] != '\0'; i++) {
        char c = tolower((unsigned char)sentence[i]);
        if (c >= 'a' && c <= 'z') {
            seen[c - 'a'] = true;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!seen[i]) {
            return false;
        }
    }
    return true;
}