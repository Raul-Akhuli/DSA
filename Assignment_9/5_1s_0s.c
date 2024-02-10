#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum length subarray with an equal number of 0's and 1's
void findMaxLengthSubarray(int arr[], int size) {
    // Create a hash table to store the cumulative sum and its corresponding indices
    int* hashTable = (int*)malloc((size * 2 + 1) * sizeof(int));
    for (int i = 0; i <= size * 2; i++)
        hashTable[i] = -1;

    int sum = 0;
    int maxLength = 0;
    int endIndex = -1;

    for (int i = 0; i < size; i++) {
        // Convert 0 to -1 to handle the cumulative sum
        sum += (arr[i] == 0) ? -1 : 1;
        if (sum == 0) {
            // Update the maximum length and ending index
            maxLength = i + 1;
            endIndex = i;
        }

        if (hashTable[sum + size] != -1) {
            // If the current sum has been seen before, update the maximum length and ending index
            if (i - hashTable[sum + size] > maxLength) {
                maxLength = i - hashTable[sum + size];
                endIndex = i;
            }
        } else
            // Store the current sum and its index in the hash table
            hashTable[sum + size] = i;
    }

    // Print the maximum length subarray
    if (endIndex != -1) {
        printf("Maximum length subarray with equal 0's and 1's is: [");
        for (int i = endIndex - maxLength + 1; i <= endIndex; i++)
            printf("%d ", arr[i]);
        printf("]\n");
    } else
        printf("No subarray found with an equal number of 0's and 1's\n");
    free(hashTable);
}

void main() {
    int arr[] = {0, 1, 0, 1, 1, 1, 0, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    findMaxLengthSubarray(arr, size);
}