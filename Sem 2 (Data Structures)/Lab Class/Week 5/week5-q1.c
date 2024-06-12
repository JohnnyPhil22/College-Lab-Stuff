// Create a Circular Linked List. Your program should take integer data values to be stored in the nodes as input from the user. Now, increment the data value of every node present in the circular list by 150. Write code to display the data present within the nodes of the Circular Linked List before and after the increment.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL)
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else
    {
        newNode->next = newNode;
    }
    *head = newNode;
}

void print_list(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        while (temp != head)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
    printf("NULL\n");
}

int inc_150(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        while (temp != head)
        {
            temp->data += 150;
            temp = temp->next;
        }
    }
}

void main()
{
    struct Node *head = NULL;
    int n, i, elem;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data in node %d: ", i + 1);
        scanf("%d", &elem);
        push(&head, elem);
    }
    printf("List before increment: ");
    print_list(head);

    inc_150(head);
    printf("List after increment: ");
    print_list(head);
}