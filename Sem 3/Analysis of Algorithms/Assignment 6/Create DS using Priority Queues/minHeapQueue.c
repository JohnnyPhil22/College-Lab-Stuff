// Q11: Create queue using priority queue (min heap)
#include <stdio.h>
#include <stdlib.h>

struct PQElement
{
    int val;
    int priority;
};

struct priorityQ
{
    struct PQElement *elements;
    int capacity;
    int size;
};

struct priorityQ *createPriorityQ(int capacity)
{
    struct priorityQ *pq = (struct priorityQ *)malloc(sizeof(struct priorityQ));
    pq->elements = (struct PQElement *)malloc(capacity * sizeof(struct PQElement));
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}

void swap(struct PQElement *a, struct PQElement *b)
{
    struct PQElement temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct priorityQ *pq, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->elements[left].priority < pq->elements[smallest].priority)
    {
        smallest = left;
    }
    if (right < pq->size && pq->elements[right].priority < pq->elements[smallest].priority)
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&pq->elements[i], &pq->elements[smallest]);
        heapify(pq, smallest);
    }
}

void enqueue(struct priorityQ *pq, int value, int priority)
{
    if (pq->size == pq->capacity)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = pq->size++;
    pq->elements[i].val = value;
    pq->elements[i].priority = priority;

    while (i != 0 && pq->elements[(i - 1) / 2].priority > pq->elements[i].priority)
    {
        swap(&pq->elements[i], &pq->elements[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct PQElement dequeue(struct priorityQ *pq)
{
    if (pq->size == 0)
    {
        printf("Priority Queue Underflow\n");
        struct PQElement empty = {-1, -1};
        return empty;
    }

    struct PQElement root = pq->elements[0];
    pq->elements[0] = pq->elements[--pq->size];
    heapify(pq, 0);
    return root;
}

struct Queue
{
    struct priorityQ *pq;
    int prio;
};

struct Queue *createQ(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->pq = createPriorityQ(capacity);
    queue->prio = 0;
    return queue;
}

void enqueueQ(struct Queue *queue, int value)
{
    enqueue(queue->pq, value, queue->prio);
    queue->prio++;
}

int dequeueQ(struct Queue *queue)
{
    if (queue->pq->size == 0)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    struct PQElement frontElement = dequeue(queue->pq);
    return frontElement.val;
}

int front(struct Queue *queue)
{
    if (queue->pq->size == 0)
    {
        printf("Empty Queue\n");
        return -1;
    }
    return queue->pq->elements[0].val;
}

void main()
{
    struct Queue *queue = createQ(100);

    enqueueQ(queue, 10);
    enqueueQ(queue, 20);
    enqueueQ(queue, 30);

    printf("Top element: %d\n", front(queue));

    printf("Popped element: %d\n", dequeueQ(queue));
    printf("Popped element: %d\n", dequeueQ(queue));
}