// Create a Singly Linked List of size 10. Traverse it and return the data in the node with the smallest key value.
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
    newNode->next = (*head);
    (*head) = newNode;
}

void traverse(struct Node *node)
{
    struct Node *current = node;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int minimum(struct Node *node)
{
    struct Node *current = node;
    int minim = current->data;
    while (current != NULL)
    {
        if (current->data < minim)
        {
            minim = current->data;
        }
        current = current->next;
    }
    return minim;
}

void main()
{
    struct Node *root = NULL;

    int i, elem;
    for (i = 1; i <= 10; i++)
    {
        printf("Enter element: ");
        scanf("%d", &elem);
        insert(&root, elem);
    }

    printf("Linked list: ");
    traverse(root);

    printf("Minimum element in list: %d\n", minimum(root));
}