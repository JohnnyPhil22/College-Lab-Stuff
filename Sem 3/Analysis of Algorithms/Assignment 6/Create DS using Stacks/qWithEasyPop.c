// Q7: Create queues using stacks (easy pop)
#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
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

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow!\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

struct Queue
{
    struct Stack *stack1;
    struct Stack *stack2;
};

struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void transferStack(struct Stack *stack1, struct Stack *stack2)
{
    while (!isEmpty(stack1))
    {
        push(stack2, pop(stack1));
    }
}

void enqueue(struct Queue *queue, int item)
{
    transferStack(queue->stack1, queue->stack2);
    push(queue->stack1, item);
    transferStack(queue->stack2, queue->stack1);
    printf("Enqueued %d\n", item);
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue->stack1))
    {
        printf("Empty Queue\n");
        return -1;
    }

    int item = pop(queue->stack1);
    return item;
}

void main()
{
    struct Queue *queue = createQueue(100);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("\nDequeued %d\n", dequeue(queue));
    printf("Dequeued %d\n\n", dequeue(queue));

    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("\nDequeued %d\n", dequeue(queue));
    printf("Dequeued %d\n", dequeue(queue));
    printf("Dequeued %d\n", dequeue(queue));
}