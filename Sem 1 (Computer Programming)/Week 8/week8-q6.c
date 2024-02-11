// Write a program in C to concatenate two strings without using any standard library string functions.
#include <stdio.h>

void str_cat(char *dest, const char *src)
{
    while (*dest)
    {
        dest++;
    }
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

void main()
{
    char str1[] = "Hello, ";
    char str2[] = "World!";
    printf("String 1: %s\nString 2: %s\n", str1, str2);

    str_cat(str1, str2);
    printf("New string: %s", str1);
}