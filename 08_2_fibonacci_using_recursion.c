/*
    To Become familiar with Fibonacci series using Recursion.
*/

#include <stdio.h>

// Function to find the nth Fibonacci number using recursion
int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int num;
    printf("\nEnter the number of terms in the Fibonacci series : ");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Number of terms should be a positive integer.\n\n");
    }
    else
    {
        printf("Fibonacci series: ");
        for (int i = 0; i < num; i++)
        {
            printf("%d ", fibonacci(i));
        }
        printf("\n\n");
    }

    return 0;
}