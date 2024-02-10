#include <stdio.h>

void main()
{
    int arr1[100], arr2[100], arr3[200];
    int M, N, X;
    int i, j, k;	
	printf("Input the number of elements to be stored in the first array :");
    scanf("%d",&M);
    printf("Input %d elements in the array :\n",M);
    for(i=0;i<M;i++)
	    scanf("%d",&arr1[i]);


    printf("Input the number of elements to be stored in the second array :");
    scanf("%d",&N);
    printf("Input %d elements in the array :\n",N);
    for(i=0;i<N;i++)
	    scanf("%d",&arr2[i]);

    X = M + N;

    for(i=0;i<M; i++)
        arr3[i] = arr1[i];

    for(j=0;j<N; j++){
        arr3[i] = arr2[j];
        i++; 
    }
    for(i=0;i<X; i++)
        for(k=0;k<X-1;k++)
            if(arr3[k]>=arr3[k+1]){
                j=arr3[k+1];
                arr3[k+1]=arr3[k];
                arr3[k]=j;
            }              

    printf("\nThe merged array is :\n");
    for(i=0; i<X; i++)
        printf("%d   ", arr3[i]);
}