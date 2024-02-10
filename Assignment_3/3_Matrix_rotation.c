#include <stdio.h>

void display(int matrix[][4], int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void main(){
    int m=4,i,j;
    int matrix[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    printf("Original Matrix:\n");
    display(matrix, m, m);

    int new_mat[m][m];
    int n = 0;
    for(i=m;i>0;i--){
        for(j=0;j<m;j++)
            new_mat[j][i - 1] = matrix[n][j];
        n++;
    }

    printf("New matrix:\n");
    display(new_mat, m, m);
}