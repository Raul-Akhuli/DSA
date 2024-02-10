#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    int leftThread;
    int rightThread;
}Node;

// Function to create a new node
Node* createNode(int data) {
    Node* nw = (Node*)malloc(sizeof(Node));
    nw->data = data;
    nw->left = nw->right = NULL;
    nw->leftThread = nw->rightThread = 0; // Initially, not threaded
    return nw;
}

// Function to perform an inorder traversal using threads
void threadedInorderTraversal(Node* root) {
    Node* current = leftMost(root);

    while (current != NULL) {
        printf("%d ", current->data);

        // If the right child is not threaded, move to the right child
        if (!current->rightThread) {
            current = leftMost(current->right);
        } else { // If right child is threaded, move to the threaded successor
            current = current->right;
        }
    }
}

// Function to find the leftmost node in the tree rooted at a given node
Node* leftMost(Node* node) {
    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to insert a node into the threaded binary tree
Node* insertNode(Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL)
        return createNode(data);
    Node* current = root;
    Node* parent = NULL;

    // Find the position to insert the new node
    while (current != NULL) {
        parent = current;

        // Move to the left subtree
        if (data < current->data) {
            if (!current->leftThread) {
                current = current->left;
            } else {
                break; // Found the position to insert
            }
        } else if (data > current->data) { // Move to the right subtree
            if (!current->rightThread) {
                current = current->right;
            } else {
                break; // Found the position to insert
            }
        } else {
            // Duplicate data is not allowed in a BST
            return root;
        }
    }

    // Create the new node
    Node* nw = createNode(data);

    // Insert the new node
    if (data < parent->data) {
        nw->left = parent->left;
        nw->right = parent;
        parent->leftThread = 0; // Set left thread to 0
        parent->left = nw;
    } else {
        nw->left = parent;
        nw->right = parent->right;
        parent->rightThread = 0; // Set right thread to 0
        parent->right = nw;
    }

    return root;
}

void main() {
    Node* root = NULL;
    int n, data;

    // Input the size of the threaded binary tree
    printf("Enter the size of the threaded binary tree: ");
    scanf("%d", &n);

    // Input the threaded binary tree elements
    printf("Enter the threaded binary tree elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Perform threaded inorder traversal
    printf("Threaded Inorder Traversal: ");
    threadedInorderTraversal(root);
    printf("\n");
}