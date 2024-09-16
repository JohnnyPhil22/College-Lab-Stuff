// Q4: Create Priority Queue (Max Heap) using Queues
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct priorityQ
{
    struct Node *front;
};

struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct priorityQ *createPriorityQ()
{
    struct priorityQ *pq = (struct priorityQ *)malloc(sizeof(struct priorityQ));
    pq->front = NULL;
    return pq;
}

int isEmpty(struct priorityQ *pq)
{
    return pq->front == NULL;
}

void enqueue(struct priorityQ *pq, int data)
{
    struct Node *temp = newNode(data);
    if (isEmpty(pq) || data > pq->front->data)
    {
        temp->next = pq->front;
        pq->front = temp;
    }
    else
    {
        struct Node *current = pq->front;
        while (current->next != NULL && current->next->data >= data)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

int dequeue(struct priorityQ *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty");
        return -1;
    }
    struct Node *temp = pq->front;
    int maxVal = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return maxVal;
}

int getMax(struct priorityQ *pq)
{
    if (isEmpty(pq))
    {
        printf("Priority Queue is empty");
        return -1;
    }
    return pq->front->data;
}

void printQ(struct priorityQ *pq)
{
    if (isEmpty(pq))
    {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = pq->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    struct priorityQ *pq = createPriorityQ();

    enqueue(pq, 10);
    enqueue(pq, 20);
    enqueue(pq, 5);
    enqueue(pq, 40);
    enqueue(pq, 15);

    printf("Priority Queue: ");
    printQ(pq);

    printf("Maximum element: %d\n", getMax(pq));

    printf("Extracting maximum element: %d\n", dequeue(pq));
    printf("Priority Queue after extraction: ");
    printQ(pq);
}