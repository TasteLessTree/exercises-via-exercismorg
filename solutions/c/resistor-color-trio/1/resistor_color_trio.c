#include <stdint.h>

#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t colors[]) {
    uint64_t main_value = colors[0] * 10 + colors[1]; // Same as "Resistor Color Duo"
    uint64_t zeros = colors[2];

    // We add the ceros
    uint64_t ohms = main_value;
    for (uint64_t i = 0; i < zeros; i++) {
        ohms *= 10;
    }

    resistor_value_t result;

    uint64_t giga = 1000000000ULL;
    uint64_t mega = 1000000ULL;
    uint64_t kilo = 1000ULL;
    
    if (ohms >= giga && ohms % giga == 0) {
        result.value = ohms / giga;
        result.unit = GIGAOHMS;
    } else if (ohms >= mega && ohms % mega == 0) {
        result.value = ohms / mega;
        result.unit = MEGAOHMS;
    } else if (ohms >= kilo && ohms % kilo == 0) {
        result.value = ohms / kilo;
        result.unit = KILOOHMS;
    } else {
        result.value = ohms;
        result.unit = OHMS;
    }

    return result;
}