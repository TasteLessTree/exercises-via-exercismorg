#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score) {
    if (allergen >= ALLERGEN_COUNT)
        return false; // Out of bounds
    return (score & allergen_values[allergen]) != 0;
}

allergen_list_t get_allergens(int score) {
    allergen_list_t list = {0};
    list.count = 0;
    for (int i = 0; i < ALLERGEN_COUNT; ++i) {
        if (score & allergen_values[i]) {
            list.allergens[i] = true;
            list.count++;
        } else {
            list.allergens[i] = false;
        }
    }
    return list;
}