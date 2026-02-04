#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
        
        // Check if the middle is the value
        if (arr[middle] == value) {
            return &arr[middle];
        }
        
        // If value is greater than the middle, we ignore the left half
        if (middle < value) {
            low = middle + 1;
        } else {
            // If value is smaller than the middle, we ignore the right half
            high = middle - 1;
        }
    }

    return NULL;
}