// Implement Circular Queue using Linked List that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;
int count = 0;

// Check whether the Circular Queue is empty or not.
int isEmpty()
{
    return front == NULL;
}

// Insert user-given integer elements in the Circular Queue.
void enqueue(int value)
{
    if (count >= MAX_SIZE)
    { // Check whether the Circular Queue is full or not.
        printf("Circular Queue overflow\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = rear = newNode;
        rear->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    count++; // Count the number of elements present in the Circular Queue.
}

// Delete elements from the Circular Queue.
void dequeue()
{
    if (isEmpty())
    {
        printf("Circular Queue underflow\n");
        return;
    }
    struct Node *temp = front;
    int removedValue = front->data;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
    count--;
    printf("Element %d dequeued\n", removedValue);
}

// Display all the elements present in the Circular Queue.
void display()
{
    if (isEmpty())
    {
        printf("Empty Circular Queue\n");
        return;
    }
    struct Node *temp = front;
    printf("Elements in the Circular Queue are: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Print the address of Front and Rear pointer after insertion operations.
void printPointers()
{
    printf("Front pointer: %p\n", (void *)front);
    printf("Rear pointer: %p\n", (void *)rear);
}

int main()
{
    int ch, elem;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Count elements\n4. Display elements\n5. Check if Queue is empty\n6. Print pointers\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &elem);
            enqueue(elem);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printf("Number of elements: %d\n", count);
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty())
                printf("Empty Circular Queue\n");
            else
                printf("Circular Queue not empty\n");
            break;
        case 6:
            printPointers();
            break;
        case 7:
            exit(0);
        default:
            printf("Enter a valid option\n");
        }
    } while (1);
}