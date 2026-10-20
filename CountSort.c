#include <stdio.h>

void countingSort(int A[], int B[], int n, int k)
{
    int C[100], i;

    // 1. Initialize count array
    for (i = 0; i <= k; i++)
        C[i] = 0;

    // 2. Count occurrences
    for (i = 0; i < n; i++)
        C[A[i]]++;

    // 3. Calculate cumulative count
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];

    // 4. Place elements in output array
    for (i = n - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main()
{
    int A[100], B[100], n, i, k = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter non-negative elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);

        if (A[i] > k)
            k = A[i];
    }

    countingSort(A, B, n, k);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", B[i]);

    return 0;
}