// Implement Double Ended Queue that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int deque[MAX_SIZE];
int front = -1, rear = -1;

// Check whether Queue is empty or not.
int isEmpty()
{
    return front == -1 && rear == -1;
}

// Check whether Queue is full or not.
int isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

// Insert user-given integer elements into the Queue.
void insertFront(int value)
{
    if (isFull())
    {
        printf("Full Deque\n");
        return;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque[front] = value;
}

void insertRear(int value)
{
    if (isFull())
    {
        printf("Full Deque\n");
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
    deque[rear] = value;
}

// Delete elements from the Queue.
void deleteFront()
{
    if (isEmpty())
    {
        printf("Empty Deque\n");
        return;
    }
    int removedValue = deque[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    printf("Element %d deleted from the front.\n", removedValue);
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Empty Deque\n");
        return;
    }
    int removedValue = deque[rear];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    printf("Element %d deleted from the rear.\n", removedValue);
}

// Count the number of elements present in the Queue.
int count()
{
    if (isEmpty())
    {
        return 0;
    }
    return (rear - front + MAX_SIZE) % MAX_SIZE + 1;
}

// Display all the elements present in the Queue.
void display()
{
    if (isEmpty())
    {
        printf("Empty Deque.\n");
        return;
    }
    printf("Elements in the Deque: ");
    int i = front;
    do
    {
        printf("%d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    printf("\n");
}

int main()
{
    int ch, elem;
    do
    {
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Count elements\n6. Display elements\n7. Check if Deque is full\n8. Check if Deque is empty\n9. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to insert at front: ");
            scanf("%d", &elem);
            insertFront(elem);
            break;
        case 2:
            printf("Enter the element to insert at rear: ");
            scanf("%d", &elem);
            insertRear(elem);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            printf("Number of elements: %d\n", count());
            break;
        case 6:
            display();
            break;
        case 7:
            if (isFull())
                printf("Full Deque\n");
            else
                printf("Not Full Deque\n");
            break;
        case 8:
            if (isEmpty())
                printf("Empty Deque\n");
            else
                printf("Not Empty Deque\n");
            break;
        case 9:
            exit(0);
        default:
            printf("Enter a valid option\n");
        }
    } while (1);
}