#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAX_VERTICES 100

int findMinDistanceVertex(int dist[], bool sptSet[], int vertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (sptSet[v] == false && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printShortestDistance(int dist[], int vertices, int source) {
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d \t%d\n", i, dist[i]);
    }
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int source) {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = findMinDistanceVertex(dist, sptSet, vertices);

        sptSet[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printShortestDistance(dist, vertices, source);
}

int main() {
    int vertices = 5;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 4, 0, 0, 7},
        {4, 0, 2, 5, 0},
        {0, 2, 0, 1, 0},
        {0, 5, 1, 0, 3},
        {7, 0, 0, 3, 0}
    };

    int source = 0;
    printf("Shortest Distances from Source Vertex %d:\n", source);
    dijkstra(graph, vertices, source);

    return 0;
}
