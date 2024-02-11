// Create a C program that acts as a simple calculator, allowing the user to perform addition, subtraction, multiplication, and division operations on two numbers based on user input.
#include <stdio.h>

void main()
{
    int a, b, c;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter choice (1 = Add, 2 = Subtract, 3 = Multiply, 4 = Divide): ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        printf("%d + %d = %d", a, b, (a + b));
        break;

    case 2:
        printf("%d - %d = %d", a, b, (a - b));
        break;

    case 3:
        printf("%d * %d = %d", a, b, (a * b));
        break;

    case 4:
        printf("%d / %d = %f", a, b, (float)a / (float)b);
        break;

    default:
        printf("Enter valid option\n");
        break;
    }
}