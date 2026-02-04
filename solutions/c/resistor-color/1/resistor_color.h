#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H

typedef enum {
    BLACK, // = 0
    BROWN, // = 1...
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE // = 9
} resistor_band_t;

// Function prototypes
int color_code(resistor_band_t);
resistor_band_t *colors(void);

#endif