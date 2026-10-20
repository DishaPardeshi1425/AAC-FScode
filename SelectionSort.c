#include <stdio.h>

void selectionSort(int A[], int n)
{
    int i, j, mini, temp;

    for (i = 0; i < n - 1; i++)
    {
        mini = i;

        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[mini])
            {
                mini = j;
            }
        }

        temp = A[i];
        A[i] = A[mini];
        A[mini] = temp;
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

    selectionSort(A, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}