#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
    size_t count = 0;

    // Factor out of 2s
    while (n % 2 == 0) {
        if (count >= MAXFACTORS) {
            break;
        }
        factors[count++] = 2;
        n /= 2;
    }

    // Try odd numbers starting at 3
    for (size_t i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            if (count >= MAXFACTORS) {
                break;
            }
            factors[count++] = i;
            n /= i;
        }
    }

    // If n is still greater than 1, it's a prime factor
    if (n > 1 && count < MAXFACTORS) {
        factors[count++] = n;
    }
    
    return count;
}