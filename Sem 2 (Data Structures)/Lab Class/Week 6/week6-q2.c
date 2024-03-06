// Write a menu-driven program to implement Queue using Array that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

#define max 10

int queue[max];
int rear = -1, front = -1;

/// Insert user-given integer elements in the Queue using Enqueue operations.
void enqueue(int item)
{
    if (rear == max - 1)
    {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

/// Delete elements from the Queue.
int dequeue()
{
    int temp;
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
        return -1;
    }
    temp = queue[front];
    front++;
    return temp;
}

/// Check whether Queue is empty or not.
int isEmpty()
{
    if (front == -1 || front == rear + 1)
        return 1;
    else
        return 0;
}

/// Check whether Queue is full or not.
int isFull()
{
    if (rear == max - 1)
        return 1;
    else
        return 0;
}

/// Display all the elements present in the Queue.
void display()
{
    int i;
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in queue:\n");
    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

/// Print the address of Front and Rear pointer after insertion operations.
void frontrearadd(int item)
{
    if (rear == max - 1)
    {
        printf("Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = item;

    printf("Address of front pointer after insertion: %p\n", (void *)&front);
    printf("Address of rear pointer after insertion: %p\n", (void *)&rear);
}

void main()
{
    int ch, elem, count = 0;
    do
    {
        printf("\n1. Insert element\n2. Count number of elements\n3. Display all elements\n4. Check if queue is full or not\n5. Print address of front and rear pointers after insertion\n6. Delete elements\n7. Check if empty\n8. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &elem);
            enqueue(elem);
            count++; /// Count the number of elements present in the Queue.
            break;
        case 2:
            printf("Number of elements: %d\n", count);
            break;
        case 3:
            display();
            break;
        case 4:
            if (isFull())
            {
                printf("Queue is full");
            }
            else
            {
                printf("Queue is not full");
            }
            break;
        case 5:
            printf("Enter element: ");
            scanf("%d", &elem);
            frontrearadd(elem);
            break;
        case 6:
            dequeue();
            break;
        case 7:
            if (isEmpty())
            {
                printf("Queue is empty");
            }
            else
            {
                printf("Queue is not empty");
            }
            break;
        case 8:
            printf("Exiting...");
            break;
        default:
            printf("Please enter a valid option.\n");
        }
    } while (ch != 8);
}