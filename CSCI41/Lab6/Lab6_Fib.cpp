#include <iostream>
using namespace std;

// Fibonacci using for loop
int fibonacciFor(int n)
{
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c; // Time complexity: O(n)
}

// Fibonacci using while loop
int fibonacciWhile(int n)
{
    int a = 0, b = 1, c;
    int i = 2;
    while (i <= n)
    {
        c = a + b;
        a = b;
        b = c;
        i++;
    }
    return c; // Time complexity: O(n)
}

// Fibonacci using recursion
int fibonacciRecursive(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    } // Time complexity: O(2^n)
}

int main()
{
    int num = 6;
    cout << "Fibonacci (for loop): " << fibonacciFor(num) << endl;
    cout << "Fibonacci (while loop): " << fibonacciWhile(num) << endl;
    cout << "Fibonacci (recursion): " << fibonacciRecursive(num) << endl;
    return 0;
}
