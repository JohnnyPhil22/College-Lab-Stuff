// Counting sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int arr[], int n, int max)
{
    int *count = (int *)malloc((max + 1) * sizeof(int)), *output = (int *)malloc(n * sizeof(int));

    for (int i = 0; i <= max; ++i)
        count[i] = 0;

    for (int i = 0; i < n; ++i)
        count[arr[i]]++;

    for (int i = 1; i <= max; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];

    free(count);
    free(output);
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

double measureTime(int arr[], int n, int max)
{
    clock_t start, end;
    start = clock();
    countingSort(arr, n, max);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
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
        double best = measureTime(arr, n, getMax(arr, n));

        generateArray(arr, n, 2); // Worst case
        double worst = measureTime(arr, n, getMax(arr, n));

        generateArray(arr, n, 0); // Average case
        double avg = measureTime(arr, n, getMax(arr, n));

        fprintf(fptr, "%d %f %f %f\n", n, best, worst, avg);

        free(arr);
    }

    fclose(fptr);
}
