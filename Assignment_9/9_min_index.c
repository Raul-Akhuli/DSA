#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum index of a repeating element in an array
int findMinIndexRepeatingElement(int arr[], int size) {
    // Create a hash table to store the last index of each element
    int* lastIndex = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        lastIndex[i] = -1;
    int minIndex = INT_MAX;

    // Traverse the array from right to left
    for (int i = size - 1; i >= 0; i--) {
        // Check if the element is repeating and update the minimum index
        if (lastIndex[arr[i]] != -1)
            minIndex = i;
        else
            lastIndex[arr[i]] = i;
    }

    free(lastIndex);
    return (minIndex == INT_MAX) ? -1 : minIndex;
}

void main() {
    int arr[] = {4, 2, 6, 1, 3, 1, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findMinIndexRepeatingElement(arr, size);

    if (result != -1)
        printf("Minimum index of a repeating element: %d\n", result);
    else
        printf("No repeating element found\n");
}