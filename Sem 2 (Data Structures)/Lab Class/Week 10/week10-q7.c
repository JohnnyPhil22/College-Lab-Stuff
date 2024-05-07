// Check whether an array is a subset of another array.
#include <stdio.h>

int arrsubs(int size1, int arr1[], int size2, int arr2[])
{
    int i, j;
    for (i = 0; i < size1; i++)
    {
        for (j = 0; j < size2; j++)
        {
            if (arr2[j] == arr1[i])
            {
                break;
            }
        }
        if (j == size2)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int size1, i, elem, size2;
    printf("Enter size of first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    for (i = 0; i < size1; i++)
    {
        printf("Enter element: ");
        scanf("%d", &elem);
        arr1[i] = elem;
    }

    printf("Enter size of second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    for (i = 0; i < size2; i++)
    {
        printf("Enter element: ");
        scanf("%d", &elem);
        arr2[i] = elem;
    }

    if (arrsubs(size2, arr2, size1, arr1))
    {
        printf("Second array is subset of first array");
    }
    else
    {
        printf("Second array is not subset of first array");
    }
}