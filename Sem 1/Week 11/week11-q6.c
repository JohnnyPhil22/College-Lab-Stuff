// Write a program to append the contents of one file at the end of another.
#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *file1 = fopen("C:\\Users\\Jonathan Philips\\OneDrive\\Desktop\\C-and-CPP-Projects-College\\Week 11 Assignment\\example.txt", "r");
    FILE *file2 = fopen("C:\\Users\\Jonathan Philips\\OneDrive\\Desktop\\C-and-CPP-Projects-College\\Week 11 Assignment\\example2.txt", "a");

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
        fputc(ch, file2);
    }

    fclose(file1);
    fclose(file2);

    printf("Contents appended successfully\n");
}