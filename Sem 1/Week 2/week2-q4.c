// Write a C program that swaps the values of two variables: A. Using a third variable as a temporary storage.
#include <stdio.h>

void main()
{
    int a, b, temp;
    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    temp = a;
    a = b;
    b = temp;
    printf("a = %d, b = %d", a, b);
}

// B. Without using a third variable. Use arithmetic operations to achieve this.
#include <stdio.h>

void main()
{
    int a, b;
    printf("Enter values of a and b: ");
    scanf("%d %d", &a, &b);
    printf("a = %d, b = %d\n", a, b);
    a += b;
    b = a - b;
    a -= b;
    printf("a = %d, b = %d", a, b);
}