#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

#include <ctype.h>

unsigned int score(const char *word);

// helpers
int is_one_point(char c);
int is_two_points(char c);
int is_three_points(char c);
int is_four_points(char c);
int is_five_points(char c);
int is_eight_points(char c);
int is_ten_points(char c);

#endif
