// Binary Search is defined as a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N) where N is the array size. Write C program to implement binary search on the following scenario: Consider an array arr[]={2,5,8,12,16,23,38,56,72,91}, and the target = 23
#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
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
    int target;
    printf("Enter target value: ");
    scanf("%d", &target);

    printf("Element found at index %d", binarySearch(arr, size, target));
}