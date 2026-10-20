#include <stdio.h>

void knapsack(int n, float w[], float p[], float capacity)
{
    int i, j;
    float ratio[100], temp, profit = 0;

    for (i = 0; i < n; i++)
        ratio[i] = p[i] / w[i];

    // Sort by profit/weight ratio
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (capacity >= w[i])
        {
            capacity -= w[i];
            profit += p[i];
        }
        else
        {
            profit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", profit);
}

int main()
{
    int n, i;
    float w[100], p[100], capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &w[i]);

    printf("Enter profits:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &p[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    knapsack(n, w, p, capacity);

    return 0;
}