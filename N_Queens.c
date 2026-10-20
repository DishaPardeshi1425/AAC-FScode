#include <stdio.h>
#include <stdlib.h>

int x[20], n;

int place(int row, int col)
{
    int i;

    for (i = 0; i < row; i++)
        if (x[i] == col || abs(x[i] - col) == abs(i - row))
            return 0;

    return 1;
}

int solve(int row)
{
    int col;

    if (row == n)
        return 1;

    for (col = 0; col < n; col++)
    {
        if (place(row, col))
        {
            x[row] = col;

            if (solve(row + 1))
                return 1;
        }
    }

    return 0;
}

int main()
{
    int i, j;

    printf("Enter number of queens (1-19): ");
    scanf("%d", &n);

    if (n < 1 || n > 19)
    {
        printf("Invalid size.\n");
        return 1;
    }

    if (solve(0))
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf("%c ", x[i] == j ? 'Q' : '.');
            printf("\n");
        }
    }
    else
        printf("No solution exists.\n");

    return 0;
}