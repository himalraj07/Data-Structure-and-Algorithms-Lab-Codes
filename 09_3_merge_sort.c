/*
    To Become familiar with sorting algorithms. ( Merge Sort ).
*/

#include <stdio.h>
#define MAX 100

void merge(int L[], int R[], int A[], int nL, int nR)
{
    int i, j, k;
    i = j = k = 0;

    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nL)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < nR)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int n)
{
    if (n < 2)
        return;

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = A[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = A[i];

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, right, A, mid, n - mid);
}

int main()
{
    int merge[MAX], n;

    printf("\nEnter total number of elements (1 to %d): ", MAX);
    while (scanf("%d", &n) != 1 || n < 1 || n > MAX)
    {
        printf("Invalid input. Please enter a positive integer between 1 and %d: ", MAX);
        while (getchar() != '\n'); // Clear input buffer
    }

    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &merge[i]);

    mergeSort(merge, n);

    printf("\nSorting %d elements of the array ...\n", n);
    printf("Sorted elements are : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", merge[i]);
    }

    printf("\n\n");
    return 0;
}