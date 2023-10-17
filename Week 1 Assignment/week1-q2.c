// Create a C program that takes two numbers as input and prints their sum.
#include <stdio.h>

void main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("%d + %d = %d", a, b, (a + b));
}