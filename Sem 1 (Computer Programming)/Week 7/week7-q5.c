// Write a C program to find the first peak element which is not smaller than its neighbours.
#include <stdio.h>

int findPeak(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == size - 1 || arr[mid] >= arr[mid + 1]))
        {
            return arr[mid];
        }
        else if (mid > 0 && arr[mid - 1] > arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
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
    printf("%d", findPeak(arr, size));
}