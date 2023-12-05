// Write a program to copy contents of one file to another. While doing so replace all lowercase characters to their equivalent uppercase characters.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main()
{
    FILE *file1 = fopen("C:\\Users\\Jonathan Philips\\OneDrive\\Desktop\\C-and-CPP-Projects-College\\Week 11 Assignment\\example.txt", "r");
    FILE *file2 = fopen("C:\\Users\\Jonathan Philips\\OneDrive\\Desktop\\C-and-CPP-Projects-College\\Week 11 Assignment\\example3.txt", "w");

    char ch;

    if (file1 == NULL)
    {
        perror("Error opening source file");
        exit(1);
    }

    if (file2 == NULL)
    {
        perror("Error opening destination file");
        fclose(file1);
        exit(1);
    }

    while ((ch = fgetc(file1)) != EOF)
    {
        if (tolower(ch))
        {
            ch = toupper(ch);
        }
        fputc(ch, file2);
    }

    fclose(file1);
    fclose(file2);

    printf("Contents copied successfully\n");
}