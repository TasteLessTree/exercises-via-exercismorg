#include <stdlib.h>
#include <string.h>

#include "sieve.h"

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
    if (limit < 2 || max_primes == 0) {
        return 0;
    }

    // Allocate a boolean array to mark prime/nonprime; index 0..limit
    char *is_prime = (char*)malloc((limit + 1) * sizeof(char));
    if (!is_prime) return 0;

    memset(is_prime, 1, limit + 1); // Assume all numbers are prime
    is_prime[0] = is_prime[1] = 0;  // 0 and 1 are not prime

    uint32_t count = 0;
    for (uint32_t i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (uint32_t j = i * i; j <= limit; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    // Collect primes up to limit (but not more than max_primes)
    for (uint32_t i = 2; i <= limit && count < max_primes; ++i) {
        if (is_prime[i]) {
            primes[count++] = i;
        }
    }

    free(is_prime);
    return count;
}