#include <stdio.h>
void main()
{
    int array[100];
    int i, n, max1=0, max2=0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements \n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    for(i=0; i<n; i++) {
        if(array[i] > max1){
            max2 = max1;
            max1 = array[i];
        } else if(array[i] > max2 && array[i] < max1) {
            max2 = array[i];
        }
    }

    printf("Second largest = %d", max2);
}