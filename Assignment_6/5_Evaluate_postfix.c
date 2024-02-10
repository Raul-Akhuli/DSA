#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    int stack[MAX];
} Stack;

void initializeStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->stack[++stack->top] = value;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->stack[stack->top--];
}

int evaluatePostfix(char* expression) {
    Stack stack;
    initializeStack(&stack);

    int length = strlen(expression);
    for (int i = 0; i < length; i++) {
        if (isdigit(expression[i])) {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}

void main() {
    char postfix[MAX];
    printf("Enter the equation: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strlen(postfix) - 1] = '\0';
    int result = evaluatePostfix(postfix);
    printf("Result of postfix expression %s is: %d\n", postfix, result);
}