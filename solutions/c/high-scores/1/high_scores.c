#include <stdint.h>
#include <stddef.h>

#include "high_scores.h"

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int32_t high_score;
    for (size_t i = 0; i < scores_len; i++) {
        high_score = scores[i];

        for (size_t j = 0; j < scores_len; j++) {
            if (high_score < scores[j]) {
                high_score = scores[j];
            }
        }
    }

    return high_score;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
#include <stdint.h>
#include <stddef.h>

size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output) {
    if (scores_len == 0) return 0;

    // Copy scores to a temporary array for sorting
    int32_t temp[3] = {INT32_MIN, INT32_MIN, INT32_MIN};

    // Find the top three scores
    for (size_t i = 0; i < scores_len; ++i) {
        int32_t score = scores[i];
        if (score > temp[0]) {
            temp[2] = temp[1];
            temp[1] = temp[0];
            temp[0] = score;
        } else if (score > temp[1]) {
            temp[2] = temp[1];
            temp[1] = score;
        } else if (score > temp[2]) {
            temp[2] = score;
        }
    }

    // Write up to three scores to output
    size_t count = scores_len < 3 ? scores_len : 3;
    for (size_t i = 0; i < count; ++i) {
        output[i] = temp[i];
    }
    return count;
}