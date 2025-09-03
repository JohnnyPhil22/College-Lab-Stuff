#include <iostream>
#include <cmath>
using namespace std;

class MyArray
{
private:
    double *arr;
    int size;

public:
    // Constructor
    MyArray(int s)
    {
        size = s;
        arr = new double[size];
    }

    // Constructor with values
    MyArray(double elements[], int s)
    {
        size = s;
        arr = new double[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = elements[i];
        }
    }

    // Destructor to free memory
    ~MyArray()
    {
        delete[] arr;
    }

    // Function to display the array
    void Display() const
    {
        cout << "[ ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }

    // Search using a for loop
    bool Search1(double x)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                return true;
            }
        }
        return false;
    }

    // Search using a while loop
    bool Search2(double x)
    {
        int i = 0;
        while (i < size)
        {
            if (arr[i] == x)
            {
                return true;
            }
            i++;
        }
        return false;
    }

    // Search using a do-while loop
    bool Search3(double x)
    {
        int i = 0;
        do
        {
            if (arr[i] == x)
            {
                return true;
            }
            i++;
        } while (i < size);
        return false;
    }

    // Recursive search
    bool Search4Helper(int index, double x)
    {
        if (index >= size)
        {
            return false;
        }
        if (arr[index] == x)
        {
            return true;
        }
        return Search4Helper(index + 1, x);
    }

    bool Search4(double x)
    {
        return Search4Helper(0, x);
    }

    // Check if all elements are even using a for loop
    bool IsAllEven1()
    {
        for (int i = 0; i < size; i++)
        {
            if (static_cast<int>(arr[i]) % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }

    // Check if all elements are even using a while loop
    bool IsAllEven2()
    {
        int i = 0;
        while (i < size)
        {
            if (static_cast<int>(arr[i]) % 2 != 0)
            {
                return false;
            }
            i++;
        }
        return true;
    }

    // Check if all elements are even using a do-while loop
    bool IsAllEven3()
    {
        int i = 0;
        do
        {
            if (static_cast<int>(arr[i]) % 2 != 0)
            {
                return false;
            }
            i++;
        } while (i < size);
        return true;
    }

    // Check if all elements are even using recursion
    bool IsAllEven4Helper(int index)
    {
        if (index >= size)
        {
            return true;
        }
        if (static_cast<int>(arr[index]) % 2 != 0)
        {
            return false;
        }
        return IsAllEven4Helper(index + 1);
    }

    bool IsAllEven4()
    {
        return IsAllEven4Helper(0);
    }

    // Find all indices where x appears and return a new MyArray
    MyArray FindIndices(double x)
    {
        MyArray indiceArr(size);
        int writeHead = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                indiceArr.arr[writeHead] = i;
                writeHead++;
            }
        }
        indiceArr.size = writeHead;
        return indiceArr;
    }

    // Swap all occurrences of x with y
    void SwapAll(double x, double y)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                arr[i] = y;
            }
        }
    }

    // Remove all occurrences of x
    void RemoveALL(double x)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == x)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                size--;
                i--;
            }
        }
    }
};

// Main function to test the class
int main()
{
    double elements[] = {1, 2, 2, 1, 4, 1};
    int size = sizeof(elements) / sizeof(elements[0]);

    MyArray myArray(elements, size);

    cout << "Original array: ";
    myArray.Display();

    // Search tests
    cout << "Search1 (2): " << (myArray.Search1(2) ? "Found" : "Not Found") << endl;
    cout << "Search2 (5): " << (myArray.Search2(5) ? "Found" : "Not Found") << endl;
    cout << "Search3 (1): " << (myArray.Search3(1) ? "Found" : "Not Found") << endl;
    cout << "Search4 (3): " << (myArray.Search4(3) ? "Found" : "Not Found") << endl;

    // Even number checks
    cout << "IsAllEven1: " << (myArray.IsAllEven1() ? "True" : "False") << endl;
    cout << "IsAllEven2: " << (myArray.IsAllEven2() ? "True" : "False") << endl;
    cout << "IsAllEven3: " << (myArray.IsAllEven3() ? "True" : "False") << endl;
    cout << "IsAllEven4: " << (myArray.IsAllEven4() ? "True" : "False") << endl;

    // Find indices of a given value
    MyArray indices = myArray.FindIndices(1);
    cout << "Indices of 1: ";
    indices.Display();

    // Swap values
    myArray.SwapAll(1, 5);
    cout << "After swapping 1 with 5: ";
    myArray.Display();

    // Remove all occurrences of a value
    myArray.RemoveALL(5);
    cout << "After removing all 5s: ";
    myArray.Display();

    return 0;
}
