#include <stdio.h>

void heapify(int A[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}

void heapSort(int A[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapify(A, i, 0);
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

    heapSort(A, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}