// Count total number of duplicate elements in array and print the data values which repeat within array.
#include <stdio.h>
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

    printf("Repeated elements in array: ");
    int j, k, count;
    for (j = 0; j < size; j++)
    {
        for (k = j + 1; k < size; k++)
        {
            if (arr[j] == arr[k])
            {
                count++;
                printf("%d ", arr[k]);
                break;
            }
        }
    }
    printf("\nTotal number of repeated elements: %d\n", count);
}