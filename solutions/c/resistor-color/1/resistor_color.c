#include <stdio.h>
#include "resistor_color.h"

int color_code(resistor_band_t color) {
    // Return the value associated with the color
    return color;
}

// Loop through the enum
resistor_band_t *colors(void) {
    static resistor_band_t color_array[] = {
        BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE
    };
    
    return color_array;
}