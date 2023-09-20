// Check if inputted year is leap year or not using && and ||
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

// Check if inputted year is leap year or not without using && and ||
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