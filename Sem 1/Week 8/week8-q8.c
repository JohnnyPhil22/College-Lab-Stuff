// Write a program in C to check a whether a given string is palindrome or not.
#include <stdio.h>

int palinchk(char string1[], char string2[])
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
    char str[] = "abba";
    int count;
    while (str[count] != 0)
    {
        count++;
    }
    char revstr[count + 1];

    for (int i = 0; i < count; i++)
    {
        revstr[i] = str[count - i - 1];
    }
    revstr[count] = '\0';

    if (palinchk(str, revstr))
    {
        printf("%s is palindrome\n", str);
    }
    else
    {
        printf("%s is not palindrome\n", str);
    }
}