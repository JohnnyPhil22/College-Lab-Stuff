// Write a program to obtain the prime factors of a positive integer entered through the keyboard. Modify the function suitably to obtain the prime factors recursively.
/// Non - recursive function
#include <stdio.h>

int prime_factors(int n)
{
    printf("Prime factors are: ");
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
    }
}

void main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    prime_factors(num);
}

/// Recursive function
#include <stdio.h>

int primefactors(int n, int div)
{
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        if (n % div == 0)
        {
            printf("%d ", div);
            primefactors(n / div, div);
        }
        else
        {
            primefactors(n, div + 1);
        }
    }
}

int main()
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Prime factors of %d are: ", num);
    primefactors(num, 2);
}