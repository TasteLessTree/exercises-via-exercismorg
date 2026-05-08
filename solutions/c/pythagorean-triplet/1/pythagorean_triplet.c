#include "pythagorean_triplet.h"

triplets_t *triplets_with_sum(uint16_t sum) {
    triplets_t *result = malloc(sizeof(triplets_t));
    if (!result) {
        return NULL;    
    }

    result->triplets = malloc(sum * sizeof(triplet_t));
    if (!result->triplets) {
        free(result);
        return NULL;
    }

    result->count = 0;
    for (uint16_t a = 1; a * 3 < sum; a++) {
        for (uint16_t b = a + 1; a + 2 * b < sum; b++) {
            uint16_t c = sum - a - b;
            if (a * a + b * b == c * c) {
                result->triplets[result->count].a = a;
                result->triplets[result->count].b = b;
                result->triplets[result->count].c = c;
                result->count++;
            }
        }
    }
    
    if (result->count > 0) {
        triplet_t *resized = realloc(result->triplets, result->count * sizeof(triplet_t));
        if (resized) {
            result->triplets = resized;
        }
    } else {
        free(result->triplets);
        result->triplets = NULL;
    }
    return result;
}

void free_triplets(triplets_t *triplets) {
    if (triplets) {
        free(triplets->triplets);
        free(triplets);
    }
}