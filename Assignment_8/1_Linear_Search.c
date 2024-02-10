#include <stdio.h>

int linearSearch(int arr[], int n, int ele) {
    for (int i = 0; i < n; i++)
        if (arr[i] == ele)
            return i; 
    return -1; 
}

void main() {
    int arr[] = {12, 45, 67, 89, 34, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the element to be searched: ");
    scanf("%d",&target);

    int result = linearSearch(arr, n, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array\n");
}