// Write a program maxmin.c to find the largest and smallest elements in an array using a fixed function call (max_min()) that involves both call by addressing and call by value. Modify the maxmin.c program so that the max_min() function uses a pointer instead of an integer to keep track of the current position in the array.
#include <stdio.h>

void max_min(int arr[], int size, int *max, int *min)
{
    *max = *min = arr[0];

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
        else if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}

void main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nUsing Call by Value:\n");
    int max_val, min_val;
    max_min(arr, size, &max_val, &min_val);
    printf("Largest element: %d\n", max_val);
    printf("Smallest element: %d\n", min_val);

    printf("\nUsing Call by Addressing:\n");
    int max_val_ptr, min_val_ptr;
    int *max_ptr = &max_val_ptr;
    int *min_ptr = &min_val_ptr;
    max_min(arr, size, max_ptr, min_ptr);
    printf("Largest element: %d\n", *max_ptr);
    printf("Smallest element: %d", *min_ptr);
}