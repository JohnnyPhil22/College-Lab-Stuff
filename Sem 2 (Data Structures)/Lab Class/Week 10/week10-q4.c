// Create an unsorted Doubly Linked List containing n nodes. Remove duplicate nodes from the Doubly Linked List.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head, *tail = NULL;

void insert(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = tail = newNode;
        head->prev = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = NULL;
    }
}

void traverse()
{
    struct Node *current = head;
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deldup()
{
    struct Node *current, *index, *temp;

    if (head == NULL)
    {
        return;
    }
    else
    {
        for (current = head; current != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data == index->data)
                {
                    temp = index;
                    index->prev->next = index->next;
                    if (index->next != NULL)
                    {
                        index->next->prev = index->prev;
                    }
                    temp = NULL;
                }
            }
        }
    }
}

void main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int i, elem;
    for (i = 1; i <= n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &elem);
        insert(elem);
    }

    printf("List before removing duplicates: ");
    traverse();

    deldup();

    printf("List after removing duplicates: ");
    traverse();
}