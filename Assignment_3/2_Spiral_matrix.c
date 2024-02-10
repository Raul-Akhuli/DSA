#include <stdio.h>

void main()
{
    int n = 4, count = 1;
    int matrix[n][n];
    int start = 0, i = 0;
    for (int x = 0; x < n - 1; x++){
        while (start < n-x){
            while (i < n-x){
                matrix[start][i] = count;
                count++;
                i++;
            }
            start++;
            if (start < n-x){
                matrix[start][i - 1] = count;
                count++;
            }
        }
        start--;
        i--;
        while (start > x){
            while (i > x){
                matrix[start][i - 1] = count;
                count++;
                i--;
            }
            start--;
            if (start > x){
                matrix[start][i] = count;
                count++;
            }
        }
        start++;
        i++;
    }

    printf("The matrix:\n");
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++)
            printf("%d ", matrix[x][y]);
        printf("\n");
    }
}