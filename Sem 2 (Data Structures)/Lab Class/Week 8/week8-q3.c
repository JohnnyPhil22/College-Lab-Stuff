// Implement a Priority Queue program using Linked List that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct PriorityQueue
{
    struct Node *front;
};

struct Node *createNode(int data, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

struct PriorityQueue *createPriorityQueue()
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    if (pq == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    pq->front = NULL;
    return pq;
}

// Check whether the Priority Queue is empty or not.
bool isEmpty(struct PriorityQueue *pq)
{
    return (pq->front == NULL);
}

// Insert user-given integer elements in the Priority Queue.
void insert(struct PriorityQueue *pq, int data, int priority)
{
    struct Node *newNode = createNode(data, priority);
    if (isEmpty(pq) || priority > pq->front->priority)
    {
        newNode->next = pq->front;
        pq->front = newNode;
    }
    else
    {
        struct Node *current = pq->front;
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Count the number of elements present in the Priority Queue.
int countElements(struct PriorityQueue *pq)
{
    int count = 0;
    struct Node *current = pq->front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Display all the elements present in the Priority Queue.
void display(struct PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty\n");
    }
    else
    {
        printf("Priority Queue elements: ");
        struct Node *current = pq->front;
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
    }
}

// Check whether the Priority Queue is full or not.
bool isFull(struct PriorityQueue *pq)
{
    // Assuming no predefined maximum capacity
    return false;
}

// Delete elements from the Priority Queue.
void deleteElement(struct PriorityQueue *pq)
{
    if (isEmpty(pq))
    {
        printf("Empty Priority Queue\n");
    }
    else
    {
        struct Node *temp = pq->front;
        pq->front = pq->front->next;
        free(temp);
    }
}

int main()
{
    struct PriorityQueue *pq = createPriorityQueue();
    int ch, data, priority;

    do
    {
        printf("1. Insert element\n2. Count elements\n3. Display elements\n4. Check if Priority Queue is full\n5. Delete element\n6. Check if Priority Queue is empty\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data and priority to insert: ");
            scanf("%d %d", &data, &priority);
            insert(pq, data, priority);
            break;
        case 2:
            printf("Number of elements in Priority Queue: %d\n", countElements(pq));
            break;
        case 3:
            display(pq);
            printf("\n");
            break;
        case 4:
            if (isFull(pq))
            {
                printf("Full Priority Queue\n");
            }
            else
            {
                printf("Not Full Priority Queue\n");
            }
            break;
        case 5:
            deleteElement(pq);
            break;
        case 6:
            if (isEmpty(pq))
            {
                printf("Empty Priority Queue\n");
            }
            else
            {
                printf("Not Empty Priority Queue\n");
            }
            break;
        case 7:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 7);
}
