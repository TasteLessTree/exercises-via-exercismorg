#include "resistor_color_duo.h"

int color_code(resistor_band_t color[]) {
    int num1 = color[0]; // The first element
    int num2 = color[1]; // The second element, ignores the third color

    int solution = num1 * 10 + num2; // num1 is multiplied by 10 so we obtain the tens
    
    return solution;
}