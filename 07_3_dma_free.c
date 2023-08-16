/*
    [ DMC FREE ]

    [ To Become familiar with dynamic memory allocation. ( Free ) ]

    To Become familiar with dynamic memory allocation ( Free ).

    Program to calculate the sum of n numbers entered by the user.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, *ptr, sum = 0;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    // Check if the user entered a positive number of elements
    if (n <= 0)
    {
        printf("Error! Please enter a positive number of elements.\n\n");
        return 1;
    }

    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Error! Memory not allocated.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("The sum of first %d elements is %d.\n\n", n, sum);
    free(ptr);

    return 0;
}