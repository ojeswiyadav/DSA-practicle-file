#include <stdio.h>
#include <stdlib.h>

// Structure for an edge
struct Edge
{
    int u, v, weight;
};

// Structure for a disjoint-set (Union-Find)
struct Subset
{
    int parent;
    int rank;
};

// Function to compare two edges based on their weight
int compareEdges(const void *a, const void *b)
{
    struct Edge *edge1 = (struct Edge *)a;
    struct Edge *edge2 = (struct Edge *)b;
    return edge1->weight - edge2->weight;
}

// Function to find the parent of a node with path compression
int find(struct Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to perform the union of two subsets using rank
void unionSubsets(struct Subset subsets[], int x, int y)
{
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
    {
        subsets[rootX].parent = rootY;
    }
    else if (subsets[rootX].rank > subsets[rootY].rank)
    {
        subsets[rootY].parent = rootX;
    }
    else
    {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Function to implement Kruskal's algorithm to find MST
void kruskal(struct Edge edges[], int V, int E)
{
    struct Subset subsets[V];
    for (int i = 0; i < V; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort all edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Result array to store MST
    struct Edge result[V - 1];
    int e = 0; // Count of edges in MST
    int i = 0; // Index for sorted edges

    while (e < V - 1 && i < E)
    {
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.u);
        int y = find(subsets, nextEdge.v);

        // If including this edge does not form a cycle
        if (x != y)
        {
            result[e++] = nextEdge;
            unionSubsets(subsets, x, y);
        }
    }

    // Print the MST
    printf("\nMinimum Spanning Tree (MST):\n");
    int mstWeight = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d -- %d = %d\n", result[i].u, result[i].v, result[i].weight);
        mstWeight += result[i].weight;
    }
    printf("\nTotal weight of MST: %d\n", mstWeight);
}

int main()
{
    int V, E;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    // Input all the edges
    printf("Enter the edges (u, v, weight):\n");
    for (int i = 0; i < E; i++)
    {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Call Kruskal's algorithm to find the MST
    kruskal(edges, V, E);

    return 0; // Explicit return for program termination
}
