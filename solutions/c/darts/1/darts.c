#include "darts.h"

int score (coordinate_t pos) {  
    // Calculate the square of the distance from the center (0,0)
    float distance_squared = pos.x * pos.x + pos.y * pos.y;
    
    // Check the outer circle (radius 10)
    if (distance_squared <= 10.0F * 10.0F){
        // Check the middle circle (radius 5)
        if (distance_squared <= 5.0F * 5.0F) {
            // Check the inner circle (radius 1)
            if (distance_squared <= 1.0F * 1.0F) {
                return 10;
            }
            // Middle circle
            return 5;
        }
        // Outer circle
        return 1;
    }

    // If it's outside the target (distance is greater than radius 10)
    return 0;
}