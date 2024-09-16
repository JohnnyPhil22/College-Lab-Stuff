// Q6: Create queues using stacks (easy push)
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

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top];
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

void enqueue(struct Queue *queue, int item)
{
    push(queue->stack1, item);
    printf("Enqueued %d\n", item);
}

int dequeue(struct Queue *queue)
{
    int item;

    if (isEmpty(queue->stack1) && isEmpty(queue->stack2))
    {
        printf("Empty Queue\n");
        return -1;
    }

    if (isEmpty(queue->stack2))
    {
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }

    item = pop(queue->stack2);
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