#include <stdio.h>
#include <stdlib.h>

// Function to print all subarrays with zero sum
void printAllSubarraysWithZeroSum(int arr[], int size) {
    // Create a hash table to store the cumulative sum and its corresponding indices
    int* hashTable = (int*)malloc((size + 1) * sizeof(int));
    for (int i = 0; i <= size; i++)
        hashTable[i] = -1;

    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
        // Check if the current sum is in the hash table
        if (hashTable[sum] != -1) {
            // Print the subarray with zero sum
            for (int j = hashTable[sum] + 1; j <= i; j++)
                printf("%d ", arr[j]);
            printf("\n");
        } else if (sum == 0) {
            // If the sum is 0, print the subarray from the beginning to the current index
            for (int j = 0; j <= i; j++)
                printf("%d ", arr[j]); 
            printf("\n");
        }
        hashTable[sum] = i;
    }
    free(hashTable);
}

void main() {
    int arr[] = {4, 2, -3, 1, 6, -1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Subarrays with zero sum:\n");
    printAllSubarraysWithZeroSum(arr, size);
}