// Q2: Create stacks using queues
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool queueEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (queueEmpty(q))
    {
        printf("Empty Queue\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

typedef struct
{
    Queue *q1;
    Queue *q2;
} Stack;

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->q1 = createQueue();
    s->q2 = createQueue();
    return s;
}

bool stackEmpty(Stack *s)
{
    return queueEmpty(s->q1);
}

void push(Stack *s, int value)
{
    enqueue(s->q1, value);
}

int pop(Stack *s)
{
    if (stackEmpty(s))
    {
        printf("Empty Stack\n");
        return -1;
    }

    while (s->q1->front != s->q1->rear)
    {
        enqueue(s->q2, dequeue(s->q1));
    }

    int item = dequeue(s->q1);

    Queue *temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return item;
}

int peek(Stack *s)
{
    if (stackEmpty(s))
    {
        printf("Empty Stack\n");
        return -1;
    }

    while (s->q1->front != s->q1->rear)
    {
        enqueue(s->q2, dequeue(s->q1));
    }

    int item = s->q1->items[s->q1->front];

    enqueue(s->q2, dequeue(s->q1));

    Queue *temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    return item;
}

void main()
{
    Stack *stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    push(stack, 4);
    push(stack, 5);

    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    printf(stackEmpty(stack) ? "Empty Stack" : "Not empty stack");
}