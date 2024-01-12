// Determine if one string is a rotation of another. (e.g., "waterbottle" is a rotation of "erbottlewat").
#include <stdio.h>
#include <string.h>

int isrot(const char *str1, const char *str2)
{
    int len1 = strlen(str1), len2 = strlen(str2);

    if (len1 == len2 && len1 > 0)
    {
        char temp[2 * len1 + 1];
        strcpy(temp, str1);
        strcat(temp, str1);

        if (strstr(temp, str2) != NULL)
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void main()
{
    char str1[] = "erbottlewat", str2[] = "waterbottle";
    if (isrot(str1, str2))
    {
        printf("\'%s\' is a rotation of \'%s\'", str1, str2);
    }
    else
    {
        printf("\'%s\' is not a rotation of \'%s\'", str1, str2);
    }
}