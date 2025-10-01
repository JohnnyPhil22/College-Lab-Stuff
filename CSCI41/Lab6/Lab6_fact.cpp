#include <iostream>
using namespace std;

// Factorial using for loop
int factorialFor(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res; // Time complexity: O(n)
}

// Factorial using while loop
int factorialWhile(int n)
{
    int res = 1, i = 1;
    while (i <= n)
    {
        res *= i;
        i++;
    }
    return res; // Time complexity: O(n)
}

// Factorial using recursion
int factorialRecursive(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorialRecursive(n - 1); // Time complexity: O(n)
}

int main()
{
    int num = 5;
    cout << "Factorial (for loop): " << factorialFor(num) << endl;
    cout << "Factorial (while loop): " << factorialWhile(num) << endl;
    cout << "Factorial (recursion): " << factorialRecursive(num) << endl;
    return 0;
}
