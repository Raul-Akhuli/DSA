#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
typedef struct node {
    int data;
    struct node* next;
}Node;

// Structure to represent the adjacency list
typedef struct adjList {
    Node* head;
}AdjList;

// Function to create a new node
Node* createNode(int data) {
    Node* nw = (Node*)malloc(sizeof(Node));
    nw->data = data;
    nw->next = NULL;
    return nw;
}

// Function to create an adjacency list for a graph
AdjList* createGraph(int vertices) {
    AdjList* graph = (AdjList*)malloc(vertices * sizeof(AdjList));

    for (int i = 0; i < vertices; ++i) {
        graph[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(AdjList* graph, int src, int dest) {
    // Add an edge from src to dest
    Node* nw = createNode(dest);
    nw->next = graph[src].head;
    graph[src].head = nw;

    // Add an edge from dest to src
    nw = createNode(src);
    nw->next = graph[dest].head;
    graph[dest].head = nw;
}

// Function to print the adjacency list of the graph
void printAdjList(AdjList* graph, int vertices) {
    for (int i = 0; i < vertices; ++i) {
        Node* current = graph[i].head;

        printf("Adjacency list of vertex %d: ", i);

        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
    }
}

void main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    AdjList* graph = createGraph(vertices);

    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printAdjList(graph, vertices);
}