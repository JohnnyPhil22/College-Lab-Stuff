// Read data elements present in array and display array elements in reverse order by calling appropriate function.
#include <stdio.h>
void revarr(int size, int arr[])
{
    int k;
    for (k = 0; k < size; k++)
    {
        printf("%d ", arr[(size - 1) - k]);
    }
    printf("\n");
}

void main()
{
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size], i;
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    int j;
    for (j = 0; j < size; j++)
    {
        printf("%d ", arr[j]);
    }

    printf("\nReversed array: ");
    revarr(size, arr);
}