#include <stdio.h>

int binarySearch(int arr[], int left, int right, int ele) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == ele)
            return mid; 
        if (arr[mid] < ele)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void main() {
    int arr[] = {12, 34, 45, 56, 67, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the element to be searched: ");
    scanf("%d",&target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array\n");
}