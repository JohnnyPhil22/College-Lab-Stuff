// Write a program to create a Singly Linked List where elements to be inserted into the Singly Linked List are taken as input from the user. Print the address of the last node of the Singly Linked List.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void traverse()
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

void print_address()
{
    struct Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    printf("\nAddress of last node: 0x%p", current);
}

void main()
{
    int n, i, elem;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &elem);
        insert(elem);
    }

    printf("List: ");
    traverse();
    print_address();
}