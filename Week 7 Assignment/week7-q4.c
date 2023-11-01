// Given an array arr[ ] of size N and a number K, where K is smaller than the size of the array. Write a C program to find the Kth smallest element in the given array. Given that all array elements are distinct.
#include <stdio.h>
void main()
{
    int size, k;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);

    int i, j, key;
    for (i = 0; i < size - 1; i++)
    {
        key = arr[i + 1];
        j = i;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("%d", arr[k - 1]);
}