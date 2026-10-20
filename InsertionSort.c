#include <stdio.h>

void insertionSort(int A[], int n)
{
    int i, j, item;

    for (i = 1; i < n; i++)
    {
        item = A[i];
        j = i - 1;

        while (j >= 0 && item < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = item;
    }
}

int main()
{
    int A[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    insertionSort(A, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}