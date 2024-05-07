// Swap the two adjacent nodes in a Circular Linked List.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data)
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

void traverse(struct Node *head)
{
    struct Node *current = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("\n");
}

void swap(struct Node **head)
{
    if (*head == NULL || (*head)->next == *head)
    {
        return;
    }

    struct Node *current = *head;
    do
    {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        current = current->next->next;
    } while (current != *head);
}

void main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    struct Node *root = NULL;
    int i, elem;
    for (i = 1; i <= n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &elem);
        insert(&root, elem);
    }

    printf("List before swapping: ");
    traverse(root);

    swap(&root);

    printf("List after swapping: ");
    traverse(root);
}