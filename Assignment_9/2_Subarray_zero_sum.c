#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

// Function to check if a subarray with 0 sum exists using hashing
bool hasZeroSumSubarray(int arr[], int size) {
    int prefixSum = 0;
    int hashTable[MAX] = {0};

    for (int i = 0; i < size; i++) {
        prefixSum += arr[i];

        // Check if the current prefix sum has been seen before
        if (hashTable[prefixSum] != 0 || prefixSum == 0) {
            return true;
        }

        hashTable[prefixSum] = 1;
    }

    return false;
}

void main() {
    int arr[] = {4, 2, -3, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (hasZeroSumSubarray(arr, size))
        printf("Subarray with 0 sum exists.\n");
    else
        printf("Subarray with 0 sum does not exist.\n");
}