// Check if number is zero, positive or negative
#include <stdio.h>

int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    if (num == 0)
    {
        printf("Number is zero");
    }
    else if (num > 0)
    {
        printf("%d is positive", num);
    }
    else if (num < 0)
    {
        printf("%d is negative", num);
    }
    else
    {
        printf("Enter valid number");
    }
}