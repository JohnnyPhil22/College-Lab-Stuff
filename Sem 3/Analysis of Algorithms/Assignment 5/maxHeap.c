// Q1: Create max Heap
#include <stdio.h>

void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void maxHeapify(int arr[], int i, int heapSize)
{
	int LC = 2 * i + 1;
	int RC = 2 * i + 2;
	int large = i;

	if (LC <= heapSize && arr[LC] > arr[large])
	{
		large = LC;
	}
	if (RC <= heapSize && arr[RC] > arr[large])
	{
		large = RC;
	}
	if (i != large)
	{
		swap(&arr[i], &arr[large]);
		maxHeapify(arr, large, heapSize);
	}
}

void buildMaxHeap(int arr[], int heapSize)
{
	int i;
	for (i = (heapSize / 2) - 1; i >= 0; i--)
	{
		maxHeapify(arr, i, heapSize);
	}
}

void main()
{
	int arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
	int size = sizeof(arr) / sizeof(arr[0]);

	buildMaxHeap(arr, size);

	int i;
	printf("Heap: ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
