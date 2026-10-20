#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int w[100], p[100], dp[101][101];
    int n, capacity, i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    printf("Enter profits:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for (i = 0; i <= n; i++)
        for (j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i] <= j)
                dp[i][j] = max(p[i] + dp[i-1][j-w[i]],
                               dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }

    printf("Maximum profit = %d\n", dp[n][capacity]);

    return 0;
}