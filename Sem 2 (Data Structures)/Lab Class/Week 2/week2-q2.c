// Compute sum of all even numbers in array and write a function to check whether given number is even or odd.
#include <stdio.h>
void chkeveodd(int num)
{
    if (num % 2 == 1)
    {
        printf("%d is odd\n", num);
    }
    else
    {
        printf("%d is even\n", num);
    }
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
        chkeveodd(arr[i]);
    }

    int j, sum;
    for (j = 0; j < size; j++)
    {
        if (arr[j] % 2 == 0)
        {
            sum += arr[j];
        }
    }

    printf("Sum of all even elements in array: %d\n", sum);
}