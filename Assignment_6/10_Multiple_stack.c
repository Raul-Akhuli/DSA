#include <stdio.h>
#include <stdlib.h>

#define MAX_STACKS 3 // Number of stacks
#define MAX_SIZE 100 // Total size of the array

// Structure to represent a stack
struct Stack {
    int top; // Top of the stack
    int* array; // Array to store the elements
};

// Initialize a stack
void initialize(struct Stack* stack, int* array, int stackSize) {
    stack->top = -1;
    stack->array = array;
}

// Check if a stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if a stack is full
int isFull(struct Stack* stack, int stackSize) {
    return stack->top == stackSize - 1;
}

// Push an element onto a stack
void push(struct Stack* stack, int stackSize, int data) {
    if (isFull(stack, stackSize)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
}

// Pop an element from a stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int main() {
    int array[MAX_SIZE];
    struct Stack stacks[MAX_STACKS];

    // Calculate the size of each stack
    int stackSize = MAX_SIZE / MAX_STACKS;

    // Initialize each stack
    for (int i = 0; i < MAX_STACKS; i++) {
        initialize(&stacks[i], &array[i * stackSize], stackSize);
    }

    // Push and pop elements from the first stack
    push(&stacks[0], stackSize, 1);
    push(&stacks[0], stackSize, 2);
    push(&stacks[0], stackSize, 3);
    printf("Popped from stack 1: %d\n", pop(&stacks[0]));

    // Push and pop elements from the second stack
    push(&stacks[1], stackSize, 4);
    push(&stacks[1], stackSize, 5);
    printf("Popped from stack 2: %d\n", pop(&stacks[1]));

    // Push and pop elements from the third stack
    push(&stacks[2], stackSize, 6);
    printf("Popped from stack 3: %d\n", pop(&stacks[2]));

    return 0;
}