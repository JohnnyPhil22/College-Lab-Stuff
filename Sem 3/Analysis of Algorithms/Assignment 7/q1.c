// Q1: Find the ith order static and i smallest numbers using Max heap of size n.
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

void insert(struct maxHeap *heap, int key)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap is full. Cannot insert.\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = key;

    while (i != 0 && heap->arr[(i - 1) / 2] < heap->arr[i])
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(struct maxHeap *heap, int *success)
{
    if (heap->size <= 0)
    {
        *success = 0;
        return 0;
    }

    *success = 1;
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

void buildMaxHeap(struct maxHeap *heap)
{
    int i;
    for (i = (heap->size - 2) / 2; i >= 0; i--)
        maxHeapify(heap, i);
}

int findKthLargest(int *nums, int numsSize, int k, int *success)
{
    struct maxHeap *heap = createMaxHeap(numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        insert(heap, nums[i]);
    }

    int result = 0;
    *success = 1;
    for (int i = 0; i < k; i++)
    {
        int extractSuccess;
        result = extractMax(heap, &extractSuccess);
        if (!extractSuccess)
        {
            *success = 0;
            break;
        }
    }

    free(heap->arr);
    free(heap);
    return result;
}

void findKSmallest(int *nums, int numsSize, int k)
{
    if (k > numsSize)
    {
        printf("k is larger than the array size. Cannot find %d smallest elements.\n", k);
        return;
    }

    struct maxHeap *heap = createMaxHeap(k);

    for (int i = 0; i < k; i++)
    {
        insert(heap, nums[i]);
    }

    for (int i = k; i < numsSize; i++)
    {
        if (nums[i] < heap->arr[0])
        {
            int success;
            extractMax(heap, &success);
            insert(heap, nums[i]);
        }
    }

    printf("The %d smallest elements are: ", k);
    for (int i = 0; i < k; i++)
    {
        int success;
        printf("%d ", extractMax(heap, &success));
    }
    printf("\n");

    free(heap->arr);
    free(heap);
}

void main()
{
    int nums[] = {3, 2, 1, 5, 6, 4, 0};
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int success;
    int kthLargest = findKthLargest(nums, size, k, &success);
    if (success)
    {
        printf("The %dth largest element is: %d\n", k, kthLargest);
    }
    else
    {
        printf("Failed to find the %dth largest element.\n", k);
    }

    findKSmallest(nums, size, k);
}