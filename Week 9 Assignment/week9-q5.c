// Write a C program repdigit.c to check whether a given number has one or more repeated digit(s) or not. For example, the number 28212 has a repeated digit (2), 3125653 has two repeated digits (3 and 5), and 93576 has no repeated digit. Modify the repdigit.c program so that it prints a table showing how many times each digit (if any) appears in the number.
#include <stdio.h>

int hasrepdig(int num)
{
    int digitCount[10] = {0};

    while (num > 0)
    {
        int digit = num % 10;
        digitCount[digit]++;
        if (digitCount[digit] > 1)
        {
            return 1;
        }
        num /= 10;
    }
    return 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (hasrepdig(num))
    {
        printf("The number has repeated digit(s).\n");
    }
    else
    {
        printf("The number has no repeated digits.\n");
    }
    int digitCount[10] = {0};

    while (num > 0)
    {
        int digit = num % 10;
        digitCount[digit]++;
        num /= 10;
    }

    printf("Digit Counts:\n");
    for (int i = 0; i < 10; i++)
    {
        if (digitCount[i] > 0)
        {
            printf("%d: %d times\n", i, digitCount[i]);
        }
    }
}