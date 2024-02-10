#include <stdio.h>

unsigned long long fibonacci(int n, unsigned long long a, unsigned long long b) {
    if (n == 0) {
        return a;
    }
    printf("%llu ", a);
    return fibonacci(n - 1, b, a + b);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Fibonacci Series up to %d: ", n);

    if (n >= 0) {
        printf("0 "); // Print the first Fibonacci number (0) separately
    }

    if (n >= 1) {
        printf("1 "); // Print the second Fibonacci number (1) separately
    }

    if (n >= 2) {
        fibonacci(n - 2, 1, 2); // Start printing from the third Fibonacci number
    }

    printf("\n");

    return 0;
}