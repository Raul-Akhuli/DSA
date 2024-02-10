#include <stdio.h>

void display(int matrix[][4], int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void main(){
    int r1,r2;
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    printf("Original Matrix:\n");
    display(matrix, 4, 4);

    printf("Enter the rows you want to interchange:\n");
    scanf("%d",&r1);
    scanf("%d",&r2);

    int temp[4];
    for (int i = 0; i < 4; i++){
        temp[i] = matrix[r1 - 1][i];
        matrix[r1 -1][i] = matrix[r2 -1][i];
        matrix[r2 -1][i] = temp[i];
    }
    
    printf("New Matrix:\n");
    display(matrix, 4, 4);
}