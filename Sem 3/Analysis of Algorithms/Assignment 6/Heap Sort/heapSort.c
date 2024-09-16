// Q1: Heap Sort time complexity graphs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void maxHeapify(int arr[], int i, int heapSize)
{
	int LC = 2 * i + 1, RC = 2 * i + 2, large = i;

	if (LC < heapSize && arr[LC] > arr[large])
	{
		large = LC;
	}
	if (RC < heapSize && arr[RC] > arr[large])
	{
		large = RC;
	}
	if (i != large)
	{
		swap(&arr[i], &arr[large]);
		maxHeapify(arr, large, heapSize);
	}
}

void buildMaxHeap(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		maxHeapify(arr, i, size);
	}
}

void heapSort(int arr[], int size)
{
	buildMaxHeap(arr, size);
	for (int i = size - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[i]);
		maxHeapify(arr, 0, i);
	}
}

void generateArray(int arr[], int n, int type)
{
	if (type == 1) // Best case
	{
		for (int i = 0; i < n; i++)
			arr[i] = i;
	}
	else if (type == 2) // Worst case
	{
		for (int i = 0; i < n; i++)
			arr[i] = n - i;
	}
	else // Average case
	{
		for (int i = 0; i < n; i++)
			arr[i] = rand() % 10000;
	}
}

double measureTime(int arr[], int n)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	heapSort(arr, n);
	gettimeofday(&end, NULL);
	return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

void main()
{
	FILE *fptr;
	fptr = fopen("data.txt", "w");
	int sizes[] = {100, 500, 1000, 5000, 10000};
	int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
	int *arr;

	srand(time(0));
	for (int i = 0; i < num_sizes; i++)
	{
		int n = sizes[i];
		arr = (int *)malloc(n * sizeof(int));

		generateArray(arr, n, 1); // Best case
		double best = measureTime(arr, n);

		generateArray(arr, n, 2); // Worst case
		double worst = measureTime(arr, n);

		generateArray(arr, n, 0); // Average case
		double avg = measureTime(arr, n);

		fprintf(fptr, "%d %f %f %f\n", n, best, worst, avg);

		free(arr);
	}

	fclose(fptr);
}