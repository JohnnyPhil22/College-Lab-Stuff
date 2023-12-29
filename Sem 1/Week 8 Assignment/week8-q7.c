// Write a program in C to compare two strings without using any standard library string functions.
#include <stdio.h>

int str_cmp(const char *string1, const char *string2)
{
    while (*string1 != '\0' && *string2 != '\0')
    {
        if (*string1 != *string2)
        {
            return 0;
        }
        string1++;
        string2++;
    }

    if (*string1 == '\0' && *string2 == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    char str1[] = "Hello";
    char str2[] = "World";

    if (str_cmp(str1, str2))
    {
        printf("The strings are equal.\n");
    }
    else
    {
        printf("The strings are not equal.\n");
    }
}