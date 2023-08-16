/*
    To Become Familiar With Searching Algorithms.
*/

#include <stdio.h>

#define MAX_SIZE 100

int searchArray(int arr[], int size, int toSearch)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == toSearch)
        {
            return i;
        }
    }
    return -1; // Not found
}

int main()
{
    int arr[MAX_SIZE];
    int size, i, toSearch, found;

    printf("\nEnter the size of the array (up to %d): ", MAX_SIZE);

    do
    {
        if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_SIZE)
        {
            printf("Invalid input. Please enter a positive integer size up to %d: ", MAX_SIZE);
            while (getchar() != '\n')
                ; // Clear input buffer
        }
        else
        {
            break;
        }
    } while (1);

    printf("Enter elements in the array : ");
    for (i = 0; i < size; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input. Please enter an integer: ");
            i--;
            while (getchar() != '\n')
                ; // Clear input buffer
        }
    }

    printf("Enter the element to search: ");
    while (scanf("%d", &toSearch) != 1)
    {
        printf("Invalid input. Please enter an integer: ");
        while (getchar() != '\n')
            ; // Clear input buffer
    }

    found = searchArray(arr, size, toSearch);

    if (found != -1)
    {
        printf("%d is found at position %d.\n\n", toSearch, found + 1);
    }
    else
    {
        printf("%d is not found in the array.\n\n", toSearch);
    }

    return 0;
}