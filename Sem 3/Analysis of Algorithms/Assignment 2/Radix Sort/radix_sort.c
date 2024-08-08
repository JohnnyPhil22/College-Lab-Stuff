// Radix sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
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
    radixSort(arr, n);
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
