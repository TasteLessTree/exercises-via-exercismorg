#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "dnd_character.h"

int ability(void) {
    srand(time(NULL));

    int dice_rolles[4];
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        dice_rolles[i] = (rand() % 6) + 1; // Random number in range [1, 6]
    }

    // Find and discard the lowest number
    int low_num;
    for (int i = 0; i < 4; i++) {
        low_num = dice_rolles[i];

        // This loop returns the lowest number
        for (int j = 0; j < 4; j++) {
            if (dice_rolles[j] < low_num) {
                low_num = dice_rolles[j];
            }
        }
        // We sum up all the rolles we've done
        sum += dice_rolles[i];
    }
    // Substract the lowest number
    sum -= low_num;

    return sum; // <- Ability points
}

int modifier(int score) {
    // The score is the constitution
    // floor rounds down. Takes double as argument (should parse)
    return (floor((double)(score - 10) / 2));
}

dnd_character_t make_dnd_character(void) {
    dnd_character_t Dnd_char;
    
    Dnd_char.strength = ability();
    Dnd_char.dexterity = ability();
    Dnd_char.constitution = ability();
    Dnd_char.intelligence = ability();
    Dnd_char.wisdom = ability();
    Dnd_char.charisma = ability();
    
    Dnd_char.hitpoints = 10 + modifier(Dnd_char.constitution);
    
    return Dnd_char;
}