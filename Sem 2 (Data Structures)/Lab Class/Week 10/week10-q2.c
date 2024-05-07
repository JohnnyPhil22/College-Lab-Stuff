// Implement Adjacency Matrix for graph implementation.
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];

void addEdge(int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void main()
{
    int num;
    printf("Enter number of vertices: ");
    scanf("%d", &num);
    int v1, v2, ch = 1;
    while (ch == 1)
    {
        printf("Enter the two vertices with link: ");
        scanf("%d %d", &v1, &v2);
        addEdge(v1, v2);
        printf("Do you want to add more links? (1/0): ");
        scanf("%d", &ch);
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}