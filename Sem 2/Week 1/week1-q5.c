// Write a program in C to find the maximum and minimum elements in an array.
#include <stdio.h>
void main()
{
    int size, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int arr[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max = arr[0], min = arr[0];
    for (j = 1; j < size; j++)
    {
        if (arr[j] > max)
        {
            max = arr[j];
        }
        else if (arr[j] < min)
        {
            min = arr[j];
        }
    }
    printf("Maximum element: %d\nMinimum element: %d\n", max, min);
}