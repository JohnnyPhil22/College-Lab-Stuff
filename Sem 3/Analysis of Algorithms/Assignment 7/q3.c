// Q3: Find the ith order static and i smallest numbers using Min heap.
#include <stdio.h>
#include <stdlib.h>

struct minHeap
{
    int *arr;
    int capacity;
    int size;
};

struct minHeap *createMinHeap(int capacity)
{
    struct minHeap *heap = (struct minHeap *)malloc(sizeof(struct minHeap));
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

void minHeapify(struct minHeap *heap, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

void insert(struct minHeap *heap, int key)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = key;

    while (i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(struct minHeap *heap)
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
    minHeapify(heap, 0);

    return root;
}

int findIthOrderStatistic(int *nums, int numsSize, int i)
{
    if (i <= 0 || i > numsSize)
    {
        printf("Invalid i value\n");
        return -1; // Or some error value
    }

    struct minHeap *heap = createMinHeap(numsSize);

    for (int j = 0; j < numsSize; j++)
    {
        insert(heap, nums[j]);
    }

    for (int j = 0; j < i - 1; j++)
    {
        extractMin(heap);
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

    struct minHeap *heap = createMinHeap(numsSize);

    for (int j = 0; j < numsSize; j++)
    {
        insert(heap, nums[j]);
    }

    printf("The %d smallest numbers are: ", i);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", extractMin(heap));
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