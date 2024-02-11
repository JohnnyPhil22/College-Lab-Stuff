// Given an array arr[] of size N-1 with integers in the range of [1, N]. Write a C program to find the missing number from the first N integers.

int missno(int arr[], int size)
{
    int tot = 0, exptot = ((size + 1) * (size + 2)) / 2;
    for (int i = 0; i < size; i++)
    {
        tot += arr[i];
    }
    return exptot - tot;
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("%d", missno(arr, size));
}