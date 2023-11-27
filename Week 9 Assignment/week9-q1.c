// Create a program to count the number of vowels in a given string.
#include <stdio.h>

void main()
{
    char str[] = "HellO WoRlD";
    int count, vowelcount = 0;
    while (str[count] != '\0')
    {
        if (str[count] == 'A' || str[count] == 'E' || str[count] == 'I' || str[count] == 'O' || str[count] == 'U' || str[count] == 'a' || str[count] == 'e' || str[count] == 'i' || str[count] == 'o' || str[count] == 'u')
        {
            vowelcount++;
        }
        count++;
    }
    printf("Number of vowels in \'%s\': %d", str, vowelcount);
}