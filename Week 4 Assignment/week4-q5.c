// WAP to print all prime numbers from 1 to 100.
#include <stdio.h>

int main()
{
    int lower, upper, i, j, flag;

    printf("Enter lower and upper limits of interval: ");
    scanf("%d %d", &lower, &upper);

    printf("Prime numbers between %d and %d:\n", lower, upper);

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