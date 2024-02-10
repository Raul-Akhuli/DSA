#include <stdio.h>

typedef struct student {
    int weight;
    int height;
}Student;

void main(){
    int N;
    double Max=0;
    printf("Enter the number of students: ");
    scanf("%d",&N);
    Student stud[N];

    for(int i=0;i<N;i++){
        printf("Enter the details of student %d:\n",i+1);
        printf("Weight: ");
        scanf("%d",&stud[i].weight);
        printf("Height: ");
        scanf("%d",&stud[i].height);
    }

    for(int i=0;i<N;i++)
        if((double)stud[i].weight/stud[i].height>Max)
            Max = (double)stud[i].weight/stud[i].height;

    printf("Maximum weight/height ratio is %0.2f",Max);
}