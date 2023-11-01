// Given an array of n elements that contains elements from 0 to N-1, with any of these numbers appearing any number of times. Write a C program to find these repeating numbers. (Note: The repeating element should be printed only once)
#include <stdio.h>
#include <math.h>

void repelem(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int index = abs(arr[i]);
        if (arr[index] >= 0)
        {
            arr[index] = -arr[index];
        }
        else
        {
            printf("%d ", index);
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    repelem(arr, size);
}