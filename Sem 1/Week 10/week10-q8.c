// Write a program that will read a line and delete from it all occurrences of the word ‘the’.
#include <stdio.h>
#include <string.h>

void deleteWord(char *str, const char *word)
{
    char *ptr = str;

    while ((ptr = strstr(ptr, word)) != NULL)
    {
        memmove(ptr, ptr + strlen(word), strlen(ptr + strlen(word)) + 1);
    }
}

int main()
{
    char line[1000];

    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);

    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
    {
        line[len - 1] = '\0';
    }

    deleteWord(line, "the");
    printf("Modified line: %s\n", line);
}