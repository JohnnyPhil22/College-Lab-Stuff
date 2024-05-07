// Print the Connected Components in an Undirected Graph.
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES], num = 0;
bool visited[MAX_VERTICES];

void addEdge(int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void DFS(int v)
{
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < num; i++)
    {
        if (adjMatrix[v][i] && !visited[i])
        {
            DFS(i);
        }
    }
}

void printConn()
{
    printf("Connected Components:\n");
    for (int v = 0; v < num; v++)
    {
        if (!visited[v])
        {
            printf("Component: ");
            DFS(v);
            printf("\n");
        }
    }
}

int main()
{
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

    for (int i = 0; i < num; i++)
    {
        visited[i] = false;
    }

    printConn();
}