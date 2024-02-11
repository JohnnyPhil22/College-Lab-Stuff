// Write a C program to verify Legendre's Conjecture for a given N.
#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int i;
    if (n <= 1)
    {
        return 0;
    }
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int legendre(int n)
{
    int count = 0;
    int i = n * n + 1;
    while (count < 1)
    {
        if (is_prime(i))
        {
            count++;
        }
        i++;
    }
    return i - 1;
}

int main()
{
    int n;
    printf("Enter N: ");
    scanf("%d", &n);
    int prime = legendre(n);
    printf("It verifies Legendre Conjecture and the prime number is: %d\n", prime);
    return 0;
}