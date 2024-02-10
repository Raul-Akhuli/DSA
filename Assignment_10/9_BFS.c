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

// Structure to represent a queue node for BFS
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Structure to represent a queue
struct Queue {
    struct QueueNode *front, *rear;
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

// Function to create a new node for the queue
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue a node in the queue
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* newNode = createQueueNode(data);

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue a node from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1; // Indicates an empty queue
    }

    struct QueueNode* temp = queue->front;
    int data = temp->data;

    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

// Function to perform Breadth-First Search on the graph
void BFS(struct AdjList* graph, int vertices, int startVertex) {
    // Create a boolean array to track visited vertices
    bool* visited = (bool*)malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; ++i) {
        visited[i] = false;
    }

    // Create a queue for BFS
    struct Queue* queue = createQueue();

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(queue, startVertex);

    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Explore all adjacent vertices of the dequeued vertex
        struct Node* temp = graph[currentVertex].head;
        while (temp != NULL) {
            int adjacentVertex = temp->data;

            // If the adjacent vertex is not visited, mark it as visited and enqueue it
            if (!visited[adjacentVertex]) {
                visited[adjacentVertex] = true;
                enqueue(queue, adjacentVertex);
            }

            temp = temp->next;
        }
    }

    printf("\n");

    // Free dynamically allocated memory
    free(visited);
    free(queue);
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

    // Input the starting vertex for BFS
    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS on the graph
    BFS(graph, vertices, startVertex);

    // Free dynamically allocated memory
    free(graph);

    return 0;
}