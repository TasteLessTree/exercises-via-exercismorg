#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    // Check for valid positions
    if (queen_1.row > 7 || queen_1.column > 7 || queen_2.row > 7 || queen_2.column > 7 ||
       (queen_1.row == queen_2.row && queen_1.column == queen_2.column)) {
        return INVALID_POSITION;
    }

    // Check if they can attack each other
    if (queen_1.row == queen_2.row ||
        queen_1.column == queen_2.column ||
        (queen_1.row - queen_1.column) == (queen_2.row - queen_2.column) ||
        (queen_1.row + queen_1.column) == (queen_2.row + queen_2.column)) {
        return CAN_ATTACK;
    }

    // If none of the conditions are true, then they cannot attack each other
    return CAN_NOT_ATTACK;
}