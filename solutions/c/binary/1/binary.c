#include <string.h>
#include <math.h>

#include "binary.h"

int convert(const char *input) {
	int num = 0;
	int last = strlen(input);
	int exp = last - 1;

	for (int i = 0; i < last; i++) {
		if (input[i] == '0') {
			exp--;
			continue;
		} else if (input[i] == '1') {
			num += (int)pow(2, exp);
            exp--;
		} else {
			return INVALID;
		}
	}

	return num;
}