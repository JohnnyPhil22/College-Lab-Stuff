// Take two Singly Linked Lists as input from the user. Nodes of the Linked List should contain integer values as data value. Now, your program should be able to display a new Singly Linked List (from the user-given Linked Lists) which have the comparatively greater element at each node.
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
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head_ref, int data)
{
    struct Node *newNode = createNode(data);
    if (!newNode)
    {
        return;
    }

    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

struct Node *mergeLists(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {
        int greaterData = (temp1->data > temp2->data) ? temp1->data : temp2->data;
        insertAtEnd(&result, greaterData);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != NULL)
    {
        insertAtEnd(&result, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        insertAtEnd(&result, temp2->data);
        temp2 = temp2->next;
    }

    return result;
}

void print_list(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head1 = NULL, *head2 = NULL;
    int n, i, elem;

    printf("Linked list 1:\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data in node %d: ", i + 1);
        scanf("%d", &elem);
        insertAtEnd(&head1, elem);
    }

    printf("\nLinked list 2:\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter data in node %d: ", i + 1);
        scanf("%d", &elem);
        insertAtEnd(&head2, elem);
    }

    printf("\nLinked list 1: ");
    print_list(head1);
    printf("Linked list 2: ");
    print_list(head2);

    struct Node *head3 = mergeLists(head1, head2);
    printf("Merged list with greater elements: ");
    print_list(head3);
}