#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Function to perform depth-first search and find all paths
void dfs(int graph[MAX_NODES][MAX_NODES], int node, int n, int* visited, int* path, int pathLength, int** paths, int* numPaths) {
    visited[node] = 1;
    path[pathLength] = node;
    pathLength++;

    if (node == n - 1) {
        // Found a path from 0 to n-1
        paths[*numPaths] = (int*)malloc(pathLength * sizeof(int));
        for (int i = 0; i < pathLength; i++) 
        {
            paths[*numPaths][i] = path[i];
        }
        (*numPaths)++;
    }
     else {
        // Explore all adjacent nodes
        for (int i = 0; i < graph[node][0]; i++)
         {
            int adjacentNode = graph[node][i + 1];
            if (!visited[adjacentNode])
             {
                dfs(graph, adjacentNode, n, visited, path, pathLength, paths, numPaths);
            }
        }
    }

    // Backtrack
    visited[node] = 0;
    pathLength--;
}

// Function to find all paths in the graph
int** findPaths(int graph[MAX_NODES][MAX_NODES], int n, int* numPaths) {
    int visited[MAX_NODES] = {0};
    int path[MAX_NODES];
    int** paths = (int**)malloc(MAX_NODES * sizeof(int*));
    *numPaths = 0;

    dfs(graph, 0, n, visited, path, 0, paths, numPaths);

    return paths;
}

// Function to free the memory allocated for paths
void freePaths(int** paths, int numPaths) 
{
    for (int i = 0; i < numPaths; i++)
     {
        free(paths[i]);
    }
    free(paths);
}

int main()
 {
    int graph[MAX_NODES][MAX_NODES] = {{1, 2}, {3}, {3}, {}};
    int n = 4;
    int numPaths;

    int** paths = findPaths(graph, n, &numPaths);

    printf("Output:\n");
    for (int i = 0; i < numPaths; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d", paths[i][j]);
            if (j != n - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }

    freePaths(paths, numPaths);

    return 0;
}