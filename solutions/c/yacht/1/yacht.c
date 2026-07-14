#include <stdlib.h>

#include "yacht.h"

int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int score(dice_t dice, category_t category) {
    int length = sizeof(dice.faces) / sizeof(dice.faces[0]);
    int score = 0;
    switch (category) {
        case ONES:
            for (int i = 0; i < length; i++) {
                if (dice.faces[i] == 1) {
                    score++;
                }
            }
            break;
        
        case TWOS:
            for (int i = 0; i < length; i++) {
                if (dice.faces[i] == 2) {
                    score += 2;
                }
            }
            break;
        
        case THREES:
            for (int i = 0; i < length; i++) {
                if (dice.faces[i] == 3) {
                    score += 3;
                }
            }
            break;
        
        case FOURS:
            for (int i = 0; i < length; i++) {
                if (dice.faces[i] == 4) {
                    score += 4;
                }
            }
            break;
        
        case FIVES:
            for (int i = 0; i < length; i++) {
                if (dice.faces[i] == 5) {
                    score += 5;
                }
            }
            break;
        
        case SIXES:
            for (int i = 0; i < length; i++) {
                if (dice.faces[i] == 6) {
                    score += 6;
                }
            }
            break;
        
        case FULL_HOUSE:
            // sort the array
            qsort(dice.faces, length, sizeof(dice.faces[0]), comp);
            // counters for the numbers
            int first_counter = 0;
            int second_counter = 0;

            // we know these two numbers are different
            int first_number = dice.faces[0];
            int last_number = dice.faces[length - 1];

            int idx = 0;
            while (idx < length) {
                int current = dice.faces[idx];

                if (current == first_number) {
                    first_counter++;
                } else if (current == last_number) {
                    second_counter++;
                }

                // two small three big
                if (first_counter == 2 && second_counter == 3) {
                    score = (first_number * 2) + (last_number * 3);
                }
                // three small two big
                if (first_counter == 3 && second_counter == 2) {
                    score = (first_number * 3) + (last_number * 2);
                }

                idx++;
            }
            break;
        
        case FOUR_OF_A_KIND:
            for (int i = 0; i < length; i++) {
                int counter = 0;
                int current = dice.faces[i];
                for (int j = 0; j < length; j++) {
                    if (current == dice.faces[j]) {
                        counter++;
                    }

                    if (counter == 4) {
                        score = current * 4;
                        return score;
                    }
                }
            }
            break;

        case LITTLE_STRAIGHT:
            // sort the array
            qsort(dice.faces, length, sizeof(dice.faces[0]), comp);

            if (dice.faces[0] == 1 && dice.faces[1] == 2 && dice.faces[2] == 3 && dice.faces[3] == 4 && dice.faces[4] == 5) {
                return 30;
            }
            
            break;
        
        case BIG_STRAIGHT:
            // sort the array
            qsort(dice.faces, length, sizeof(dice.faces[0]), comp);

            if (dice.faces[0] == 2 && dice.faces[1] == 3 && dice.faces[2] == 4 && dice.faces[3] == 5 && dice.faces[4] == 6) {
                return 30;
            }
            break;
        
        case CHOICE:
            for (int i = 0; i < length; i++) {
                score += dice.faces[i];
            }
            break;
        
        case YACHT:
            for (int i = 0; i < length; i++) {
                int current = dice.faces[i];
                for (int j = i + 1; j < length; j++) {
                    if (current != dice.faces[j]) {
                        return 0;
                    }
                }
                break;
            }
            score = 50;
            break;

        default:
            return 0;
    }

    return score;
}