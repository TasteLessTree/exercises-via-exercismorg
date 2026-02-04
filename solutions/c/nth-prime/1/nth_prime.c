#include "nth_prime.h"

int isPrime(uint32_t n) {
    // Corner cases
    if (n <= 1) {
        return 0;
    }

    if (n == 2 || n == 3) {
        return 1;
    }

    // Between 0 and 5, there are only two prime numbers: two and three
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    // Using concept of prime number can be represented in form of (6*k + 1) or(6*k - 1)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}

uint32_t nth(uint32_t n) {
    uint32_t i = 1;

    while (n > 0) {
        if (isPrime(i)) {
            n--;
        }
        i++;
    }
    --i;

    return i;
}