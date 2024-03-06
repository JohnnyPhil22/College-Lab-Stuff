// Write a menu-driven program to implement Stack using Linked List that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

/// Insert user-given integer elements in the Stack.
void push(struct Node **top, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

/// Check whether Stack is empty or not.
int isEmpty(struct Node *top)
{
    return top == NULL;
}

/// Count the number of elements present in the Stack.
int count(struct Node *top)
{
    int count = 0;
    struct Node *current = top;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

/// Display all the elements present in the Stack.
void display(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the Stack: ");
    struct Node *current = top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/// Find out the largest element present in the Stack.
int largest(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return -1;
    }
    int largest = top->data;
    struct Node *current = top->next;
    while (current != NULL)
    {
        if (current->data > largest)
            largest = current->data;
        current = current->next;
    }
    return largest;
}

void main()
{
    struct Node *top = NULL;

    int ch, elem;

    do
    {
        printf("1. Push\n2. Count elements\n3. Display elements\n4. Check if Stack is full\n5. Find largest element\n6. Check if Stack is empty\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &elem);
            push(&top, elem);
            break;
        case 2:
            printf("Number of elements in the Stack: %d\n", count(top));
            break;
        case 3:
            display(top);
            break;
        case 4:
            printf("Stack is never full in linked list implementation\n"); /// Check whether Stack is full or not.
            break;
        case 5:
            printf("Largest element in the Stack: %d\n", largest(top));
            break;
        case 6:
            if (isEmpty(top))
                printf("Stack is empty\n");
            else
                printf("Stack is not empty\n");
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Please enter a valid option\n");
        }
    } while (ch != 7);
}