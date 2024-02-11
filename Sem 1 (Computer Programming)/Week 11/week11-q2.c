// Create a structure called library to hold accession number, title of the book, author name, price of the book, and flag indicating whether book is issued or not. Write a menu-driven program that implements the working of a library. The menu options should be add book information, Display book information, List all books of given author, List the title of specified book, List the count of books in the library, List the books in the order of accession number and Exit.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Library
{
    int accessno;
    char title[100];
    char author[100];
    float price;
    int flag;
};

int main()
{
    int choice;
    int count = 0;
    struct Library library[100];

    while (choice != 7)
    {
        printf("Please enter all string inputs without any spaces\n1. Add book information\n2. Display book information\n3. List all books of given author\n4. List the title of specified book\n5. List the count of books in the library\n6. List the books in the order of accession number\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            if (count < 100)
            {
                int noofbooks;
                printf("Enter number of books to add: ");
                scanf("%d", &noofbooks);
                for (int i = 0; i < noofbooks; i++)
                {
                    printf("\nEnter book information:\n");
                    printf("Accession Number: ");
                    scanf("%d", &library[count].accessno);

                    printf("Title: ");
                    scanf("%s", &library[count].title);

                    printf("Author: ");
                    scanf("%s", &library[count].author);

                    printf("Price: ");
                    scanf("%f", &library[count].price);

                    printf("Is the book issued? (1 for Yes, 0 for No): ");
                    scanf("%d", &library[count].flag);

                    count++;
                }
            }
            else
            {
                printf("Library is full. Cannot add more books.\n");
            }
            break;

        case 2:
            printf("\nBook Information:\n");
            for (int i = 0; i < count; i++)
            {
                printf("Accession Number: %d\n", library[i].accessno);
                printf("Title: %s\n", library[i].title);
                printf("Author: %s\n", library[i].author);
                printf("Price: %.2f\n", library[i].price);
                printf("Issued: %s\n", library[i].flag ? "Yes" : "No");
                printf("\n");
            }
            break;

        case 3:
        {
            char searchAuthor[100];
            printf("\nEnter author's name: ");
            scanf("%s", &searchAuthor);
            while (getchar() != '\n')
                ;

            printf("\nBooks by author %s:\n", searchAuthor);
            for (int i = 0; i < count; i++)
            {
                if (strcmp(library[i].author, searchAuthor) == 0)
                {
                    printf("Title: %s\n", library[i].title);
                }
            }
        }
        break;

        case 4:
        {
            int searchaccessno;
            printf("\nEnter Accession Number: ");
            scanf("%d", &searchaccessno);
            while (getchar() != '\n')
                ;

            int found = 0;
            for (int i = 0; i < count; i++)
            {
                if (library[i].accessno == searchaccessno)
                {
                    printf("\nTitle of the book with Accession Number %d: %s\n", searchaccessno, library[i].title);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("\nBook not found with Accession Number %d\n", searchaccessno);
            }
        }
        break;

        case 5:
            printf("\nNumber of books in the library: %d\n", count);
            break;

        case 6:
            printf("\nBooks in the order of accession number:\n");
            for (int i = 0; i < count; i++)
            {
                printf("Accession Number: %d, Title: %s, Author: %s, Price :%.2f\n", library[i].accessno, library[i].title, library[i].author, library[i].price);
            }
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
