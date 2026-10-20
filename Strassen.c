#include <stdio.h>

int main()
{
    int A[2][2], B[2][2], C[2][2];
    int m1, m2, m3, m4, m5, m6, m7;
    int i, j;

    printf("Enter first 2x2 matrix:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second 2x2 matrix:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    m2 = (A[1][0] + A[1][1]) * B[0][0];
    m3 = A[0][0] * (B[0][1] - B[1][1]);
    m4 = A[1][1] * (B[1][0] - B[0][0]);
    m5 = (A[0][0] + A[0][1]) * B[1][1];
    m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;

    printf("Product matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}