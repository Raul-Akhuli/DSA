#include <stdio.h>

int findOddOccurrence(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++)
        result ^= arr[i];
    return result;
}

void main() {
    int arr[] = {4, 3, 4, 2, 2, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int oddNumber = findOddOccurrence(arr, n);
    printf("The number occurring an odd number of times is: %d\n", oddNumber);
}