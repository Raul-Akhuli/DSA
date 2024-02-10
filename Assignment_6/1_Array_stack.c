#include <stdio.h>

int stack[100], choice, n, top, x, i;

void push() {
    if (top >= n - 1)
        printf("\nSTACK overflow");
    else{
        printf(" Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop(){
    if (top <= -1)
        printf("\n Stack is Empty");
    else{
        printf("\n The popped element is %d", stack[top]);
        top--;
    }
}

void peek(){
    if (top <= -1)
        printf("\n The STACK is empty");
    else
        printf("\n The top element is %d", stack[top]);
}

void display(){
    if (top >= 0){
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n");
    }
    else
        printf("\n The STACK is empty");
}

void main(){
    top = -1;
    printf("\n Enter the size of STACK[MAX=100]:");
    scanf("%d", &n);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.PEEK\n 5.EXIT");
    do{
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            break;
        default:
            printf("\n Please Enter a Valid Choice(1/2/3/4/5)");
            break;
        }
    } while (choice != 5);
}