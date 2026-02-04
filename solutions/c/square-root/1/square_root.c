#include "square_root.h"

int square_root(int num) {
    int solution = 1;

    for (int i = 1; i < num; i++) {
        int square = i * i;
        if (square == num) {
            solution = i;
            break;
        }
    }
    
    return solution;
}