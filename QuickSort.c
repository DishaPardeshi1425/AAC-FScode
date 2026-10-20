#include <stdio.h>

void quickSort(int A[], int low, int high)
{
    int i, j, pivot, temp;

    if (low < high)
    {
        pivot = A[high];
        i = low - 1;

        for (j = low; j < high; j++)
        {
            if (A[j] < pivot)
            {
                i++;
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

        temp = A[i + 1];
        A[i + 1] = A[high];
        A[high] = temp;

        int p = i + 1;

        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

int main()
{
    int A[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    quickSort(A, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}