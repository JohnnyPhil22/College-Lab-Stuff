// Write a menu-driven program to implement Stack using Array that can perform the following operations:
#include <stdio.h>
#include <stdlib.h>

int size, count = 0;

int *createStack()
{
    int *stack = (int *)malloc(size * sizeof(int));
    return stack;
}

/// Check whether Stack is empty or not.
int chkempty(int top)
{
    return (top == -1);
}

/// Check whether Stack is full or not.
int chkfull(int top, int size)
{
    return (top == size - 1);
}

/// Insert user-given integer elements in the Stack using Push operations.
/// Count the number of elements present in the Stack.
void push(int *stack, int *top, int *size, int item)
{
    if (chkfull(*top, *size))
    {
        printf("Stack is full\n");
        return;
    }
    stack[++(*top)] = item;
    count++;
}

/// Display all the elements present in the Stack.
void display(int *stack, int top)
{
    printf("Elements in stack:\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int pop(int *stack, int *top)
{
    if (chkempty(*top))
    {
        printf("Stack is empty\n");
        return -1;
    }
    count--;
    return stack[(*top)--];
}

void main()
{
    int *stack;
    int top = -1;

    printf("Enter number of elements: ");
    scanf("%d", &size);
    stack = createStack();

    int ch, elem;
    do
    {
        printf("\n1. Insert element\n2. Count number of elements\n3. Display all elements\n4. Check if stack is full or not\n5. Find largest element by pop operation\n6. Check if empty\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (count == size)
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Enter element: ");
                scanf("%d", &elem);
                push(stack, &top, &size, elem);
            }
            break;
        case 2:
            printf("Number of elements: %d\n", count);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            if (count == size)
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }
            break;
        /// Find the largest element present in the Stack after performing Pop operations over the complete Stack.
        case 5:
            if (!chkempty(top))
            {
                int max = pop(stack, &top);
                while (!chkempty(top))
                {
                    int temp = pop(stack, &top);
                    if (temp > max)
                        max = temp;
                }
                printf("Largest element using pop operation: %d\n", max);
            }
            else
            {
                printf("Stack is empty\n");
            }
            break;
        case 6:
            if (chkempty(top))
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Please enter a valid option.\n");
        }
    } while (ch != 7);

    free(stack);
}
