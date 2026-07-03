#include "matching_brackets.h"

bool is_paired(const char *input) {
    size_t len = strlen(input);
    
    if (len == 0) {
        return true;
    }

    char *stack = malloc(len + 1);
    if (!stack) {
        return false;
    }
    int top = -1;
    
    for (size_t i = 0; i < len; i++) {
        char current = *(input + i);
        
        // Add them to the array if they are open
        if (current == '[') {
            push(stack, &top, '[');
        } else if (current == '{') {
            push(stack, &top, '{');
        } else if (current == '(') {
            push(stack, &top, '(');
        }
        
        // Remove them for the array if they are closed
        if (current == ']') {
            if (top == -1) {
                free(stack);
                return false;
            }
            char top_stack = peek(stack, top);
            if (top_stack == '[') {
                pop(stack, &top);
            } else {
                free(stack);
                return false;
            }
        } else if (current == '}') {
            if (top == -1) {
                free(stack);
                return false;
            }
            char top_stack = peek(stack, top);
            if (top_stack == '{') {
                pop(stack, &top);
            } else {
                free(stack);
                return false;
            }
        } else if (current == ')') {
            if (top == -1) {
                free(stack);
                return false;
            }
            char top_stack = peek(stack, top);
            if (top_stack == '(') {
                pop(stack, &top);
            } else {
                free(stack);
                return false;
            }
        }
    }
    
    free(stack);
    
    return (top == -1) ? true : false;
}

void push(char *stack, int *top, char c) {
    (*top)++;
    stack[*top] = c;
}

char pop(char *stack, int *top) {
    char c = stack[*top];
    (*top)--;
    return c;
}

char peek(char *stack, int top) {
    return stack[top];
}