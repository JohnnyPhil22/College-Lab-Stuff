// Write a program in C to copy the contents of one string into another without using any standard library string functions.
#include <stdio.h>

void str_copy(char *src, char *dest)
{
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

void main()
{
    char str[] = "Hello, World!";
    int count;
    while (str[count] != 0)
    {
        count++;
    }

    char newstr[count];

    str_copy(str, newstr);

    printf("Original string: \"%s\"\nNew string: \"%s\"\n", str, newstr);
}