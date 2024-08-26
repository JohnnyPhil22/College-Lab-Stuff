#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low], i = low - 1;
    for (int j = low; j < (high - 1); j++)
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

void quickSortIterative(int arr[], int low, int high)
{
    int *stack = (int *)malloc((high - low + 1) * sizeof(int));

    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        int pivot = partition(arr, low, high);

        if (pivot - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = pivot - 1;
        }

        if (pivot + 1 < high)
        {
            stack[++top] = pivot + 1;
            stack[++top] = high;
        }
    }

    free(stack);
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
    clock_t start, end;
    start = clock();
    quickSortIterative(arr, 0, n - 1);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
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