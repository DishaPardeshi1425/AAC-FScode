#include <stdio.h>
#define MAX 10000

void bubbleSort(int a[], int n, int choice)
{
    int i, j, temp, swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            if ((choice == 1 && a[j] > a[j + 1]) ||
                (choice == 2 && a[j] < a[j + 1]))
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

int main(void)
{
    int a[MAX], n, choice, i;

    printf("BUBBLE SORT\nEnter number of elements (1-%d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Order: 1. Ascending  2. Descending\nEnter choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2)
    {
        printf("Invalid choice.\n");
        return 1;
    }

    bubbleSort(a, n, choice);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}