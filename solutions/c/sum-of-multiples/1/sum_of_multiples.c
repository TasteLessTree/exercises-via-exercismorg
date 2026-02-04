#include <stdbool.h>
#include <stdlib.h>

#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit) {
    if (number_of_factors == 0 || limit == 0) return 0;

    // To avoid adding duplicates, we use a boolean array
    bool *visited = (bool *)calloc(limit, sizeof(bool));
    unsigned int total = 0;

    for (size_t i = 0; i < number_of_factors; ++i) {
        unsigned int factor = factors[i];
        if (factor == 0) continue; // Avoid division by zero

        for (unsigned int multiple = factor; multiple < limit; multiple += factor) {
            if (!visited[multiple]) {
                total += multiple;
                visited[multiple] = true;
            }
        }
    }

    free(visited);
    return total;
}