/*
    To Become familiar with GCD Using Recursion.
*/

#include <stdio.h>

// Function to find the GCD of two numbers using recursion
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int num1, num2;
    printf("\nEnter two integers to find their GCD : ");
    scanf("%d %d", &num1, &num2);

    if (num1 <= 0 || num2 <= 0)
    {
        printf("Both numbers should be positive integers.\n\n");
    }
    else
    {
        int result = gcd(num1, num2);
        printf("GCD of %d and %d is %d\n\n", num1, num2, result);
    }

    return 0;
}