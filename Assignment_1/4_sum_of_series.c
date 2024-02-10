#include <stdio.h>

void main()
{
    int n, sum = 0, a = 1, b = 1, c;
    printf("Enter number N: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        sum += a * a;
        c = a + b; // next element
        a = b;
        b = c;
    }
    
    printf("The sum of series is %d", sum);
}