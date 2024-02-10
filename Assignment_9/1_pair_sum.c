#include <stdio.h>

#define MAX 10000

// Function to find a pair with the given sum using a hash table
void findPair(int arr[], int size, int targetSum) {
    int hashTable[MAX] = {0}; // Initialize hash table with zeros
    for (int i = 0; i < size; i++) {
        int complement = targetSum - arr[i];

        // Check if the complement is present in the hash table
        if (hashTable[complement] != 0) {
            printf("Pair found: (%d, %d)\n", arr[i], complement);
            return;
        }

        hashTable[arr[i]] = 1;
    }
    printf("Pair not found\n");
}

void main() {
    int arr[] = {4, 2, 8, 5, 1, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 10;

    findPair(arr, size, targetSum);
}