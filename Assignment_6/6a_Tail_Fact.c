#include <stdio.h>

#define MAX_DIGITS 1000
#define BASE 10

int stk[MAX_DIGITS];
int size = MAX_DIGITS;
int ptr = -1;

void push(int x) {
    if (ptr == size - 1)
        printf("Overflow\n");
    else {
        ++ptr;
        stk[ptr] = x;
    }
}

int top() {
    if (ptr == -1)
        return 0;
    else
        return stk[ptr];
}

void pop() {
    if (ptr != -1)
        --ptr;
}

int isempty() {
    return ptr == -1;
}

void multiply(int n) {
    int carry = 0;
    for (int i = 0; i <= ptr || carry; ++i) {
        if (i > ptr)
            push(0);
        long long current = stk[i] * 1LL * n + carry;
        stk[i] = current % BASE;
        carry = current / BASE;
    }
}

void calculateFactorial(int n) {
    push(1);
    for (int i = 2; i <= n; ++i)
        multiply(i);
}

void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    calculateFactorial(n);

    printf("Factorial: ");
    while (!isempty()) {
        printf("%d", top());
        pop();
    }
    printf("\n");
}