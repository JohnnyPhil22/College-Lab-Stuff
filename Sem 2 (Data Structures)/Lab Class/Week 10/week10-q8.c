// Segregate a given array of 0s and 1s in random order such that all 0s are on the left side and 1s are on the right side of the array using one loop only.
#include <stdio.h>

void segregate(int size, int arr[])
{
    int left = 0, right = size - 1;
    while (left < right)
    {
        while (arr[left] == 0 && left < right)
        {
            left++;
        }
        while (arr[right] == 1 && left < right)
        {
            right--;
        }
        if (left < right)
        {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

void main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int i, arr[size];
    for (i = 0; i < size; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    segregate(size, arr);
    printf("\nSegregated array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}