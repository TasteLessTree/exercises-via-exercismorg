#include "space_age.h"

float age(planet_t planet, int64_t seconds) {
    float age_planet = 0.0F;
    float secs_earth_year = 31557600.0F;
    
    switch (planet) {
        default:
            age_planet = -1.0F;
            break;
        case MERCURY:
            age_planet = seconds / (0.2408467F * secs_earth_year);
            break;
        case VENUS:
            age_planet = seconds / (0.61519726F * secs_earth_year);
            break;
        case EARTH:
            age_planet = seconds / (1.0F * secs_earth_year);
            break;
        case MARS:
            age_planet = seconds / (1.8808158F * secs_earth_year);
            break;
        case JUPITER:
            age_planet = seconds / (11.862615F * secs_earth_year);
            break;
        case SATURN:
            age_planet = seconds / (29.447498F * secs_earth_year);
            break;
        case URANUS:
            age_planet = seconds / (84.016846F * secs_earth_year);
            break;
        case NEPTUNE:
            age_planet = seconds / (164.79132F * secs_earth_year);
            break;
    }

    return age_planet;
}