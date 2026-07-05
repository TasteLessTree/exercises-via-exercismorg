#include "spiral_matrix.h"

spiral_matrix_t *spiral_matrix_create(int size) {  
    spiral_matrix_t *matrix = malloc(sizeof(spiral_matrix_t));

    if (!matrix) {
        return NULL;
    }

    if (size <= 0) {
        matrix->matrix = NULL;
        return matrix;
    }

    matrix->size = size;
    matrix->matrix = malloc(size * sizeof(int *));

    if (!matrix->matrix) {
        free(matrix);
        return NULL;
    }
    
    for (int i = 0; i < size; i++) {
        matrix->matrix[i] = malloc(size * sizeof(int));
        
        if (!matrix->matrix[i]) {
            for (int j = 0; j < i; j++) {
                free(matrix->matrix[j]);
            }
            free(matrix->matrix);
            free(matrix);
            return NULL;
        }
    }

    int top = 0, bottom = size - 1, left = 0, right = size - 1, num = 1;

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            matrix->matrix[top][col] = num;
            num++;
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            matrix->matrix[row][right] = num;
            num++;
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                matrix->matrix[bottom][col] = num;
                num++;
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                matrix->matrix[row][left] = num;
                num++;
            }
            left++;
        }
    }

    return matrix;
}

void spiral_matrix_destroy(spiral_matrix_t *matrix) {
    if (!matrix) {
        return;
    }
    
    for (int i = 0; i < matrix->size; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
    free(matrix);
}