// Write a program to calculate the sum of digits of a 5-digit positive integer entered through the keyboard using both recursive and non-recursive functions.
/// Recursive function
#include <stdio.h>
int dig_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 10) + dig_sum(n / 10);
}

void main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Sum of digits: %d", dig_sum(num));
}

/// Non - Recursive function
#include <stdio.h>
int dig_sum(int n)
{
    int sum;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("Sum of digits: %d", dig_sum(num));
}