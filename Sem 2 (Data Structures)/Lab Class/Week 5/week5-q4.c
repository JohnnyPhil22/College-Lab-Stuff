// Create a Singly Linked List where a number of the nodes present within the Singly Linked List are taken as input from the user. Your program should be able to traverse the Singly Linked List. Now, return the data in the node which contains the smallest value.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *next;
};

void push(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = data;
    newNode->next = (*head);
    (*head) = newNode;
}

int min_elem(struct Node *head)
{
    int min = head->info;
    while (head != NULL)
    {
        if (min > head->info)
        {
            min = head->info;
        }
        head = head->next;
    }
    return min;
}

void print_list(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->info);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
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

    printf("Linked list: ");
    print_list(head);

    int min = min_elem(head);
    printf("Minimum element in list: %d\n", min);
}