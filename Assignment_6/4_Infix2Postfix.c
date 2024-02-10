#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node* next;
} Node;

Node* top = NULL;
int MAX = 100;

void push(char x) {
    Node* nw;
    nw = (Node*)malloc(sizeof(Node));
    nw->data = x;
    nw->next = NULL;
    if (top == NULL)
        top = nw;
    else {
        nw->next = top;
        top = nw;
    }
}

char pop() {
    Node* p = top;
    top = top->next;
    char s = p->data;
    free(p);
    return s;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infix2postfix(char infix[], char postfix[]) {
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j++] = infix[i];
        }
        else if (isOperator(infix[i])) {
            while (top != NULL && precedence(top->data) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (top != NULL && top->data != '(') {
                postfix[j++] = pop();
            }
            if (top != NULL && top->data == '(') {
                pop();
            }
        }
    }

    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter the equation: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0';
    infix2postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}