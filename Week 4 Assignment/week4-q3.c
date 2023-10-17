// WAP to find the value of one number raised to the power of other number (do not use pow() function).
#include <stdio.h>
#include <math.h>

int main()
{
    int y = 1, x, n;
    printf("Enter values of x and n: ");
    scanf("%d %d", &x, &n);
    for (int i = 1; i <= n; i++)
    {
        y *= x;
    }
    printf("y = %d\n", y);
}