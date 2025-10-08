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
        if (!IsFull())
        {
            rear = (rear + 1) % capacity;
            q[rear] = x;
            size++;
        }
        else
        {
            cout << "Queue Overflow" << endl;
        }
    }

    double Dequeue()
    {
        if (!IsEmpty())
        {
            double item = q[front];
            front = (front + 1) % capacity;
            size--;
            return item;
        }
        else
        {
            cout << "Queue Underflow" << endl;
            return INT_MIN;
        }
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
        for (int i = 0; i < size; i++)
        {
            cout << "Element " << i << ": " << q[(front + i) % capacity] << endl;
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
