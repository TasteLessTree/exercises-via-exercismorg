#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "nucleotide_count.h"

char *count(const char *dna_strand) {
    // We count:     A, C, G, T
    int counts[4] = {0, 0, 0, 0};
    const char *ptr = dna_strand;

    // Allocate enough space for the result string
    char *result = malloc(20); // To have enough space for 2-digit counts in all of the nucleotides

    if (!result) {
        return NULL;
    }
    
    while (*ptr) {
        switch (*ptr) {
            case 'A':
                counts[0]++;
                break;

            case 'C':
                counts[1]++;
                break;

            case 'G':
                counts[2]++;
                break;

            case 'T':
                counts[3]++;
                break;

            default:
                if (result) strcpy(result, "");
                return result;
        }
        ptr++;
    }

    snprintf(result, 20, "A:%d C:%d G:%d T:%d", counts[0], counts[1], counts[2], counts[3]);

    return result;
}