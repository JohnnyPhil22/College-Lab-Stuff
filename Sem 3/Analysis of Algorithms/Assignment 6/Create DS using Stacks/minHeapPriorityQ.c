// Q7: Create priority queue (min heap) using stacks
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *arr;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->arr[stack->top];
}

struct priorityQ
{
    struct Stack *stack1;
    struct Stack *stack2;
};

struct priorityQ *createPriorityQ(int capacity)
{
    struct priorityQ *pq = (struct priorityQ *)malloc(sizeof(struct priorityQ));
    pq->stack1 = createStack(capacity);
    pq->stack2 = createStack(capacity);
    return pq;
}

void enqueue(struct priorityQ *pq, int data)
{
    while (!isEmpty(pq->stack1) && (peek(pq->stack1) < data))
    {
        push(pq->stack2, pop(pq->stack1));
    }
    push(pq->stack1, data);
    while (!isEmpty(pq->stack2))
    {
        push(pq->stack1, pop(pq->stack2));
    }
}

int dequeue(struct priorityQ *pq)
{
    if (isEmpty(pq->stack1))
    {
        printf("Empty Queue\n");
        return -1;
    }

    return pop(pq->stack1);
}

int getMin(struct priorityQ *pq)
{
    if (isEmpty(pq->stack1))
    {
        printf("Empty Queue\n");
        return -1;
    }
    return peek(pq->stack1);
}

void main()
{
    struct priorityQ *pq = createPriorityQ(100);

    enqueue(pq, 10);
    enqueue(pq, 20);
    enqueue(pq, 5);
    enqueue(pq, 40);
    enqueue(pq, 15);

    printf("Minimum element: %d\n", getMin(pq));

    printf("Extracting minimum element: %d\n", dequeue(pq));
    printf("Extracting minimum element: %d\n", dequeue(pq));
}