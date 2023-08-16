/*
    To Become familiar with dynamic memory allocation ( Relloc ).

    Write a C program that dynamically allocates memory to an integer array. The program should prompt the user to enter the initial size of the array and then display the addresses of the allocated memory blocks. Next, the program should ask the user to enter a new size for the array and display the addresses of the newly allocated memory blocks. Finally, the program should release the allocated memory before exiting.
    Your program should also handle potential errors gracefully, such as when the user enters a non-positive size for the array. Implement error handling to display user-friendly messages in such cases.
    Please write the C program based on the above requirements.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, i, n1, n2;
    printf("\nEnter the initial size: ");
    scanf("%d", &n1);

    // Error handling for non-positive size
    if (n1 <= 0)
    {
        printf("Invalid size. Please enter a positive number.\n");
        return 1; // Exit the program with an error code
    }

    ptr = (int *)malloc(n1 * sizeof(int));

    printf("Addresses of previously allocated memory:\n");
    for (i = 0; i < n1; ++i)
        printf("%p\n", (void *)(ptr + i));

    printf("\nEnter the new size: ");
    scanf("%d", &n2);

    // Error handling for non-positive size
    if (n2 <= 0)
    {
        printf("Invalid size. Please enter a positive number.\n");
        free(ptr); // Free previously allocated memory
        return 1;  // Exit the program with an error code
    }

    // reallocating the memory
    ptr = (int *)realloc(ptr, n2 * sizeof(int));

    printf("Addresses of newly allocated memory:\n");
    for (i = 0; i < n2; ++i)
        printf("%p\n", (void *)(ptr + i));

    free(ptr);
    printf("\n");

    return 0; // Exit the program successfully
}