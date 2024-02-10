#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node * createList() {
    Node *h, *nw, *last;
    h = NULL;
    int n;
    printf("Enter size of the linked list: ");
    scanf("%d",&n);
    printf("Enter node data:\n");
    for(int i=0;i<n;i++){
        nw = (Node*)malloc(sizeof(Node));
        scanf("%d",&nw->data);
        nw->next = NULL;
        if(h==NULL)
            h = last = nw;
        else{
            last->next = nw;
            last = nw;
        }
    }
    return h;
}

Node *merge_sorted_lists(Node *list1, Node *list2) {
    Node *merged = NULL;
    Node *current = NULL;

    while (list1 != NULL && list2 != NULL) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->next = NULL;
        if (list1->data < list2->data) {
            new_node->data = list1->data;
            list1 = list1->next;
        } else {
            new_node->data = list2->data;
            list2 = list2->next;
        }
        if (merged == NULL)
            merged = current = new_node;
        else {
            current->next = new_node;
            current = new_node;
        }
    }
    if (list1 != NULL) {
        if (merged == NULL)
            merged = list1;
        else
            current->next = list1;
    }
    if (list2 != NULL) {
        if (merged == NULL)
            merged = list2;
        else
            current->next = list2;
    }
    return merged;
}

void display_list(Node *head) {
    while (head != NULL) {
        printf("%d-->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void main() {
    Node *list1 = NULL;
    Node *list2 = NULL;
    list1 = createList();
    list2 = createList();
    printf("List 1: ");
    display_list(list1);
    printf("List 2: ");
    display_list(list2);

    Node *merged = merge_sorted_lists(list1, list2);

    printf("Merged List: ");
    display_list(merged);
}