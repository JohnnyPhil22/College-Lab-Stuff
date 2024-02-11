// Implement linear search using arrays
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

    int num;
    printf("Enter number to search: ");
    scanf("%d", &num);

    int j, flag = 0, index;
    for (j = 0; j < size; j++)
    {
        if (num == arr[j])
        {
            flag = 1;
            index = j + 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }

    if (flag == 1)
    {
        printf("%d found at position %d\n", num, index);
    }
    else
    {
        printf("Number not present in array\n");
    }
}