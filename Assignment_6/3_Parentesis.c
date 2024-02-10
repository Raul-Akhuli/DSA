#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = item;
    }
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0';
}

bool areParenthesesBalanced(const char* str) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            push(&stack, str[i]);
        } else if (str[i] == ')') {
            if (isEmpty(&stack)) {
                return false;
            }
            pop(&stack);
        }
    }

    return isEmpty(&stack);
}

int main() {
    char str[MAX_SIZE];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    if (areParenthesesBalanced(str)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}