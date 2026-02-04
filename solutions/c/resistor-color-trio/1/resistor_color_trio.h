#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

typedef enum {
    OHMS,
    KILOOHMS,
    MEGAOHMS,
    GIGAOHMS
} unit_t;

typedef struct {
    uint16_t value;
    unit_t unit;
} resistor_value_t;

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

resistor_value_t color_code(resistor_band_t colors[]);

#endif