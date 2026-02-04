#include "eliuds_eggs.h"

#include <string.h>

int egg_count(int display) {
    int base = 2; // Base 2 (binary)
    char s[MAXIMUM]; // String where the binary number will be saved

    itob(display, s, base);

    int eggs = one_counter(s);
    
    return eggs;
}

// Converts the integer number into a base 'base' character representation in the string 'str'.
// In particular, itob(n,s,16) formats 'num' as a hexadecimal integer in 'str'.
void itob(int num, char str[], int base) {
    int i = 0;
    do {
        if (num % base > 9)
            str[i++] = num % base + 'A' - 10;
        else
            str[i++] = num % base + '0';
    } while ((num /= base));

    reverse(str);
}

void reverse(char str[]) {
    int i, j, c;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
        c = str[i], str[i] = str[j], str[j] = c;
}

int one_counter(char binary[]) {
    int ones = 0;

    for (size_t i = 0; i < strlen(binary); i++)
        if (binary[i] == '1')
            ones++;
    
    return ones;
}