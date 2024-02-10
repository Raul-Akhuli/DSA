#include <stdio.h>

void main(){
    int n;
    printf("Enter the number of rows required: ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        
        for(int j=1;j<=i;j++){
            printf("%c ",64+i);
        }
        printf("\n");
    }
}