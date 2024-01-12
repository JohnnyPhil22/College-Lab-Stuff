// Write a C program to find the sum of elements in an array.
#include <stdio.h>
void main()
{
    int size, sum, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int arr[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (j = 0; j < size; j++)
    {
        sum += arr[j];
    }
    printf("Sum of elements: %d\n", sum);
}