#include <stdio.h>
void main()
{
    int array[100];
    int i, n, x, found, pos;

    printf("Enter the number of elements in the array \n");
    scanf("%d", &n);

    printf("Enter the elements \n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("Input array elements are: \n");
    for (i = 0; i < n; i++)
        printf("%d ", array[i]);

    printf("\nEnter the element to be deleted: ");
    scanf("%d", &x);

    for (i = 0; i < n; i++)
        if (array[i] == x){
            found = 1;
            pos = i;
            break;
        }
 
    if (found == 1) {
        for (i = pos; i <  n - 1; i++)
            array[i] = array[i + 1];
 
        printf("The array after deleting the element is: \n");
        for (i = 0; i < n - 1; i++)
            printf("%d ", array[i]); 
    } else
    printf("Element %d is not found in the array\n", x);
}