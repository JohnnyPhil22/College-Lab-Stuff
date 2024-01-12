// Write a C program to move all the even numbers to beginning and the odd numbers to end of the same array.
#include <stdio.h>

void shiftelem(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {

        while (arr[left] % 2 == 0 && left < right)
        {
            left++;
        }

        while (arr[right] % 2 != 0 && left < right)
        {
            right--;
        }

        if (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
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
    shiftelem(arr, size);
}