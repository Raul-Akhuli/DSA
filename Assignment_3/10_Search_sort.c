#include <stdio.h>
#include <string.h>

#define MAX 100

void searchStrings(char arr[][MAX], int n){
    char w[MAX];
    printf("Enter a word to be searched: ");
    scanf("%s",w);
    int found = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++) 
            if (strcmp(arr[j], w) > 0){
                found = 1;
                break;
            }
    if(found)
        printf("The word is in the list\n");
    else
        printf("Word not in list\n");
}

void sortStrings(char arr[][MAX], int n){
    char temp[MAX];
 
    // Sorting strings using bubble sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++) 
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
}

void main()
{
    char arr[][MAX] = { "Hello", "World", "Apple", "Fish", "Bird" };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    searchStrings(arr, n);
    sortStrings(arr, n);

    printf("Strings in sorted order are : ");
    for (int i = 0; i < n; i++)
        printf("%s, ",arr[i]);
}