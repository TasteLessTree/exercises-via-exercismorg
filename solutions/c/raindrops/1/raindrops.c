#include <stdio.h>

#include "raindrops.h"

void convert(char result[], int drops) {
    if (drops % 3 != 0 && drops % 5 != 0 && drops % 7!= 0) {
        sprintf(result, "%d", drops);
        return;
    }

    if (drops % 7 == 0 && drops % 5 == 0 && drops % 3 == 0) {
        sprintf(result, "%s", "PlingPlangPlong");
        return;
    }

    if (drops % 7 == 0 && drops % 5 == 0) {
        sprintf(result, "%s", "PlangPlong");
        return;
    }

    if (drops % 7 == 0 && drops % 3 == 0) {
        sprintf(result, "%s", "PlingPlong");
        return;
    }

    if (drops % 5 == 0 && drops % 3 == 0) {
        sprintf(result, "%s", "PlingPlang");
        return;
    }

    if (drops % 7 == 0) {
        sprintf(result, "%s", "Plong");
        return;
    }

    if (drops % 5 == 0) {
        sprintf(result, "%s", "Plang");
        return;
    }

    if (drops % 3 == 0) {
        sprintf(result, "%s", "Pling");
        return;
    }
}