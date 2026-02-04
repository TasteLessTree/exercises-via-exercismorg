#include "leap.h"

bool leap_year(int year){
    bool leap;
    if (year % 100 == 0){
        if (year % 400 == 0){
            leap = true;
        } else {
            leap = false;
        }
    } else if (year % 4 == 0){
        leap = true;
    } else {
        leap = false;
    }
    return leap;
}