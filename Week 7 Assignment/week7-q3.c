// Twenty numbers are entered from the keyboard into an array. Write a C program to find out how many of them are positive, how many are negative, how many are even and how many odd using conditional operators.
#include <stdio.h>
void main()
{
    int cpos = 0, cneg = 0, ceve = 0, codd = 0, arr[20];
    for (int i = 0; i < 20; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
        cpos += (arr[i] > 0) ? 1 : 0;
        cneg += (arr[i] < 0) ? 1 : 0;
        ceve += (arr[i] % 2 == 0) ? 1 : 0;
        codd += (arr[i] % 2 != 0) ? 1 : 0;
    }
    printf("Odd numbers: %d\nEven numbers: %d\nPositive Numbers: %d\nNegative Numbers: %d\n", codd, ceve, cpos, cneg);
}