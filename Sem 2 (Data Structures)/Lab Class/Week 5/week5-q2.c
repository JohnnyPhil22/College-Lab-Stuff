// Write a menu-driven program for creation of the Doubly Linked List consisting of integer data values within nodes. Your program should be able to perform following operations based on the user’s choice:
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

/// Count the number of nodes present within the Doubly Linked List.
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

/// Delete the node present at the end of the Doubly Linked List.
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }
    free(temp);
}

/// Insert the node at the beginning of the Doubly Linked List.
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

/// Print the address of the previous and next node corresponding to the node containing ‘data value’ as given by the user.
void printPrevNextAddress(struct Node *head, int data)
{
    while (head != NULL)
    {
        if (head->data == data)
        {
            printf("Address of the previous node: %p\n", (void *)head->prev);
            printf("Address of the next node: %p\n", (void *)head->next);
            return;
        }
        head = head->next;
    }
    printf("Node with data value %d not found in the list.\n", data);
}

/// Print the address of the node having maximum data value in the Doubly Linked List.
void printMaxAddress(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *maxNode = head;
    while (head != NULL)
    {
        if (head->data > maxNode->data)
        {
            maxNode = head;
        }
        head = head->next;
    }
    printf("Address of the node with maximum data value (%d): %p\n", maxNode->data, (void *)maxNode);
}

/// Print the address of the nodes having 'odd value' within nodes.
void printOddValueAddresses(struct Node *head)
{
    printf("Addresses of nodes with odd data values:\n");
    while (head != NULL)
    {
        if (head->data % 2 != 0)
        {
            printf("%p\n", (void *)head);
        }
        head = head->next;
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
        insertAtEnd(&head, elem);
    }

    int ch, data;
    do
    {
        printf("1. Count the number of nodes\n2. Delete the node present at the end\n3. Insert a node at the beginning\n4. Print the address of the previous and next node corresponding to the node containing 'data value'\n5. Print the address of the node having maximum data value\n6. Print the address of the nodes having odd value within nodes\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Number of nodes in the Doubly Linked List: %d\n", countNodes(head));
            break;
        case 2:
            deleteAtEnd(&head);
            printf("Node at the end deleted successfully.\n");
            printf("Number of nodes in the Doubly Linked List: %d\n", countNodes(head));
            break;
        case 3:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            printf("Node inserted at the beginning successfully.\n");
            break;
        case 4:
            printf("Enter data value: ");
            scanf("%d", &data);
            printPrevNextAddress(head, data);
            break;
        case 5:
            printMaxAddress(head);
            break;
        case 6:
            printOddValueAddresses(head);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Please enter a valid option.\n");
        }
    } while (ch != 7);
}
