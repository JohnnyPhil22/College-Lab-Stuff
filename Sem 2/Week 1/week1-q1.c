// Implement Call by Value and Call by Reference mechanisms.
#include <stdio.h>
void main()
{
    int a = 5, b = 6;
    printf("Call by value:\na: %d\nb: %d\n", a, b);
    int *c = a, *d = b;
    printf("\nCall by reference:\na: %d\nb: %d\n", c, d);
}