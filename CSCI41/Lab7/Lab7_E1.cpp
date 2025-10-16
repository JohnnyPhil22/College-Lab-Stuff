#include <iostream>
using namespace std;

class MyQueue
{
public:
    MyQueue()
    {
        capacity = 0;
        front = size = 0;
        rear = capacity - 1;
        q = nullptr;
    }

    MyQueue(int capacity1)
    {
        capacity = capacity1;
        front = size = 0;
        rear = capacity - 1;
        q = new double[capacity];
    }

    ~MyQueue()
    {
        delete[] q;
    }

    bool IsFull()
    {
        return (size == capacity);
    }

    bool IsEmpty()
    {
        return (size == 0);
    }

    void Enqueue(double x)
    {
        if (IsFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (IsEmpty())
        {
            front = 0;
            rear = -1;
        }
        rear += 1;
        q[rear] = x;
        size += 1;
    }

    double Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue Underflow" << endl;
            return INT_MIN;
        }
        double item = q[front];
        front += 1;
        size -= 1;

        // When queue becomes empty, reset indices so it can be reused linearly.
        if (size == 0)
        {
            front = 0;
            rear = -1;
        }
        return item;
    }

    double Front()
    {
        if (IsEmpty())
        {
            cout << "Empty Queue" << endl;
            return INT_MIN;
        }
        return q[front];
    }

    double Rear()
    {
        if (IsEmpty())
        {
            cout << "Empty Queue" << endl;
            return INT_MIN;
        }
        return q[rear];
    }

    void DisplayQueue()
    {
        cout << "Max capacity: " << capacity << endl
             << "Current size: " << size << endl;
        if (IsEmpty())
        {
            cout << "Empty Queue" << endl;
            return;
        }
        for (int i = front; i <= rear; ++i)
        {
            cout << "Element " << (i - front) << ": " << q[i] << endl;
        }
        cout << endl;
    }

    void DisplayAll()
    {
        DisplayQueue();
    }

private:
    int front, rear, size, capacity;
    double *q;
};

int main()
{
    MyQueue queue(5);
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.DisplayQueue();
    cout << "Front: " << queue.Front() << endl;
    cout << "Rear: " << queue.Rear() << endl;
    cout << "Dequeued: " << queue.Dequeue() << endl;
    queue.DisplayQueue();
    return 0;
}
