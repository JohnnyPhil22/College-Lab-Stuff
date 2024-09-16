// Q4: Find the ith order static and i smallest numbers using Partition Algorithm.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - low == k - 1)
            return arr[pivotIndex];

        if (pivotIndex - low > k - 1)
            return quickSelect(arr, low, pivotIndex - 1, k);

        return quickSelect(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }
    return -1;
}

int findIthOrderStatistic(int nums[], int numsSize, int i)
{
    if (i <= 0 || i > numsSize)
    {
        printf("Invalid i value\n");
        return -1;
    }
    return quickSelect(nums, 0, numsSize - 1, i);
}

void findISmallestNumbers(int nums[], int numsSize, int i)
{
    if (i <= 0 || i > numsSize)
    {
        printf("Invalid i value\n");
        return;
    }

    int *copy = (int *)malloc(numsSize * sizeof(int));
    memcpy(copy, nums, numsSize * sizeof(int));

    quickSelect(copy, 0, numsSize - 1, i);

    printf("The %d smallest numbers are: ", i);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", copy[j]);
    }
    printf("\n");
}

void main()
{
    int nums[] = {12, 3, 5, 7, 19, 2, 14, 8, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int i = 4;

    printf("Original array: ");
    for (int j = 0; j < numsSize; j++)
    {
        printf("%d ", nums[j]);
    }
    printf("\n");

    int ithOrderStat = findIthOrderStatistic(nums, numsSize, i);
    printf("The %dth order statistic is: %d\n", i, ithOrderStat);

    findISmallestNumbers(nums, numsSize, i);
}