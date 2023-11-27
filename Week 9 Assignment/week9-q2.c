// Implement a function to perform basic string compression. (e.g., "aabcccccaaa" -> "a2b1c5a3").
#include <stdio.h>
#include <string.h>

void strcmprs(char *str)
{
    int length = strlen(str);
    if (length == 0)
    {
        return;
    }

    char cmprsd[length * 2], curchar = str[0];
    int cmprsdindx = 0, count = 1;

    for (int i = 1; i < length; i++)
    {
        if (str[i] == curchar)
        {
            count++;
        }
        else
        {
            cmprsd[cmprsdindx++] = curchar;
            cmprsd[cmprsdindx++] = (char)('0' + count);

            count = 1;
            curchar = str[i];
        }
    }

    cmprsd[cmprsdindx++] = curchar;
    cmprsd[cmprsdindx++] = (char)('0' + count);

    cmprsd[cmprsdindx] = '\0';

    printf("Compressed string: %s", cmprsd);
}

void main()
{
    char str[] = "aabcccccaaa";
    printf("Original string: %s\n", str);
    strcmprs(str);
}