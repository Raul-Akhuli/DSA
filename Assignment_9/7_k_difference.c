#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to find pairs with difference k in an array
void findPairsWithDifferenceK(int arr[], int size, int k) {
    // Create a hash table to store the elements of the array
    int* hashTable = (int*)calloc(size, sizeof(int));
    // Traverse the array
    for (int i = 0; i < size; i++) {
        // Check if arr[i] - k exists in the hash table
        if (arr[i] - k >= 0 && hashTable[arr[i] - k])
            printf("Pair found: (%d, %d)\n", arr[i] - k, arr[i]);

        // Check if arr[i] + k exists in the hash table
        if (arr[i] + k < size && hashTable[arr[i] + k])
            printf("Pair found: (%d, %d)\n", arr[i], arr[i] + k);

        hashTable[arr[i]] = 1;
    }
    free(hashTable);
}

void main() {
    int arr[] = {1, 5, 3, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    findPairsWithDifferenceK(arr, size, k);
}