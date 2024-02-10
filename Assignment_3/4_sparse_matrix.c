#include <stdio.h>

void main(){
    int m,n,i,j,count=0;
    printf("Enter number of rows: ");
    scanf("%d",&m);
    printf("Enter number of columns: ");
    scanf("%d",&n);

    int matrix[m][n];
    printf("Enter the values of matrix:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&matrix[i][j]);

    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(matrix[i][j]==0)
                count++;
    if(count>(m*n)/2)
        printf("It is a sparse matrix");
    else
        printf("It is not a sparse matrix");
}