#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 4

int min(int a, int b) {
    return (a < b) ? a : b;
}

int calculateCost(int graph[][V], int u, int v) {
    return graph[u][v];
}

int tspBruteForce(int graph[][V], int visited[], int currentCity, int nVisited, int cost, int minCost) {
    if (nVisited == V) {
        cost += calculateCost(graph, currentCity, 0);
        return min(cost, minCost);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            minCost = tspBruteForce(graph, visited, i, nVisited + 1, cost + calculateCost(graph, currentCity, i), minCost);
            visited[i] = 0;
        }
    }

    return minCost;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;

    int minCost = INT_MAX;
    minCost = tspBruteForce(graph, visited, 0, 1, 0, minCost);

    printf("Minimum cost of TSP: %d\n", minCost);

    return 0;
}
