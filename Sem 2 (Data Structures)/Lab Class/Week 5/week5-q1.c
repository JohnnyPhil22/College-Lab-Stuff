// Create a Circular Linked List. Your program should take integer data values to be stored in the nodes as input from the user. Now, increment the data value of every node present in the circular list by 150. Write code to display the data present within the nodes of the Circular Linked List before and after the increment.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

void push(struct Node **head_ref, int data)
{
    struct Node *ptr1 = (struct Node *)malloc(sizeof(struct Node));
    ptr1->info = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL)
    {
        struct Node *temp = *head_ref;
        while (temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = ptr1;
    }
    else
    {
        ptr1->next = ptr1;
    }
    *head_ref = ptr1;
}

void print_list(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d -> ", temp->info);
            temp = temp->next;
        } while (temp != head);
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
        do
        {
            temp->info += 150;
            temp = temp->next;
        } while (temp != head);
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