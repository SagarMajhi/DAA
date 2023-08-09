#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    int front, rear;
    int size;
    int capacity;
    int* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

int isQueueFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

void enqueue(struct Queue* queue, int item) {
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

void BFS(int startVertex, struct Node* adjacencyList[]) {
    struct Queue* queue = createQueue(MAX_VERTICES);
    int visited[MAX_VERTICES] = {0};

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        struct Node* temp = adjacencyList[currentVertex];
        while (temp != NULL) {
            int neighbor = temp->data;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(queue, neighbor);
            }
            temp = temp->next;
        }
    }

    free(queue);
}

void addEdge(struct Node* adjacencyList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

int main() {
    struct Node* adjacencyList[MAX_VERTICES] = {NULL};

    addEdge(adjacencyList, 0, 1);
    addEdge(adjacencyList, 0, 2);
    addEdge(adjacencyList, 1, 2);
    addEdge(adjacencyList, 2, 3);
    addEdge(adjacencyList, 3, 3);

    int startVertex = 0;
    printf("BFS traversal starting from vertex %d: ", startVertex);
    BFS(startVertex, adjacencyList);
    printf("\n");

    return 0;
}
