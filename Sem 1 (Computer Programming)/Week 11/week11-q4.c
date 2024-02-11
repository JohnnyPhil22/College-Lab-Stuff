// Complex numbers are those numbers that can be expressed in the form of "a + ib" where a and b are the real numbers and i is the imaginary part with value √−1. Write a C program to add two complex numbers.
#include <stdio.h>

struct Complex
{
    int real;
    int imag;
} a, b, sum;

void main()
{
    printf("Enter real and imaginary parts of a: ");
    scanf("%d %d", &a.real, &a.imag);

    printf("Enter real and imaginary parts of b: ");
    scanf("%d %d", &b.real, &b.imag);

    sum.real = a.real + b.real;
    sum.imag = a.imag + b.imag;

    printf("Sum = %d + %di\n", sum.real, sum.imag);
}