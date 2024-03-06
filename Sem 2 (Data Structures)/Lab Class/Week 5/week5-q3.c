// Create a Doubly Linked List where data values are taken as input from the user as positive & negative integers. Your program should be able to traverse the Doubly Linked List of positive & negative integers. Now, delete all nodes from the Doubly Linked List whose data values are negative. Print the address of the remaining nodes present within the Doubly Linked List.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNegativeNodes(struct Node **head)
{
    struct Node *current = *head;
    while (current != NULL)
    {
        if (current->data < 0)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                *head = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            struct Node *temp = current;
            current = current->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
}

void printAddresses(struct Node *head)
{
    while (head != NULL)
    {
        printf("%p\n", (void *)head);
        head = head->next;
    }
}

void main()
{
    struct Node *head = NULL;
    int n, i, data;
    char choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data in node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("\nAddresses of all nodes before deletion:\n");
    printAddresses(head);

    deleteNegativeNodes(&head);

    printf("\nAddresses of remaining nodes after deletion of negative values:\n");
    printAddresses(head);
}