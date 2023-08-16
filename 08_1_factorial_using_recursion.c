/*
    To find the factorial of number using Recursion.
*/

#include <stdio.h>

// Function to find the factorial of a number using recursion
unsigned long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int num;
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        unsigned long long result = factorial(num);
        printf("Factorial of %d is %llu\n", num, result);
    }

    return 0;
}