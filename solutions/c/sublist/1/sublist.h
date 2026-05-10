#ifndef SUBLIST_H
#define SUBLIST_H

#include <stddef.h>

typedef enum {
    EQUAL,
    UNEQUAL,
    SUBLIST,
    SUPERLIST
} comparison_result_t;

comparison_result_t check_lists(
    int *compare_list,
    int *base_list,
    size_t compate_list_size,
    size_t base_list_size
);

#endif
