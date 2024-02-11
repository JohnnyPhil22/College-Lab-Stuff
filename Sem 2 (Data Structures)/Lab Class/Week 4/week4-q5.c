// Write a program to create a Singly Linked List. Further, include functions in your program to insert a node at the beginning and at the end of the Singly Linked List.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_node(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void add_at_beginning(struct Node **head, int data)
{
    struct Node *newNode = create_node(data);
    newNode->next = *head;
    *head = newNode;
}

void add_at_end(struct Node **head, int data)
{
    struct Node *newNode = create_node(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void print_list(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void main()
{
    struct Node *head = NULL;

    add_at_beginning(&head, 10);
    add_at_beginning(&head, 20);
    add_at_beginning(&head, 30);

    printf("Linked list after inserting nodes at the beginning: \n");
    print_list(head);

    add_at_end(&head, 40);
    add_at_end(&head, 50);

    printf("Linked list after inserting nodes at the end: \n");
    print_list(head);
}
