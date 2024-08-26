#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i], j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generateArray(int arr[], int n){
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 10000;
	}
}

double measureTimeInsSort(int arr[], int n)
{
    clock_t start, end;
    start = clock();
    insertionSort(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

double measureTimeBubSort(int arr[], int n)
{
    clock_t start, end;
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

void main() {
	FILE *fptr;
    fptr = fopen("insData.txt", "w");
    int sizes[] = {100, 500, 1000, 5000, 10000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int *arr;

    srand(time(0));
    for (int i = 0; i < num_sizes; i++)
    {
        int n = sizes[i];
        arr = (int *)malloc(n * sizeof(int));

        generateArray(arr, n);
        double avg = measureTimeInsSort(arr, n);

        fprintf(fptr, "%d %f\n", n, avg);

        free(arr);
    }

    fclose(fptr);
    
    fptr = fopen("bubData.txt", "w");
    srand(time(0));
    for (int i = 0; i < num_sizes; i++)
    {
        int n = sizes[i];
        arr = (int *)malloc(n * sizeof(int));

        generateArray(arr, n);
        double avg = measureTimeBubSort(arr, n);

        fprintf(fptr, "%d %f\n", n, avg);

        free(arr);
    }

    fclose(fptr);
}
