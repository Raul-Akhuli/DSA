#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a node in the binary tree
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

// Function to insert a node into the binary tree
Node* insertNode(Node* root, int data, char position) {
    if (root == NULL)
        return createNode(data);

    if (position == 'L')
        root->left = insertNode(root->left, data, position);
    else if (position == 'R')
        root->right = insertNode(root->right, data, position);
    else
        printf("Invalid position. Use 'L' for left or 'R' for right.\n");

    return root;
}

// Function to print the inorder traversal of the binary tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
// Function to print the preorder traversal of the binary tree
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to print the postorder traversal of the binary tree
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to check if the binary tree is full
bool isFullTree(Node* root) {
    // An empty tree is considered full
    if (root == NULL) {
        return true;
    }

    // If a node has one child but not both, the tree is not full
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL)) {
        return false;
    }

    // Recursively check the left and right subtrees
    return isFullTree(root->left) && isFullTree(root->right);
}

int main() {
    Node* root = NULL;
    int value;
    char position;

    // Insert nodes into the binary tree based on user input
    printf("Enter the root value: ");
    scanf("%d", &value);
    root = createNode(value);

    while (1) {
        printf("Enter the value to insert (-1 to stop): ");
        scanf("%d", &value);
        if (value == -1)
            break;
        printf("Enter the position (L for left, R for right): ");
        scanf(" %c", &position);

        root = insertNode(root, value, position);
    }

    // Print the inorder traversal of the binary tree
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    // Print the preorder traversal of the binary tree
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);

    // Print the postorder traversal of the binary tree
    printf("\nPostorder Traversal: ");
    postorderTraversal(root);

    // Check if the binary tree is full
    if (isFullTree(root)) {
        printf("\nThe binary tree is full.\n");
    } else {
        printf("\nThe binary tree is not full.\n");
    }
    
    return 0;
}