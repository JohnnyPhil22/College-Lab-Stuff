// Implement three different ways to swap two variables without using a third variable.
#include <stdio.h>
void main()
{
    int a = 5, b = 6;
    printf("Method 1: Original: a: %d, b: %d\n", a, b);
    a += b;
    b = a - b;
    a -= b;
    printf("      	Swapped: a: %d, b: %d\n\n", a, b);
    printf("Method 2: Original: a: %d, b: %d\n", a, b);
    a *= b;
    b = a / b;
    a /= b;
    printf("      	Swapped: a: %d, b: %d\n\n", a, b);
    printf("Method 3: Original: a: %d, b: %d\n", a, b);
    a = b - a;
    b -= a;
    a += b;
    printf("      	Swapped: a: %d, b: %d\n", a, b);
}