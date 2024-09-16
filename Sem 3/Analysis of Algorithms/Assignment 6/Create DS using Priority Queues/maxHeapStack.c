// Q10: Create stack using priority queue (max heap)
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
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->elements[left].priority > pq->elements[largest].priority)
    {
        largest = left;
    }
    if (right < pq->size && pq->elements[right].priority > pq->elements[largest].priority)
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&pq->elements[i], &pq->elements[largest]);
        heapify(pq, largest);
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

    while (i != 0 && pq->elements[(i - 1) / 2].priority < pq->elements[i].priority)
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

struct Stack
{
    struct priorityQ *pq;
    int prio;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->pq = createPriorityQ(capacity);
    stack->prio = 0;
    return stack;
}

void push(struct Stack *stack, int value)
{
    enqueue(stack->pq, value, stack->prio);
    stack->prio++;
}

int pop(struct Stack *stack)
{
    if (stack->pq->size == 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    struct PQElement topElem = dequeue(stack->pq);
    return topElem.val;
}

int top(struct Stack *stack)
{
    if (stack->pq->size == 0)
    {
        printf("Empty Stack\n");
        return -1;
    }
    return stack->pq->elements[0].val;
}

void main()
{
    struct Stack *stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", top(stack));

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
}