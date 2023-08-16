/*
    [ DM FREE ]
    [ Program to calculate the sum of n numbers entered by the user. ]
    [ To Become familiar with dynamic memory allocation ( Calloc ). ]
    
    Write a C program to calculate the sum of 'n' numbers entered by the user. The program should prompt the user to enter the value of 'n' and then ask the user to input 'n' integer elements. After receiving the input, the program should display the sum of all the entered elements.
    Make sure to handle any errors gracefully and provide clear instructions to the user during input.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, *ptr, sum = 0;

    printf("\nEnter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input! Please enter a positive integer for the number of elements.\n\n");
        return 1;
    }

    // Allocate memory for the elements
    ptr = (int *)malloc(n * sizeof(int));

    // If memory cannot be allocated
    if (ptr == NULL)
    {
        printf("Error! Memory not allocated.\n\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; ++i)
    {
        if (scanf("%d", ptr + i) != 1)
        {
            printf("Invalid input! Please enter a valid integer.\n\n");
            free(ptr);
            return 1;
        }
        sum += *(ptr + i);
    }
    printf("The sum of first %d elements is %d.\n\n", n, sum);

    // Deallocate the memory
    free(ptr);

    return 0;
}