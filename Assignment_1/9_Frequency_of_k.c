#include <stdio.h>

void main()
{
    int n, k, count = 0;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n], temp[n];
    printf("Enter elements in the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter K: ");
    scanf("%d",&k);

    for(int i=0;i<n;i++)
        if (arr[i]==k)
            count++;

    printf("Frequency of element k %d in array is %d",k,count);
}