#include <stdio.h>
#define INF 999

int main()
{
    int a[10][10], visited[10] = {0};
    int n, i, j, edges = 0;
    int min, u = 0, v = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix (999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    visited[0] = 1;

    while (edges < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
            if (visited[i])
                for (j = 0; j < n; j++)
                    if (!visited[j] && a[i][j] < min)
                    {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }

        if (min == INF)
        {
            printf("Graph is disconnected.\n");
            return 1;
        }

        printf("%d - %d : %d\n", u, v, min);
        cost += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", cost);

    return 0;
}