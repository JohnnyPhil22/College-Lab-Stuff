// Write a C program to implement Insertion Sort algorithm on a set of 15 numbers.
#include <stdio.h>
void insertionsort(int arr[], int size)
{
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
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    insertionsort(arr, size);
}