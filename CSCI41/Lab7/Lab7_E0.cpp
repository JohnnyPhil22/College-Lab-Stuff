#include <iostream>
using namespace std;

class MyStack
{
public:
    MyStack()
    {
        s = nullptr;
        capacity = 0;
        size = 0;
    }

    MyStack(int capacity1)
    {
        s = new double[capacity1];
        capacity = capacity1;
        size = 0;
    }

    ~MyStack()
    {
        delete[] s;
    }

    bool IsFull()
    {
        return (size == capacity);
    }

    bool IsEmpty()
    {
        return (size == 0);
    }

    void Push(double x)
    {
        if (!IsFull())
        {
            s[size] = x;
            size++;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    double Pop()
    {
        if (!IsEmpty())
        {
            size--;
            return s[size];
        }
        else
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
    }

    double Top()
    {
        if (IsEmpty())
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
        return s[size - 1];
    }

    void Display()
    {
        cout << "Max capacity: " << capacity << endl
             << "Current size: " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Element " << i << ": " << s[i] << endl;
        }
        cout << endl;
    }

private:
    double *s;
    int capacity;
    int size;
};

int main()
{
    MyStack stack(5);
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Display();
    cout << "Top: " << stack.Top() << endl;
    cout << "Popped: " << stack.Pop() << endl;
    stack.Display();
    return 0;
}