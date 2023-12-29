// Write a program in C to find the length of a given string without using any standard library string functions.
#include <stdio.h>

int str_len(char string[])
{
    int count;
    while (string[count] != 0)
    {
        count++;
    }
    return count;
}

void main()
{
    char string[] = "Hello, World!";
    printf("Length of string \"%s\": %d", string, str_len(string));
}