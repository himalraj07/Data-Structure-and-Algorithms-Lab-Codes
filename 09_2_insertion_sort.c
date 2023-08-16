/*
    To Become familiar with sorting algorithms. ( Insertion Sort ).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, size, temp;
    printf("\nInsertion Sort\n");

    // Input
    printf("Enter total number of elements: ");
    scanf("%d", &size);

    if (size <= 0 || size > 20)
    {
        printf("Error: Number of elements should be between 1 and 20.\n\n");
        return 1;
    }

    int array[20];
    printf("Enter %d elements : ", size);
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    // Insertion Sort
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }

    // Output
    printf("\nSorting %d elements of the array ...\n", size);
    printf("Sorted elements are : ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n\n");
    return 0;
}