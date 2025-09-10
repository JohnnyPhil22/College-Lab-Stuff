#include <iostream>
using namespace std;

// Function that returns the maximum value in the array
double GetMax(const double *x, int n)
{
    double max = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] > max)
        {
            max = x[i];
        }
    }
    return max;
}

// Void function returning maximum value using a pointer
void GetMax(const double *x, int n, double *vmax)
{
    *vmax = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] > *vmax)
        {
            *vmax = x[i];
        }
    }
}

// Void function returning maximum value using a reference
void GetMax(const double *x, int n, double &vmax)
{
    vmax = x[0];
    for (int i = 1; i < n; i++)
    {
        if (x[i] > vmax)
        {
            vmax = x[i];
        }
    }
}

// Main function to test all three methods
int main()
{
    double arr[] = {3.2, 7.5, 12.8, 9.1, 4.4};
    int n = 5;

    // Using function that returns vmax
    double result1 = GetMax(arr, n);
    cout << "Max using return: " << result1 << endl;

    // Using function with pointer
    double result2;
    GetMax(arr, n, &result2);
    cout << "Max using pointer: " << result2 << endl;

    // Using function with reference
    double result3;
    GetMax(arr, n, result3);
    cout << "Max using reference: " << result3 << endl;

    return 0;
}
