// Compare three given numbers and print the largest number. (Using only one loop)
#include <stdio.h>

int main()
{
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
    }

    if (arr[0] > arr[1] && arr[0] > arr[2])
    {
        printf("%d is the largest number.", arr[0]);
    }

    else if (arr[1] > arr[0] && arr[1] > arr[2])
    {
        printf("%d is the largest number.", arr[1]);
    }

    else if (arr[2] > arr[0] && arr[2] > arr[1])
    {
        printf("%d is the largest number.", arr[2]);
    }
}