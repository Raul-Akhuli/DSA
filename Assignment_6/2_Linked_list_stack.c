#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node * top = NULL;

void push(int x){
    Node * nw;
    nw = (Node*)malloc(sizeof(Node));
    nw->data = x;
    nw->next = NULL;
    if(top == NULL)
        top = nw;
    else{
        nw->next=top;
        top = nw;
    }
}

void pop(){
    if(top==NULL)
        printf("Stack Underflow");
    else{
        Node * p = top;
        top=top->next;
        printf("Popped element %d",p->data);
        free(p);
    }
}

void peek(){
    if(top==NULL)
        printf("Stack Empty");
    else
        printf("Top -> %d",top->data);
}

void display(){
    Node * p = top;
    if(top==NULL)
        printf("Stack Empty");
    else{
        printf("Top-->");
        while(p!=NULL){
            printf("%d-->",p->data);
            p=p->next;
        }
        printf("End");
    }
}

void main(){
    int choice,data;
    printf("\n STACK OPERATIONS");
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.PEEK\n 5.EXIT");
    do{
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter the data for stack: ");
            scanf("%d",&data);
            push(data);
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