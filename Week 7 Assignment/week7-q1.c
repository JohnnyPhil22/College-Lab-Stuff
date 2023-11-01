// Write a C program that interchanges the odd and even position elements in an array.
#include <stdio.h>

void intchg(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i += 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
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
    intchg(arr, size);
}