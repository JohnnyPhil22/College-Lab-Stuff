// Count the number of occurrences of an element in a Linked List without using recursion.
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

int count(struct Node *node, int elem)
{
    int count = 0;
    struct Node *current = node;
    while (current != NULL)
    {
        if (current->data == elem)
        {
            count += 1;
        }
        current = current->next;
    }
    return count;
}

void main()
{
    struct Node *root = NULL;

    int num;
    printf("Enter number of elements in list: ");
    scanf("%d", &num);

    int i, elem;
    for (i = 1; i <= num; i++)
    {
        printf("Enter element: ");
        scanf("%d", &elem);
        insert(&root, elem);
    }

    int srch;
    printf("Enter element to search: ");
    scanf("%d", &srch);
    printf("%d occurs %d times\n", srch, count(root, srch));
}