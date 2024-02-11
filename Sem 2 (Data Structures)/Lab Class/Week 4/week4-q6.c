// Write a program to delete the first and middle node from the Singly Linked List. [Note: For this problem, consider that a Singly Linked List contains only an odd number of nodes].
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
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

void deleteFirstNode(struct Node **head)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteMiddleNode(struct Node **head)
{
    struct Node *slowPtr, *fastPtr, *prev;
    slowPtr = fastPtr = *head;
    prev = NULL;

    while (fastPtr != NULL && fastPtr->next != NULL)
    {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    if (prev != NULL)
    {
        prev->next = slowPtr->next;
        free(slowPtr);
    }
}

void printList(struct Node *head)
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

    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    printf("Original linked list: \n");
    printList(head);

    deleteFirstNode(&head);
    printf("Linked list after deleting the first node: \n");
    printList(head);

    deleteMiddleNode(&head);
    printf("Linked list after deleting the middle node: \n");
    printList(head);
}
