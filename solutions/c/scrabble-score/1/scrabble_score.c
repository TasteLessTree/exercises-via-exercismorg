#include "scrabble_score.h"

unsigned int score(const char *word) {
    unsigned int score = 0;

    char *p = (char *)&word[0];
    
    while (*p != '\0') {
        if (is_one_point(*p)) {
            score++;
        } else if (is_two_points(*p)) {
            score += 2;
        } else if (is_three_points(*p)) {
            score += 3;
        } else if (is_four_points(*p)) {
            score += 4;
        } else if (is_five_points(*p)) {
            score += 5;
        } else if (is_eight_points(*p)) {
            score += 8;
        } else if (is_ten_points(*p)) {
            score += 10;
        }
        p++;
    }
    
    return score;
}

int is_one_point(char c) {
    char one_point_letters[] = {'a', 'e', 'i', 'o', 'u', 'l', 'n', 'r', 's', 't'};
    int length = sizeof(one_point_letters) / sizeof(one_point_letters[0]);
    
    for (int i = 0; i < length; i++) {
        if (tolower(c) == one_point_letters[i]) {
            return 1; // true
        }
    }
    
    return 0; // false
}

int is_two_points(char c) {
    char two_points_letters[] = {'d', 'g'};
    int length = sizeof(two_points_letters) / sizeof(two_points_letters[0]);
    
    for (int i = 0; i < length; i++) {
        if (tolower(c) == two_points_letters[i]) {
            return 1; // true
        }
    }
    
    return 0; // false
}

int is_three_points(char c) {
    char three_points_letters[] = {'b', 'c', 'm', 'p'};
    int length = sizeof(three_points_letters) / sizeof(three_points_letters[0]);
    
    for (int i = 0; i < length; i++) {
        if (tolower(c) == three_points_letters[i]) {
            return 1; // true
        }
    }
    
    return 0; // false
}

int is_four_points(char c) {
    char four_points_letters[] = {'f', 'h', 'v', 'w', 'y'};
    int length = sizeof(four_points_letters) / sizeof(four_points_letters[0]);
    
    for (int i = 0; i < length; i++) {
        if (tolower(c) == four_points_letters[i]) {
            return 1; // true
        }
    }
    
    return 0; // false
}

int is_five_points(char c) {
    if (tolower(c) == 'k') {
        return 1; // true
    }
    
    return 0; // false
}

int is_eight_points(char c) {
    char eight_points_letters[] = {'j', 'x'};
    int length = sizeof(eight_points_letters) / sizeof(eight_points_letters[0]);
    
    for (int i = 0; i < length; i++) {
        if (tolower(c) == eight_points_letters[i]) {
            return 1; // true
        }
    }
    
    return 0; // false
}

int is_ten_points(char c) {
    char ten_points_letters[] = {'q', 'z'};
    int length = sizeof(ten_points_letters) / sizeof(ten_points_letters[0]);
    
    for (int i = 0; i < length; i++) {
        if (tolower(c) == ten_points_letters[i]) {
            return 1; // true
        }
    }
    
    return 0; // false
}