#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adjacencyList[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

void DFSUtil(int vertex, int visited[], struct Node* adjacencyList[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = adjacencyList[vertex];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited, adjacencyList);
        }
        temp = temp->next;
    }
}

void DFS(int startVertex, struct Node* adjacencyList[]) {
    int visited[MAX_VERTICES] = {0};
    DFSUtil(startVertex, visited, adjacencyList);
}

int main() {
    struct Node* adjacencyList[MAX_VERTICES] = {NULL};

    addEdge(adjacencyList, 0, 1);
    addEdge(adjacencyList, 0, 2);
    addEdge(adjacencyList, 1, 2);
    addEdge(adjacencyList, 2, 3);
    addEdge(adjacencyList, 3, 3);

    int startVertex = 0;
    printf("DFS traversal starting from vertex %d: ", startVertex);
    DFS(startVertex, adjacencyList);
    printf("\n");

    return 0;
}
