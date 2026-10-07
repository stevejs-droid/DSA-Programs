#include <stdio.h>
#define MAX 100

int main()
{
    int n, start;
    int adj[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    visited[start] = 1;
    rear++;
    queue[rear] = start;

    printf("BFS Traversal: ");
    while (front <= rear)
    {
        int u = queue[front];
        front++;

        printf("%d ", u);

        for (int v = 0; v < n; v++)
        {
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                rear++;
                queue[rear] = v;
            }
        }
    }

    printf("\n");

    return 0;
}
