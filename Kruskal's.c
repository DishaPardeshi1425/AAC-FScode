#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[20];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];

    return x;
}

int main()
{
    struct Edge e[100], temp;
    int n, m, i, j, u, v, cost = 0, count = 0;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter each edge (u v weight), vertices 0 to n-1:\n");
    for (i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < m - 1; i++)
        for (j = i + 1; j < m; j++)
            if (e[i].w > e[j].w)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }

    for (i = 0; i < m && count < n - 1; i++)
    {
        u = find(e[i].u);
        v = find(e[i].v);

        if (u != v)
        {
            printf("%d - %d : %d\n",
                   e[i].u, e[i].v, e[i].w);

            parent[u] = v;
            cost += e[i].w;
            count++;
        }
    }

    if (count != n - 1)
        printf("Graph is disconnected.\n");
    else
        printf("Minimum cost = %d\n", cost);

    return 0;
}