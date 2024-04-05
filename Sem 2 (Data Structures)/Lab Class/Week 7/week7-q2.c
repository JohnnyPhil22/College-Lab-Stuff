// Delete the nth element of a Linear Queue. Firstly, your program should check if the queue is empty or if the position to delete is invalid. If the position is valid, this program should delete the first n − 1 elements, then it should delete the nth element by calling the Dequeue() function.
#include <stdio.h>
int front = -1, rear = -1;

void enqueue(int arr[], int value, int size)
{
    if (rear == size - 1)
        printf("Full Queue\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = value;
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Empty Queue\n");
    }
    else
    {
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display(int arr[])
{
    if (rear == -1)
        printf("Empty Queue\n");
    else
    {
        int i;
        printf("Queue elements: ");
        for (i = front; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int size;
    printf("Enter size of queue: ");
    scanf("%d", &size);

    int i, arr[size], elem;
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &elem);
        enqueue(arr, elem, size);
    }

    int delpos;
    printf("Enter position to delete: ");
    scanf("%d", &delpos);
    if (delpos > size)
    {
        printf("Error: Invalid position\n");
    }
    else
    {
        for (i = 0; i < delpos; i++)
        {
            dequeue();
        }
        display(arr);
    }
}
