#include <stdio.h>

int getMax(int A[], int n)
{
    int max = A[0];

    for (int i = 1; i < n; i++)
        if (A[i] > max)
            max = A[i];

    return max;
}

void countingSort(int A[], int n, int place)
{
    int B[100], C[10] = {0};
    int i, digit;

    for (i = 0; i < n; i++)
    {
        digit = (A[i] / place) % 10;
        C[digit]++;
    }

    for (i = 1; i < 10; i++)
        C[i] += C[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        digit = (A[i] / place) % 10;
        B[C[digit] - 1] = A[i];
        C[digit]--;
    }

    for (i = 0; i < n; i++)
        A[i] = B[i];
}

void radixSort(int A[], int n)
{
    int max = getMax(A, n);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(A, n, place);
}

int main()
{
    int A[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    radixSort(A, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
