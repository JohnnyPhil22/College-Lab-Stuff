// Menu-driven program in C to implement Circular Queue using Array that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Check whether the Circular Queue is empty or not.
int isEmpty()
{
    return front == -1 && rear == -1;
}

// Check whether the Circular Queue is full or not.
int isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

// Insert user-given integer elements in the Circular Queue using Enqueue operations.
void enqueue(int value)
{
    if (isFull())
    {
        printf("Full Queue\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = value;
}

// Delete elements from the Circular Queue.
void dequeue()
{
    if (isEmpty())
    {
        printf("Empty Queue\n");
        return;
    }
    int removedValue = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Element %d dequeued successfully.\n", removedValue);
}

// Count the number of elements present in the Circular Queue.
int count()
{
    if (isEmpty())
    {
        return 0;
    }
    return (rear - front + MAX_SIZE) % MAX_SIZE + 1;
}

// Display all the elements present in the Circular Queue.
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the Circular Queue are: ");
    int i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

// Print the address of Front and Rear pointer after insertion operations.
void printPointers()
{
    printf("Front pointer: %p\n", (void *)&front);
    printf("Rear pointer: %p\n", (void *)&rear);
}

int main()
{
    int ch, elem;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Count elements\n4. Display elements\n5. Check if Queue is full\n6. Check if Queue is empty\n7. Print pointers\n8. Exit\nEnter your choice: ");
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
            printf("Number of elements in the Circular Queue: %d\n", count());
            break;
        case 4:
            display();
            break;
        case 5:
            if (isFull())
                printf("Full Queue\n");
            else
                printf("Not Full Queue\n");
            break;
        case 6:
            if (isEmpty())
                printf("Empty Queue\n");
            else
                printf("Not Empty Queue\n");
            break;
        case 7:
            printPointers();
            break;
        case 8:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Please enter a valid option.\n");
        }
    } while (1);
}
