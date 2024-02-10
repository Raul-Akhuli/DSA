#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_list() {
    Node *h, *nw, *last;
    h = NULL;
    int n;
    printf("Enter size of the linked list: ");
    scanf("%d", &n);
    printf("Enter node data:\n");
    for (int i = 0; i < n; i++) {
        nw = (Node *)malloc(sizeof(Node));
        scanf("%d", &nw->data);
        nw->next = NULL;
        if (h == NULL)
            h = last = nw;
        else {
            last->next = nw;
            last = nw;
        }
    }
    return h;
}

void create_loop(Node *head, int pos) {
    Node *tail = head;
    Node *loop_node = NULL;

    int count = 1;
    while (tail->next != NULL) {
        if (count == pos) 
            loop_node = tail;
        tail = tail->next;
        count++;
    }

    if (loop_node != NULL) {
        tail->next = loop_node;
        printf("Loop created at position %d\n", pos);
    }
}

int detect_loop(Node *head) {
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

void main() {
    Node *head = NULL;
    head = create_list();
    
    int loop_pos;
    printf("Enter the position to create a loop (0 for no loop): ");
    scanf("%d", &loop_pos);
    
    if (loop_pos != 0) 
        create_loop(head, loop_pos);
    
    if (detect_loop(head))
        printf("Loop detected in the linked list.\n");
    else
        printf("No loop detected in the linked list.\n");
}