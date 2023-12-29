// Write a C program that reads two numbers and outputs their difference.
#include <stdio.h>

void main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("%d - %d = %d", a, b, (a - b));
}