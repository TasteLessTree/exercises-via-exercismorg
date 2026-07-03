#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_paired(const char *input);
void push(char *stack, int *top, char c);
char pop(char *stack, int *top);
char peek(char *stack, int top);

#endif
