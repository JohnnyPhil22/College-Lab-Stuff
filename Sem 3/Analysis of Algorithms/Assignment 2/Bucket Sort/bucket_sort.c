// Bucket sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(int arr[], int n)
{
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int bucket_count = 10;
    int range = (max - min + 1) / bucket_count;
    int **buckets = (int **)malloc(bucket_count * sizeof(int *));
    int *bucket_sizes = (int *)calloc(bucket_count, sizeof(int));

    for (int i = 0; i < bucket_count; i++)
    {
        buckets[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        int bucket_index = (arr[i] - min) / range;
        if (bucket_index >= bucket_count)
        {
            bucket_index = bucket_count - 1;
        }
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    for (int i = 0; i < bucket_count; i++)
    {
        insertionSort(buckets[i], bucket_sizes[i]);
    }

    int index = 0;
    for (int i = 0; i < bucket_count; i++)
    {
        for (int j = 0; j < bucket_sizes[i]; j++)
        {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucket_sizes);
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
    bucketSort(arr, n);
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
