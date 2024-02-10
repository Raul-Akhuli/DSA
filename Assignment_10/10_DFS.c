#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an adjacency list for a graph
struct AdjList* createGraph(int vertices) {
    struct AdjList* graph = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));

    for (int i = 0; i < vertices; ++i) {
        graph[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct AdjList* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph[src].head;
    graph[src].head = newNode;

    // Add an edge from dest to src
    newNode = createNode(src);
    newNode->next = graph[dest].head;
    graph[dest].head = newNode;
}

// Function to perform Depth-First Search on the graph
void DFS(struct AdjList* graph, int vertex, bool* visited) {
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Print the current vertex
    printf("%d ", vertex);

    // Traverse all adjacent vertices
    struct Node* temp = graph[vertex].head;
    while (temp != NULL) {
        int adjacentVertex = temp->data;

        // If the adjacent vertex is not visited, recursively call DFS on it
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }

        temp = temp->next;
    }
}

int main() {
    int vertices, edges;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create the graph
    struct AdjList* graph = createGraph(vertices);

    // Input the edges
    printf("Enter the edges (format: source destination):\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Create an array to track visited vertices
    bool* visited = (bool*)malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; ++i) {
        visited[i] = false;
    }

    // Input the starting vertex for DFS
    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Perform DFS on the graph
    printf("Depth-First Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex, visited);

    // Free dynamically allocated memory
    free(graph);
    free(visited);

    return 0;
}