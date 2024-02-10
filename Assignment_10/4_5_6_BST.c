#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
}Node;

// Function to create a new node
Node* createNode(int data) {
    Node* nw = (Node*)malloc(sizeof(Node));
    nw->data = data;
    nw->left = nw->right = NULL;
    return nw;
}

// Function to insert a node into the binary search tree
Node* insertNode(Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to perform an inorder traversal and print the values
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to create the mirror image of a binary search tree
Node* mirrorBST(Node* root) {
    if (root == NULL)
        return NULL;

    // Swap the left and right children of each node
    Node* temp = root->left;
    root->left = mirrorBST(root->right);
    root->right = mirrorBST(temp);

    return root;
}

void main() {
    Node* root = NULL;
    int value;

    // Insert nodes into the binary search tree based on user input
    // printf("Enter the values to insert into the BST (-1 to stop):\n");

    // while (1) {
    //     printf("Enter a value: ");
    //     scanf("%d", &value);

    //     if (value == -1)
    //         break;

    //     root = insertNode(root, value);
    // }

    //Insert nodes into the binary search tree via array
    int arr[] = {21,9,45,37,10,34};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i) {
        root = insertNode(root, arr[i]);
    }

    printf("\nOriginal BST Inorder Traversal: ");
    inorderTraversal(root);

    // Create the mirror image of the BST
    Node* mirroredRoot = mirrorBST(root);

    printf("\nMirrored BST Inorder Traversal: ");
    inorderTraversal(mirroredRoot);
}