#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V)
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to implement Prim's algorithm to find the MST
void prim(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    int parent[V]; // Array to store constructed MST
    int key[V];    // Key values used to pick minimum weight edge
    int mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE, mstSet[] as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that vertex 0 is picked as the first vertex
    parent[0] = -1; // First node is always root of MST

    // Construct the MST
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update the key value and parent index of the adjacent vertices of the picked vertex.
        // Consider only those vertices that are not yet included in MST
        for (int v = 0; v < V; v++)
        {
            // graph[u][v] is non-zero only for adjacent vertices of mstSet[u]
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than the current key of v
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printf("\nMinimum Spanning Tree (MST):\n");
    int mstWeight = 0;
    for (int i = 1; i < V; i++)
    {
        printf("%d -- %d = %d\n", parent[i], i, graph[i][parent[i]]);
        mstWeight += graph[i][parent[i]];
    }
    printf("\nTotal weight of MST: %d\n", mstWeight);
}

int main()
{
    int V, E;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Create a graph with no edges
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    // Input the edges (u, v, weight)
    printf("Enter the edges (u, v, weight):\n");
    printf("Note: Enter edges as 'u v weight'. Enter 0 0 0 to stop.\n");

    while (1)
    {
        int u, v, weight;
        printf("Enter edge: ");
        scanf("%d %d %d", &u, &v, &weight);
        if (u == 0 && v == 0 && weight == 0)
            break;
        graph[u][v] = weight;
        graph[v][u] = weight; // For undirected graph
    }

    // Call Prim's algorithm to find the MST
    prim(graph, V);

    return 0; // Explicit return for program termination
}
