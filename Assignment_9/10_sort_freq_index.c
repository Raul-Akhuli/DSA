    #include <stdio.h>
#include <stdlib.h>

// Structure to store freq and index information
typedef struct Element {
    int value;
    int freq;
    int index;
}ele;

// Helper function to compare two elements for sorting
int compareElements(const void *a, const void *b) {
    ele *eleA = (ele *)a;
    ele *eleB = (ele *)b;

    // If frequencies are different, sort by freq in descending order
    if (eleA->freq != eleB->freq) {
        return eleB->freq - eleA->freq;
    }

    // If frequencies are the same, sort by index in ascending order
    return eleA->index - eleB->index;
}

// Function to sort elements by freq and index
void sortByFrequencyAndIndex(int arr[], int size) {
    // Create an array of elements to store freq and index information
    ele *elements = (ele *)malloc(size * sizeof(ele));

    int *hashTable = (int *)calloc(size, sizeof(int));

    // Initialize elements array and hash table
    for (int i = 0; i < size; i++) {
        elements[i].value = arr[i];
        elements[i].freq = 0;
        elements[i].index = i;
    }

    for (int i = 0; i < size; i++) {
        elements[i].freq = ++hashTable[arr[i]];
    }
    qsort(elements, size, sizeof(ele), compareElements);

    // Print the sorted elements
    printf("Sorted elements by freq and index:\n");
    for (int i = 0; i < size; i++)
        for (int j = 0; j < elements[i].freq; j++)
            printf("%d ", elements[i].value);
    printf("\n");
    free(elements);
    free(hashTable);
}

void main() {
    int arr[] = {4, 2, 6, 1, 3, 1, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortByFrequencyAndIndex(arr, size);
}