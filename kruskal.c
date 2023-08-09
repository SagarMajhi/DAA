#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int vertices, edges;
    struct Edge* edge;
};

struct Graph* createGraph(int vertices, int edges) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (struct Edge*)malloc(edges * sizeof(struct Edge));
    return graph;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int findParent(int parent[], int vertex) {
    if (parent[vertex] == vertex)
        return vertex;
    return findParent(parent, parent[vertex]);
}

void performUnion(int parent[], int x, int y) {
    int xParent = findParent(parent, x);
    int yParent = findParent(parent, y);
    parent[xParent] = yParent;
}

void kruskalMST(struct Graph* graph) {
    int vertices = graph->vertices;
    struct Edge resultMST[vertices];
    int resultCount = 0;

    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

    int parent[MAX_VERTICES];
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    int edgeCount = 0;

    while (resultCount < vertices - 1) {
        struct Edge nextEdge = graph->edge[edgeCount++];

        int x = findParent(parent, nextEdge.src);
        int y = findParent(parent, nextEdge.dest);

        if (x != y) {
            resultMST[resultCount++] = nextEdge;
            performUnion(parent, x, y);
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 0; i < resultCount; i++) {
        printf("%d - %d \t%d\n", resultMST[i].src, resultMST[i].dest, resultMST[i].weight);
    }
}

int main() {
    int vertices = 5;
    int edges = 7;
    struct Graph* graph = createGraph(vertices, edges);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 2;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 8;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 5;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 7;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 9;

    printf("Minimum Spanning Tree:\n");
    kruskalMST(graph);

    return 0;
}
