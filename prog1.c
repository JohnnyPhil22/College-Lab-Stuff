/*
// Print hello world
#include <stdio.h>

int main()
{
    printf("Hello World\n");
}

// Check if year is leap year or not
#include <stdio.h>

int main()
{
    int num;
    printf("Enter year: ");
    scanf("%d", &num);

    if (num % 100 == 0)
    {
        if (num % 400 == 0)
        {
            printf("Leap year\n");
        }
        else
        {
            printf("Not leap year\n");
        }
    }
    else
    {
        if (num % 4 == 0)
        {
            printf("Leap year\n");
        }
        else
        {
            printf("Not leap year \n");
        }
    }
}

// Reverse inputted 5-digit number and check if it equal to original number (without loops)
#include <stdio.h>

int main()
{
    int num, ori, rev = 0, rem;
    printf("Enter number: ");
    scanf("%d", &num);
    ori = num;

    rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
    rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
    rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
    rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
    rem = num % 10;
    rev = rev * 10 + rem;
    num /= 10;
    printf("Reversed number: %i\n", rev);

    if (ori == rev)
    {
        printf("Reversed number is same as original number\n");
    }
    else
    {
        printf("Reversed number is not same as original number\n");
    }
}

// Youngest age among three people
#include <stdio.h>
int main()
{
    int a, b, c;
    printf("Enter ages of three people: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b)
    {
        if (b < c)
        {
            printf("%i is the youngest age", a);
        }
        else
        {
            if (a < c)
            {
                printf("%i is the youngest age", a);
            }
            else
            {
                printf("%i is the youngest age", c);
            }
        }
    }
    else
    {
        if (b < c)
        {
            printf("%i is the youngest age", b);
        }
        else
        {
            printf("%i is the youngest age", c);
        }
    }
}

// Solve Q3 using conditional operators
#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter ages of three people: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b && a < c)
    {
        printf("%i is the youngest age", a);
    }
    else if (b < c)
    {
        printf("%i is the youngest age", b);
    }
    else
    {
        printf("%i is the youngest age", c);
    }
}

// Find whether year is leap year or not using && and ||.
#include <stdio.h>

int main()
{
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    if (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0))
    {
        printf("It is leap year");
    }
    else
    {
        printf("It is not leap year");
    }
}

// If it was Monday on 01/01/01, find out what day it is on 01/01/yy
#include <stdio.h>

int main()
{
    int year, basic_year = 1900, leap_year, remaining_year, total_days, day;

    printf("Enter the year: ");
    scanf("%d", &year);

    if (year < basic_year)
    {
        year = (basic_year - 1) - year;
    }
    else
    {
        year = (year + 1) - basic_year;
    }

    leap_year = year / 4;

    remaining_year = year - leap_year;

    total_days = (remaining_year * 365) + (leap_year * 366) + 1;

    if (total_days % 7 == 0)
    {
        printf("Monday");
    }
    else if (total_days % 7 == 1)
    {
        printf("Tuesday");
    }
    else if (total_days % 7 == 2)
    {
        printf("Wednesday");
    }
    else if (total_days % 7 == 3)
    {
        printf("Thursday");
    }
    else if (total_days % 7 == 4)
    {
        printf("Friday");
    }
    else if (total_days % 7 == 5)
    {
        printf("Saturday");
    }
    else if (total_days % 7 == 6)
    {
        printf("Sunday");
    }
}

// Evaluate value of y=x^n
#include <stdio.h>
#include <math.h>

int main()
{
    int y, x, n;
    printf("Enter values of x and n: ");
    scanf("%d %d", &x, &n);
    y = pow(x, n);
    printf("%d\n", y);
}

// Determine factorial of given number
#include <stdio.h>

int main()
{
    int n, ori, fac = 1;
    printf("Enter number to find factorial: ");
    scanf("%d", &n);
    ori = n;
    while (n > 0)
    {
        fac *= n;
        n -= 1;
    }
    printf("Factorial of %d = %d\n", ori, fac);
}

// Print prime numbers between 1 and 300
#include <stdio.h>

int main()
{
    int lower, upper, i, j, flag;

    printf("Enter lower and upper limits of interval: ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d are:\n", lower, upper);

    for (i = lower; i <= upper; i++)
    {
        if (i == 1 || i == 0)
        {
            continue;
        }

        flag = 1;

        for (j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag == 1)
        {
            printf("%d\n", i);
        }
    }
}

// Print ASCII values and their characters
#include <stdio.h>
int main()
{
    int k;
    for (k = 0; k <= 255; k++)
    {
        printf("ASCII Value of %c is %d\n", k, k);
    }
}

// Print all Armstrong number between 1 and 2000
#include <stdio.h>

int main()
{
    int i = 1, ori, rem, sum;
    while (i <= 2000)
    {
        ori = i;
        sum = 0;
        while (ori != 0)
        {
            rem = ori % 10;
            sum += rem * rem * rem;
            ori /= 10;
        }
        if (sum == i)
        {
            printf("%d\n", i);
        }
        i++;
    }
}

// Menu driven program for factorial of number, find out if number is prime number or not, number is odd or even and exit
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    while (1)
    {
        printf("1. Factorial of number\n2. Prime number or not\n3. Odd or even number\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int n, ori, fac = 1;
            printf("Enter number to find factorial: ");
            scanf("%d", &n);
            ori = n;
            while (n > 0)
            {
                fac *= n;
                n -= 1;
            }
            printf("Factorial of %d = %d\n", ori, fac);
            break;

        case 2:
            int num, i, flag = 0;
            printf("Enter a positive integer: ");
            scanf("%d", &num);

            if (num == 0 || num == 1)
            {
                flag = 1;
            }

            for (i = 2; i <= num / 2; i++)
            {
                if (num % i == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                printf("%d is a prime number.\n", num);
            }
            else
            {
                printf("%d is not a prime number.\n", num);
            }
            break;

        case 3:
            int number;
            printf("Enter number: ");
            scanf("%d", &number);

            if (number % 2 == 0)
            {
                printf("%d is even number\n", number);
            }
            else
            {
                printf("%d is odd number\n", number);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Entered wrong choice\n");
        }
    }
}

// Check if year is leap year or not using functions
#include <stdio.h>

void leap_year(int year)
{
    if (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0))
    {
        printf("%d is leap year\n", year);
    }
    else
    {
        printf("%d is not leap year\n", year);
    }
}

int main()
{
    int yr;
    printf("Enter year: ");
    scanf("%d", &yr);
    leap_year(yr);
}

#include <stdio.h>
int main()
{
    int i, j, diff, value;
    for (i = 1; i <= 5; i++)
    {
        value = i;
        diff = 4;
        for (j = 1; j <= i; j++)
        {
            printf("%d ", value);
            value += diff;
            diff--;
        }
        printf("\n");
    }
}

// Factorial of number using recursion
#include <stdio.h>

int fact(int n)
{
    int f;
    if (n == 0 || n == 1)
    {
        return (1);
    }
    else
    {
        f = n * fact(n - 1);
    }
    return (f);
}

int main()
{
    int num, factorial;
    printf("Enter number: ");
    scanf("%d", &num);

    factorial = fact(num);
    printf("%d", factorial);
}

#include <stdio.h>
#include <math.h>
int numofdigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x /= 10;
        count++;
    }
    return count;
}

int armstrong(int x)
{
    int original = x, count = numofdigits(x), sum = 0, digit;
    while (x != 0)
    {
        digit = x % 10;
        sum += pow(digit, count);
        x /= 10;
    }
    return sum;
}

void main()
{
    int m;
    scanf("%d", &m);
    if (armstrong(m) == m)
    {
        printf("AS");
    }
    else
    {
        printf("NAS");
    }
}
*/
#include <stdio.h>
int main()
{
    int i, j, diff, value;
    for (i = 1; i <= 5; i++)
    {
        value = i;
        diff = 4;
        for (j = 1; j <= i; j++)
        {
            printf("%d ", value);
            value += diff;
            diff--;
        }
        printf("\n");
    }
}