// Write a program to compute the Greatest Common Divisor (GCD) of two number using the following approaches:
/// a. Naïve approach (Iterative approach)
#include <stdio.h>
int gcd_naive(int a, int b)
{
    int gcd;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d = %d", a, b, gcd_naive(a, b));
}

/// b. Euclidean Algorithm by Subtraction (Recursive Approach)
#include <stdio.h>
int gcd_subtract(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    if (a > b)
    {
        return gcd_subtract(a - b, b);
    }
    else
    {
        return gcd_subtract(a, b - a);
    }
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d = %d", a, b, gcd_subtract(a, b));
}

/// c. Euclidean Algorithm by Division (Recursive Approach)
#include <stdio.h>
int gcd_subtract(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd_subtract(b, a % b);
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d = %d", a, b, gcd_subtract(a, b));
}
