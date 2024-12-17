#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n)
{
    printf("Entering factorial(%d)\n", n); // Show stack state entering the function
    if (n == 0 || n == 1)
    {
        printf("Returning from factorial(%d) = 1\n", n); // Base case
        return 1;
    }
    int result = n * factorial(n - 1);                        // Recursive call
    printf("Returning from factorial(%d) = %d\n", n, result); // Show stack state before return
    return result;
}

int main()
{
    int num;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial of a negative number is not defined.\n");
    }
    else
    {
        int fact = factorial(num);
        printf("Factorial of %d is %d\n", num, fact);
    }

    return 0;
}
