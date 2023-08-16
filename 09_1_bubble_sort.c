/*
    To Become familiar with sorting algorithms. ( Bubble Sort ).
*/

#include <stdio.h>

void bubble(int *ptr, int size)
{
    int i, j;
    int temp;
    for (i = 1; i < size; i++)
    {
        for (j = 0; j < size - i; j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

int main()
{
    int arr[10];
    int i;
    int size;

    printf("\nEnter the size of the array (up to 10): ");
    scanf("%d", &size);

    if (size <= 0 || size > 10)
    {
        printf("Invalid size! Size should be between 1 and 10.\n\n");
        return 1; // Return 1 to indicate an error
    }

    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nSorting %d elements ...\n", size);
    printf("\nBefore sorting: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    bubble(arr, size);

    printf("\nAfter sorting: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    return 0; // Return 0 to indicate successful execution
}