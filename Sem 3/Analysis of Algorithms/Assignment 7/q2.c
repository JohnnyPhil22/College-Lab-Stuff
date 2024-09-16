// Q2: Find the ith order static and i smallest numbers using Max heap of size i.
#include <stdio.h>
#include <stdlib.h>

struct maxHeap
{
    int *arr;
    int capacity;
    int size;
};

struct maxHeap *createMaxHeap(int capacity)
{
    struct maxHeap *heap = (struct maxHeap *)malloc(sizeof(struct maxHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->arr = (int *)malloc(capacity * sizeof(int));
    return heap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(struct maxHeap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;

    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&heap->arr[i], &heap->arr[largest]);
        maxHeapify(heap, largest);
    }
}

int extractMax(struct maxHeap *heap)
{
    if (heap->size <= 0)
    {
        return -1;
    }
    if (heap->size == 1)
    {
        heap->size--;
        return heap->arr[0];
    }

    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return root;
}

void insert(struct maxHeap *heap, int key)
{
    if (heap->size == heap->capacity)
    {
        if (key > heap->arr[0])
        {
            return;
        }
        extractMax(heap);
    }

    int i = heap->size;
    heap->arr[i] = key;
    heap->size++;

    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int findIthOrderStatistic(int *nums, int numsSize, int i)
{
    if (i <= 0 || i > numsSize)
    {
        printf("Invalid i value\n");
        return -1; // Or some error value
    }

    struct maxHeap *heap = createMaxHeap(i);

    for (int j = 0; j < i; j++)
    {
        insert(heap, nums[j]);
    }

    for (int j = i; j < numsSize; j++)
    {
        if (nums[j] < heap->arr[0])
        {
            extractMax(heap);
            insert(heap, nums[j]);
        }
    }

    int result = heap->arr[0];

    free(heap->arr);
    free(heap);

    return result;
}

void findISmallestNumbers(int *nums, int numsSize, int i)
{
    if (i <= 0 || i > numsSize)
    {
        printf("Invalid i value\n");
        return;
    }

    struct maxHeap *heap = createMaxHeap(i);

    for (int j = 0; j < i; j++)
    {
        insert(heap, nums[j]);
    }

    for (int j = i; j < numsSize; j++)
    {
        if (nums[j] < heap->arr[0])
        {
            extractMax(heap);
            insert(heap, nums[j]);
        }
    }

    printf("The %d smallest numbers are: ", i);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", extractMax(heap));
    }
    printf("\n");

    free(heap->arr);
    free(heap);
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