// Write a C program that test whether two words are anagrams
#include <stdio.h>
#include <string.h>

void countChar(char str[], int count[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        count[str[i] - 'a']++;
    }
}

int isanag(char str1[], char str2[])
{
    int count1[26] = {0}, count2[26] = {0};
    int i;

    countChar(str1, count1);
    countChar(str2, count2);

    for (i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    char str1[] = "seashore", str2[] = "seahorse";

    if (isanag(str1, str2))
    {
        printf("\'%s\' and \'%s\' are anagrams.", str1, str2);
    }
    else
    {
        printf("\'%s\' and \'%s\' are not anagrams.", str1, str2);
    }
}