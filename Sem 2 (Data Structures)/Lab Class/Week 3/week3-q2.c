// Implement binary search over array elements where array elements as well as the element to be searched is taken as input from the user.
#include <stdio.h>

int binsrch(int arr[], int elem, int beg, int end)
{
    while (beg <= end)
    {
        int mid = end + (beg - end) / 2;
        if (arr[mid] == elem)
        {
            return mid;
        }
        else if (arr[mid] < elem)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

void main()
{
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size], i;
    for (i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int elem;
    printf("Enter element to search: ");
    scanf("%d", &elem);

    int pos = binsrch(arr, elem, 0, size - 1);
    if (pos == -1)
    {
        printf("%d is not in array\n");
    }
    else
    {
        printf("%d is at position %d\n", elem, pos + 1);
    }
}
