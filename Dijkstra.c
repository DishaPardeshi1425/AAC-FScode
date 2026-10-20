#include <stdio.h>
#define INF 999

int main()
{
    int a[10][10], d[10], visited[10] = {0};
    int n, source, i, j, min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix (999 for no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for (i = 0; i < n; i++)
        d[i] = INF;

    d[source] = 0;

    for (i = 0; i < n; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
            if (!visited[j] && d[j] < min)
            {
                min = d[j];
                u = j;
            }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++)
            if (!visited[j] && a[u][j] != INF &&
                d[u] + a[u][j] < d[j])
                d[j] = d[u] + a[u][j];
    }

    printf("Shortest distances:\n");
    for (i = 0; i < n; i++)
    {
        if (d[i] == INF)
            printf("%d -> %d = Unreachable\n", source, i);
        else
            printf("%d -> %d = %d\n", source, i, d[i]);
    }

    return 0;
}