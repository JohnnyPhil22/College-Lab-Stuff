// Implement Priority Queue program using Array that can perform the following operations:
#include <stdio.h>
#include <stdbool.h>

#define MAX 5
int arr[MAX], rear = -1;

// Insert user-given integer elements in the Priority Queue.
void insert(int data)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    int i = rear;
    while (i >= 0 && data > arr[i])
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = data;
    rear++;
}

// Display all the elements present in the Priority Queue.
void display()
{
    if (rear == -1)
    {
        printf("Empty Queue\n");
        return;
    }
    int i;
    for (i = 0; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

// Count the number of elements present in the Priority Queue.
int count()
{
    return rear + 1;
}

// Check whether the Priority Queue is full or not.
bool isFull()
{
    return rear == MAX - 1;
}

// Check whether the Priority Queue is empty or not.
bool isEmpty()
{
    return rear == -1;
}

// Delete elements from the Priority Queue.
int dequeue()
{
    if (isEmpty())
    {
        printf("Empty Queue\n");
        return -1;
    }

    int deleted = arr[0], i;
    for (i = 0; i < rear; i++)
    {
        arr[i] = arr[i + 1];
    }
    rear--;
    return deleted;
}

void main()
{
    int ch, elem;
    do
    {
        printf("1. Insert\n2. Count number of elements\n3. Display\n4. Check if queue is full\n5. Delete\n6. Check if queue is empty\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &elem);
            insert(elem);
            break;

        case 2:
            printf("Count of elements: %d\n", count());
            break;

        case 3:
            printf("Queue elements: ");
            display();
            break;

        case 4:
            if (isFull())
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
            break;

        case 5:
            printf("Deleted %d from queue\n", dequeue());
            break;

        case 6:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;

        case 7:
            break;

        default:
            printf("Please enter a valid option\n");
        }
    } while (ch != 7);
}