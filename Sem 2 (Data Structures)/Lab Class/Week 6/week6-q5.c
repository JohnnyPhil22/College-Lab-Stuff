// Write a menu-driven program to implement Queue using Linked List. Your program should be able to perform the following operations:
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

/// Insert user-given integer elements in the Queue.
void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

/// Check whether Queue is empty or not.
int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

/// Delete elements from the Queue.
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

/// Count the number of elements present in the Queue.
int countElements(struct Queue *q)
{
    int count = 0;
    struct Node *current = q->front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

/// Display all the elements present in the Queue.
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the Queue: ");
    struct Node *current = q->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void main()
{
    struct Queue q;
    q.front = NULL;
    q.rear = NULL;

    int ch, elem;

    do
    {
        printf("1. Enqueue\n2. Count elements\n3. Display elements\n4. Check if Queue is full\n5. Print addresses of Front and Rear pointers after insertion\n6. Dequeue\n7. Check if Queue is empty\n8. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &elem);
            enqueue(&q, elem);
            break;
        case 2:
            printf("Number of elements in queue: %d\n", countElements(&q));
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Queue is never full in linked list implementation\n"); /// Check whether Queue is full or not.
            break;
        case 5:
            /// Print the address of Front and Rear pointer after insertion operations.
            printf("Address of Front pointer: %p\n", (void *)&(q.front));
            printf("Address of Rear pointer: %p\n", (void *)&(q.rear));
            break;
        case 6:
            printf("Dequeued item: %d\n", dequeue(&q));
            break;
        case 7:
            if (isEmpty(&q))
                printf("Queue is empty\n");
            else
                printf("Queue is not empty\n");
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 8);
}