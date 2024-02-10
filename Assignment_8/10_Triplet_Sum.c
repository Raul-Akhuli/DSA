#include <stdio.h>
#include <stdlib.h>

void findTriplets(int arr[], int n, int K) {
    int i, j, k;
    int found = 0;

    for (i = 0; i < n - 2; i++)
        for (j = i + 1; j < n - 1; j++)
            for (k = j + 1; k < n; k++)
                if (arr[i] + arr[j] + arr[k] == K) {
                    printf("Triplets with sum %d: %d, %d, %d\n", K, arr[i], arr[j], arr[k]);
                    found = 1;
                }
    if (!found)
        printf("No triplets found with sum %d\n", K);
}

void main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 15;
    findTriplets(arr, n, K);
}