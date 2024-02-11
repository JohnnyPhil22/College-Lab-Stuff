// Write a C program that reads a message, then checks whether it's a palindrome
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *str)
{
    int len = strlen(str);
    int i = 0, j = len - 1;

    while (i < j)
    {
        while (i < j && !isalnum(str[i]))
        {
            i++;
        }

        while (i < j && !isalnum(str[j]))
        {
            j--;
        }

        if (tolower(str[i]) != tolower(str[j]))
        {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}

int main()
{
    char message[1000];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n')
    {
        message[len - 1] = '\0';
    }

    if (isPalindrome(message))
    {
        printf("Palindrome.\n");
    }
    else
    {
        printf("Not a palindrome.\n");
    }
}

// Revise the program to use pointers instead of integers to keep track of positions in the array
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *str)
{
    int len = strlen(str);
    const char *start = str;
    const char *end = str + len - 1;

    while (start < end)
    {
        while (start < end && !isalnum(*start))
        {
            start++;
        }

        while (start < end && !isalnum(*end))
        {
            end--;
        }

        if (tolower(*start) != tolower(*end))
        {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

int main()
{
    char message[1000];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n')
    {
        message[len - 1] = '\0';
    }

    if (isPalindrome(message))
    {
        printf("The entered message is a palindrome.\n");
    }
    else
    {
        printf("The entered message is not a palindrome.\n");
    }
}