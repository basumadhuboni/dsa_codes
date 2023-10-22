#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to perform depth-first search and find the depth of a given node
void dfsDepth(int graph[MAX_NODES][MAX_NODES], int node, int parent, int depth, int target, int* found, int* result) {
    if (*found) {
        return;
    }

    if (node == target) {
        *found = 1;
        *result = depth;
        return;
    }

    for (int i = 0; i < graph[node][0]; i++) {
        int adjacentNode = graph[node][i + 1];
        if (adjacentNode != parent) {
            dfsDepth(graph, adjacentNode, node, depth + 1, target, found, result);
        }
    }
}

// Function to determine the number of connected components in the graph using breadth-first search
int bfsConnectedComponents(int graph[MAX_NODES][MAX_NODES], int n) {
    int visited[MAX_NODES] = {0};
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            visited[i] = 1;
            int queue[MAX_NODES];
            int front = 0, rear = 0;
            queue[rear++] = i;

            while (front < rear) {
                int node = queue[front++];
                for (int j = 0; j < graph[node][0]; j++) {
                    int adjacentNode = graph[node][j + 1];
                    if (!visited[adjacentNode]) {
                        visited[adjacentNode] = 1;
                        queue[rear++] = adjacentNode;
                    }
                }
            }
        }
    }

    return components;
}

int main() {
    int graph[MAX_NODES][MAX_NODES] = {
        {2, 1, 2},  // Node 0 is connected to nodes 1 and 2
        {1, 0},     // Node 1 is connected to node 0
        {1, 0},     // Node 2 is connected to node 0
        {0}         // Node 3 is not connected to any node
    };
    int n = 4;
    int targetNode = 2;

    int found = 0;
    int depth = 0;
    dfsDepth(graph, 0, -1, 0, targetNode, &found, &depth);

    printf("Depth of node %d: %d\n", targetNode, depth);

    int numComponents = bfsConnectedComponents(graph, n);
    printf("Number of connected components: %d\n", numComponents);

    return 0;
}
