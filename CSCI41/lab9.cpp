#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to generate an array with random values
void generateArray(int arr[], int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100; // Array element = random value between 0 and 99
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Selection Sort Implementation
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Swap found minimum element with first element
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

// Insertion Sort Implementation
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i], j = i - 1;
        // Move elements of arr[0..i-1] > key to one position ahead of their curr pos
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort Implementation
void bubbleSort(int arr[], int size)
{
    bool flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) // If no two elements were swapped, array is sorted
        {
            break;
        }
    }
}

// Iterative Binary Search Implementation
int binarySearchIterative(int arr[], int size, int key)
{
    bool found = false;
    int mid, low = 0, high = size - 1;
    while ((low <= high) && (!found)) // While there are elements to search and not found
    {
        mid = (low + high) / 2; // Find the middle index
        if (arr[mid] == key)
        {
            found = true; // Element found
        }
        else if (arr[mid] > key)
        {
            high = mid - 1; // Search in the left half
        }
        else
        {
            low = mid + 1; // Search in the right half
        }
    }
    if (found)
    {
        return mid; // Return index of found element
    }
    else
    {
        return -1; // Element not found
    }
}

// Recursive Binary Search Implementation
int binarySearchRecursive(int arr[], int left, int right, int key)
{
    int mid;
    if (left > right)
    {
        return -1; // Base case: not found
    }
    mid = (left + right) / 2; // Find the middle index
    if (arr[mid] == key)
    {
        return mid; // Element found
    }
    else if (arr[mid] > key)
    {
        return binarySearchRecursive(arr, left, mid - 1, key); // Search in the left half
    }
    else
    {
        return binarySearchRecursive(arr, mid + 1, right, key); // Search in the right half
    }
}

int main()
{
    const int size = 10;
    int arr[size];
    generateArray(arr, size);

    cout << "Original Array: ";
    printArray(arr, size);

    // Sorting using Selection Sort
    selectionSort(arr, size);
    cout << "Sorted Array (Selection Sort): ";
    printArray(arr, size);

    // Sorting using Insertion Sort
    generateArray(arr, size);
    insertionSort(arr, size);
    cout << "Sorted Array (Insertion Sort): ";
    printArray(arr, size);

    // Sorting using Bubble Sort
    generateArray(arr, size);
    bubbleSort(arr, size);
    cout << "Sorted Array (Bubble Sort): ";
    printArray(arr, size);

    int key;
    cout << "Enter a number to search: ";
    cin >> key;

    int index = binarySearchIterative(arr, size, key);
    if (index != -1)
        cout << "Iterative Binary Search: Element found at index " << index << endl;
    else
        cout << "Iterative Binary Search: Element not found." << endl;

    index = binarySearchRecursive(arr, 0, size - 1, key);
    if (index != -1)
        cout << "Recursive Binary Search: Element found at index " << index << endl;
    else
        cout << "Recursive Binary Search: Element not found." << endl;

    return 0;
}
