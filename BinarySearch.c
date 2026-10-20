#include <stdio.h>

int binarySearch(int A[], int n, int key)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int A[100], n, key, i, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = binarySearch(A, n, key);

    if (result == -1)
        printf("Element not found");
    else
        printf("Element found at position %d", result + 1);

    return 0;
}