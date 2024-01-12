// Write a program in C to reverse a given string without using any standard library string functions.
#include <stdio.h>

void strrev(char string[])
{
    int count;
    while (string[count] != 0)
    {
        count++;
    }
    char revstr[count + 1];

    for (int i = 0; i < count; i++)
    {
        revstr[i] = string[count - i - 1];
    }
    revstr[count] = '\0';

    printf("\"%s\" reversed: %s", string, revstr);
}

void main()
{
    char str[] = "Hello";
    strrev(str);
}