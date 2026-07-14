#include "sublist.h"

comparison_result_t check_lists(
    int *compare_list,
    int *base_list,
    size_t compare_list_size,
    size_t base_list_size
) {
    if (compare_list_size == 0 && base_list_size == 0) {
        return EQUAL;
    }

    if (base_list_size == compare_list_size) {
        for (size_t i = 0; i < base_list_size; i++) {
            if (compare_list[i] != base_list[i]) {
                return UNEQUAL;
            }
        }

        return EQUAL;
    }

    if (base_list_size > compare_list_size) {
        for (size_t i = 0; i <= base_list_size - compare_list_size; i++) {
            int match = 1;
            for (size_t j = 0; j < compare_list_size; j++) {
                if (compare_list[j] != base_list[i + j]) {
                    match = 0;
                    break;
                }
            }

            if (match) {
                return SUBLIST;
            }
        }

        return UNEQUAL;
    }

    if (compare_list_size > base_list_size) {
        for (size_t i = 0; i <= compare_list_size - base_list_size; i++) {
            int match = 1;
            for (size_t j = 0; j < base_list_size; j++) {
                if (base_list[j] != compare_list[i + j]) {
                    match = 0;
                    break;
                }
            }

            if (match) {
                return SUPERLIST;
            }
        }

        return UNEQUAL;
    }

    return UNEQUAL;
}