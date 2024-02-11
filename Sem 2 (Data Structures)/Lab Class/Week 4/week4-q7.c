// Insert two elements in the array at the user-given indexes. Also, the program should be able to delete the last element of the array as per the user request.
#include <stdio.h>

void main()
{
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size], i, j;
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    int ch;
    printf("\n1. Add two elements\n2. Delete last element\nEnter choice: ");
    scanf("%d", &ch);
    int new_index;
    switch (ch)
    {
    case 1:
        for (i = 0; i < 2; i++)
        {
            printf("Enter position to add new element %d: ", i + 1);
            scanf("%d", &new_index);
            size++;
            for (j = size - 1; j >= new_index - 1; j--)
            {
                arr[j] = arr[j - 1];
            }
            printf("Enter value at position %d: ", new_index);
            scanf("%d", &arr[new_index - 1]);
        }
        printf("New array: ");
        for (i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;

    case 2:
        printf("Deleting element %d at index %d\n", arr[size - 1], size - 1);
        size--;
        printf("New array: ");
        for (i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        break;

    default:
        printf("Enter correct option\n");
        break;
    }
}
