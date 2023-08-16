/*
    To Become familiar with sorting algorithms. ( Heap Sort ).
*/

#include <stdio.h>

void create(int[]);
void adjust(int[], int);

int main()
{
    int heap[30], n, i, last, temp;

    printf("\nEnter the number of elements : ");
    scanf("%d", &n);

    if (n <= 0 || n > 30)
    {
        printf("Please enter a valid number of elements (1 to 30).\n\n");
        return 1;
    }

    printf("Enter %d elements : ", n);
    for (i = 1; i <= n; i++)
        scanf("%d", &heap[i]);

    // create a heap
    heap[0] = n;
    create(heap);

    // sorting
    while (heap[0] > 1)
    {
        // swap heap[1] and heap[last]
        last = heap[0];
        temp = heap[1];
        heap[1] = heap[last];
        heap[last] = temp;
        heap[0]--;
        adjust(heap, 1);
    }

    // print sorted data
    printf("\nSorting %d elements of the array ...\n", n);
    printf("Array after sorting with sorted elements are : ");
    for (i = 1; i <= n; i++)
        printf("%d ", heap[i]);

    printf("\n\n");
    return 0;
}

void create(int heap[])
{
    int i, n;
    n = heap[0]; // no. of elements

    for (i = n / 2; i >= 1; i--)
        adjust(heap, i);
}

void adjust(int heap[], int i)
{
    int j, temp, n, flag = 1;
    n = heap[0];

    while (2 * i <= n && flag == 1)
    {
        j = 2 * i; // j points to the left child
        if (j + 1 <= n && heap[j + 1] > heap[j])
            j = j + 1;
        if (heap[i] > heap[j])
            flag = 0;
        else
        {
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }
    }
}