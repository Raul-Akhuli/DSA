#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int item;
    struct node *next;
}Node;

int createNode(){
    int data;
    printf("Enter Node data: ");
    scanf("%d",&data);
    return data;
}

Node * createList();
void displayList(Node *);
void insertAtLast(Node *,int);
Node * insertAtFirst(Node *,int);
Node * insertAtAny(Node *,int,int);
void deleteFromLast(Node *);
Node * deleteFromFirst(Node *);
Node * deleteFromAny(Node *,int);

void main(){
    int choice,ch,pos,data;
    Node * head = NULL;
    head = createList();
    displayList(head);
    printf("What do you want to do?\n1.Insertion\n2.Deletion\n3.Exit\n");
    scanf("%d",&choice);
    while(choice==1 || choice==2){
        if(choice==1){
            printf("\n1. Insertion at end\n2. Insertion at start\n3. Insertion at any point\nChoose 1,2,3: ");
            scanf("%d",&ch);
            switch (ch){
            case 1:
                data = createNode();
                insertAtLast(head, data);
                break;
            case 2:
                data = createNode();
                head = insertAtFirst(head, data);
                break;
            case 3:
                data = createNode();
                printf("Enter the position from where you want to insert the node: ");
                scanf("%d",&pos);
                head = insertAtAny(head, data, pos);
                break;
            default:
                break;
            }
        } else {
            printf("\n1. Deletion at end\n2. Deletion at start\n3. Deletion at any point\nChoose 1,2,3:");
            scanf("%d",&ch);
            switch (ch){
            case 1:
                deleteFromLast(head);
                break;
            case 2:
                head = deleteFromFirst(head);
                break;
            case 3:
                printf("Enter the position from where you want to delete the node: ");
                scanf("%d",&pos);
                head = deleteFromAny(head, pos);
                break;
            default:
                break;
            }
        }
        displayList(head);
        printf("What do you want to do?\n1.Insertion\n2.Deletion\n3.Exit\n");
        scanf("%d",&choice);
    }
}

Node * createList(){
    Node *h, *nw, *last;
    int choice;
    h = NULL;
    do{
        nw = (Node*)malloc(sizeof(Node));
        nw->item = createNode();
        nw->next = NULL;

        if(h==NULL)
            h = last = nw;
        else{
            last->next = nw;
            last = nw;
        }
        printf("Do you want to add another node?(1/0): ");
        scanf("%d",&choice);
    } while (choice!=0);
    return h;
}

void displayList(Node *h){
    printf("\nLinked List: head-->");
    while(h!=NULL){
        printf("%d-->",h->item);
        h=h->next;
    }
    printf("NULL\n\n");
}

void insertAtLast(Node *h,int data){
    Node * nw;
    nw = (Node*)malloc(sizeof(Node));
    nw->item = data;
    nw->next = NULL;

    while(h->next!=NULL)
        h = h->next;
    h->next = nw;
}

Node * insertAtFirst(Node *h, int data){
    Node * nw;
    nw = (Node*)malloc(sizeof(Node));
    nw->item = data;
    nw->next = h;
    h = nw;
    return h;
}

Node * insertAtAny(Node *h, int data, int pos){
    Node *nw, *last, *prev;
    nw = (Node*)malloc(sizeof(Node));
    nw->item = data;
    int count = 1;
    if(pos==1)
        h = insertAtFirst(h,data);
    else{
        last = h;
        while(count<pos && last!=NULL){
            count++;
            prev = last;
            last = last->next;
        }
        if(last!=NULL){
            nw->next = last;
            prev->next = nw;
        } else
            printf("Invalid Position");
    }

    return h;
}

void deleteFromLast(Node *h){
    Node *prev, *last;
    last = h;
    prev = last;
    while(last->next!=NULL){
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    free(last);
}

Node * deleteFromFirst(Node *h){
    Node * prev = h;
    h = h->next;
    free(prev);
    return h;
}

Node * deleteFromAny(Node *h, int pos){
    int count = 1;
    Node * prev, * last;
    if(pos==1 && h!=NULL)
        h = deleteFromFirst(h);
    else {
        last = h;
        while(count<pos && last!=NULL){
            count++;
            prev = last;
            last = last->next;
        }
        if(last!=NULL){
            prev->next = last->next;
            free(last);
        } else
            printf("Invalid Position");
    }

    return h;
}