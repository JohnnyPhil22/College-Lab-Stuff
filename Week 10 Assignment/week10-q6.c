// Write a C program that reads a message, then prints the reversal of the message.
#include <stdio.h>
#include <string.h>

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

    printf("Reversed message: ");
    for (int i = strlen(message) - 1; i >= 0; --i)
    {
        printf("%c", message[i]);
    }
    printf("\n");
}

// Revise the program to use a pointer instead of an integer to keep track of the current position in the array.
#include <stdio.h>
#include <string.h>

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

    printf("Reversed message: ");
    char *ptr = message + strlen(message) - 1;

    while (ptr >= message)
    {
        printf("%c", *ptr);
        ptr--;
    }
    printf("\n");
}