// WAP to obtain the reversed number of a given number. Maximum digits in number are 7.
#include <stdio.h>
int main()
{
    int num, rev = 0, rem;
    printf("Enter number: ");
    scanf("%d", &num);

    while (num>0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    printf("Reversed number: %d\n", rev);
}