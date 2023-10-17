// Develop a C program that calculates the result of raising a number to a given power (exponent).
#include <stdio.h>
#include <math.h>

void main()
{
    int a, b, c;
    printf("Enter number and power: ");
    scanf("%d %d", &a, &b);
    c = pow(a, b);
    printf("%d ^ %d = %d", a, b, c);
}