// Find out the reverse of a user-given string using Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size;

int *createStack(int size)
{
    int *stack = (int *)malloc(size * sizeof(int));
    return stack;
}

int chkfull(int top)
{
    return (top == size - 1);
}

void push(int *stack, int *top, char item)
{
    if (chkfull(*top))
    {
        printf("Stack is full\n");
        return;
    }
    stack[++(*top)] = item;
}

char pop(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty!\n");
        return '\0';
    }
    return stack[(*top)--];
}

void reverseString(char *string)
{
    size = strlen(string);
    int *stack = createStack(size);
    int top = -1, i;

    for (i = 0; string[i] != '\0'; ++i)
    {
        push(stack, &top, string[i]);
    }

    printf("Reversed string: ");
    while (top != -1)
    {
        printf("%c", pop(stack, &top));
    }
    printf("\n");

    free(stack);
}

void main()
{
    char string[1000];
    printf("Enter string: ");
    scanf("%[^\n]", string);

    reverseString(string);
}