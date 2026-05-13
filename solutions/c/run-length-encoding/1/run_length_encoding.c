#include "run_length_encoding.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char *encode(const char *text) {
    size_t len = strlen(text);
    
    char *result = (char *)malloc(len * 2 + 1);
    if (result == NULL) {
        return NULL;
    }
    
    *result = '\0';
    size_t pos = 0;
    
    int counter = 0;
    for (size_t i = 0; i < len; i++) {
        char current = *(text + i);
        char next = (i + 1 < len) ? *(text + i + 1) : '\0';
        
        counter++;
        
        if (current != next) {
            if (counter == 1) {
                *(result + pos++) = current;
            } else {
                pos += sprintf(result + pos, "%d%c", counter, current);
            }
            counter = 0;
        }
    }
    
    *(result + pos) = '\0';
    return result;
}

char *decode(const char *data) {
    size_t len = strlen(data);
    
    char *result = (char *)malloc(len * 5 + 1);
    if (result == NULL) {
        return NULL;
    }
    
    *result = '\0';
    size_t pos = 0;
    
    for (size_t i = 0; i < len; i++) {
        char current = *(data + i);
    
        if (current >= '0' && current <= '9') {
            int number = 0;
            
            while (i < len && *(data + i) >= '0' && *(data + i) <= '9') {
                number = number * 10 + (*(data + i) - '0');
                i++;
            }
            
            char repeat = *(data + i);
            
            for (int j = 0; j < number; j++) {
                *(result + pos++) = repeat;
            }
        } else {
            *(result + pos++) = current;
        }
    }
    
    *(result + pos) = '\0';
    return result;
}