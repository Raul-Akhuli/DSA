#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char arr[MAX_SIZE];
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, char c) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = c;
}

char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

void reverseString(char *inputString) {
    int length = strlen(inputString);
    struct Stack stack;
    initialize(&stack);
    for (int i = 0; i < length; i++) {
        push(&stack, inputString[i]);
    }
    for (int i = 0; i < length; i++) {
        inputString[i] = pop(&stack);
    }
}

int main() {
    char inputString[1000];
    printf("Enter string:");
    gets(inputString);
    reverseString(inputString);
    printf("Reversed string: %s\n", inputString);
    return 0;
}