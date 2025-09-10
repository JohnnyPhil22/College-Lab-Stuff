#include <iostream>

using namespace std;

// Function that returns f(a, b, n, m)
double computeSum(const double a[], const double b[], int n, int m)
{
    double sum = 0.0;
    for (int i = 1, j = 1; i <= n && j <= m; ++i, ++j)
    {
        sum += a[i] * b[j];
    }
    return sum;
}

// Void function returning the output using a pointer
void computeSumPointer(const double a[], const double b[], int n, int m, double *result)
{
    *result = 0.0;
    for (int i = 1, j = 1; i <= n && j <= m; ++i, ++j)
    {
        *result += a[i] * b[j];
    }
}

// Void function returning the output using a reference
void computeSumReference(const double a[], const double b[], int n, int m, double &result)
{
    result = 0.0;
    for (int i = 1, j = 1; i <= n && j <= m; ++i, ++j)
    {
        result += a[i] * b[j];
    }
}

// Main function to test all three methods
int main()
{
    // Example arrays
    double a[] = {1.0, 2.0, 3.0};
    double b[] = {4.0, 5.0};
    int n = 3, m = 2;

    // Using the function that returns the sum
    double result1 = computeSum(a, b, n, m);
    cout << "Result using function return: " << result1 << endl;

    // Using the function with pointer
    double result2;
    computeSumPointer(a, b, n, m, &result2);
    cout << "Result using pointer: " << result2 << endl;

    // Using the function with reference
    double result3;
    computeSumReference(a, b, n, m, result3);
    cout << "Result using reference: " << result3 << endl;

    return 0;
}
