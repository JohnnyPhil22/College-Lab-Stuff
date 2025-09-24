// Jonathan Vijay Philips
// CSCI 41 Lab5
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printNaturalNumbers(int count)
{
	if (count == 0)
	{
		return;
	}
	printNaturalNumbers(count - 1);
	cout << count << " ";
	if (count % 10 == 0)
	{
		cout << endl;
	}
}

int calculateFactorial(int count, int n)
{
	if (count > n)
	{
		return 1;
	}
	return count * calculateFactorial(count + 1, n);
}

int calculateFibonacci(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
}

void printFibonacciSeries(int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << calculateFibonacci(i) << " ";
	}
}

void printArrayElements(int *arr, int size, int count)
{
	if (count >= size)
	{
		return;
	}
	cout << arr[count] << " ";
	printArrayElements(arr, size, count + 1);
}

int countDigits(int number, int count)
{
	if (number == 0)
	{
		return count;
	}
	return countDigits(floor(number / 10), count + 1);
}

int findGCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return findGCD(b, a % b);
}

int getLargestElement(int arr[], int size, int largest, int count)
{
	if (count >= size)
	{
		return largest;
	}
	if (arr[count] > largest)
	{
		largest = arr[count];
	}
	return getLargestElement(arr, size, largest, count + 1);
}

string convertToBinary(int num, string bit)
{
	if (num == 0)
	{
		return "0";
	}
	if (num == 1)
	{
		return "1" + bit;
	}
	bit = to_string(num % 2) + bit;
	return convertToBinary(num / 2, bit);
}

bool checkPrimeNumber(int num, int prime)
{
	if (num < 2)
	{
		return false;
	}
	if (num == 2)
	{
		return true;
	}
	if (num % prime == 0)
	{
		return false;
	}
	if (pow(prime, 2) > num)
	{
		return true;
	}
	return checkPrimeNumber(num, prime + 1);
}

int main()
{
	cout << "The natural numbers are: " << endl;
	printNaturalNumbers(50);
	cout << endl;

	cout << "The Factorial of number 5 is: " << calculateFactorial(1, 5) << endl
		 << endl;

	cout << "The Series is: " << endl;
	printFibonacciSeries(10);
	cout << endl
		 << endl;

	int *a = new int[10]{2, 4, 6, 8, 10, 12, 1, 3, 5, 7};
	cout << "The elements in the array are: " << endl;
	printArrayElements(a, 10, 0);
	cout << endl
		 << endl;

	cout << "The number of digits in the number 50 is: " << countDigits(50, 0) << endl
		 << endl;

	cout << "The GCD of 10 and 50 is: " << findGCD(10, 50) << endl
		 << endl;

	cout << "Largest element of the array is: " << getLargestElement(a, 10, INT_MIN, 0) << endl
		 << endl;

	int x = 57;
	cout << "The binary value of " << x << " is: " << convertToBinary(x, "") << endl
		 << endl;

	x = 43;
	cout << "The number " << x << " is " << (checkPrimeNumber(x, 2) ? "prime" : "not prime") << endl
		 << endl;

	return 0;
}