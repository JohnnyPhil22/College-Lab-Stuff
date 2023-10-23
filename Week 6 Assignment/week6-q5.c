/*
Write a C program to implement Modified Bubble Sort algorithm on a set of 15 numbers.
Algorithm:
Bubble sort algorithm possesses a very important property: “Once there is no swapping of elements in a particular pass, there will be no further swapping of elements in the subsequent passes.”
This property can be exploited to reduce the unnecessary passes. For this purpose we can use a flag variable to determine if any swapping has taken place, if yes only then proceed with the next pass; otherwise stop.
*/
#include <stdio.h>
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
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
    bubble_sort(arr, size);
}