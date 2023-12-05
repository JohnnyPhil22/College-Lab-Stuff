// Write a program to read a file and display its contents along with line numbers before each line.
#include <stdio.h>

void main()
{
    FILE *file = fopen("C:\\Users\\Jonathan Philips\\OneDrive\\Desktop\\C-and-CPP-Projects-College\\Week 11 Assignment\\example.txt", "r");

    if (file == NULL)
    {
        perror("Error opening the file");
    }

    int lineNumber = 1;
    char line[1000];

    printf("File contents:\n");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%d: %s", lineNumber, line);
        lineNumber++;
    }

    fclose(file);
}