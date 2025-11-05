#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

// Function to generate an array with random numbers
void generateRandomArray(int arr[], int n)
{
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right)
{
    // Initialize first subarray
    int n1 = mid - left + 1;
    int *LeftArr = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        LeftArr[i] = arr[left + i];
    }

    // Initialize second subarray
    int n2 = right - mid;
    int *RightArr = new int[n2];
    for (int i = 0; i < n2; i++)
    {
        RightArr[i] = arr[mid + 1 + i];
    }

    // Merge the temp arrays back into arr[left..right]
    int i1 = 0, i2 = 0, j = left; // Initial indexes of first and second subarrays
    while ((i1 < n1) && (i2 < n2))
    {
        if (LeftArr[i1] <= RightArr[i2]) // Take from LeftArr
        {
            arr[j] = LeftArr[i1];
            i1++;
        }
        else // Take from RightArr
        {
            arr[j] = RightArr[i2];
            i2++;
        }
        j++;
    }

    // Copy the remaining elements of LeftArr[], if there are any
    while (i1 < n1)
    {
        arr[j] = LeftArr[i1];
        i1++;
        j++;
    }

    // Copy the remaining elements of RightArr[], if there are any
    while (i2 < n2)
    {
        arr[j] = RightArr[i2];
        i2++;
        j++;
    }
    delete[] LeftArr;
    delete[] RightArr;
}

// Merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right) // More than one element, no else needed, because base case = 1 element = sorted
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Sort first half
        mergeSort(arr, mid + 1, right); // Sort second half
        merge(arr, left, mid, right);   // Merge the sorted halves
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high)
{
    int i = low, j = high;
    int pivot = arr[(low + high) / 2]; // Choosing the middle element as pivot
    bool fin = false;

    while (!fin)
    {
        while ((i < high) && (arr[i] < pivot)) // Move i to the right
        {
            i++;
        }
        while ((j > low) && (arr[j] > pivot)) // Move j to the left
        {
            j--;
        }
        if (i < j) // Swap elements at i and j
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else // Indices have crossed
        {
            fin = true;
        }
    }
    return j; // Return the partitioning index
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high) // More than one element, no else needed, because base case = 1 element = sorted
    {
        int pivotIndex = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pivotIndex);            // Recursively sort elements before partition
        quickSort(arr, pivotIndex + 1, high);       // Recursively sort elements after partition
    }
}

// Main function
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    int *arrCopy = new int[n];

    // Generate random numbers
    generateRandomArray(arr, n);

    cout << "Original array:\n";
    printArray(arr, n);

    // Copy the original array for Merge Sort
    for (int i = 0; i < n; i++)
        arrCopy[i] = arr[i];

    // Merge Sort
    mergeSort(arrCopy, 0, n - 1);
    cout << "Sorted array using Merge Sort:\n";
    printArray(arrCopy, n);

    // Copy the original array for Quick Sort
    for (int i = 0; i < n; i++)
        arrCopy[i] = arr[i];

    // Quick Sort
    quickSort(arrCopy, 0, n - 1);
    cout << "Sorted array using Quick Sort:\n";
    printArray(arrCopy, n);

    delete[] arr;
    delete[] arrCopy;
    return 0;
}
