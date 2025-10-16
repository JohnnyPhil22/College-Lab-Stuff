#include <iostream>
using namespace std;

class MyQueue
{
public:
    MyQueue(int capacity1 = 10) // Constructor with default capacity
    {
        capacity = capacity1;
        front = size = 0;
        rear = capacity - 1;
        q = new double[capacity];
    }

    ~MyQueue() // Destructor
    {
        delete[] q;
    }

    bool IsFull() // Check if the queue is full
    {
        return (size == capacity);
    }

    bool IsEmpty() // Check if the queue is empty
    {
        return (size == 0);
    }

    void Enqueue(double x) // Add an element to the queue
    {
        if (!IsFull())
        {
            rear = (rear + 1) % capacity;
            q[rear] = x;
            size++;
        }
        else
        {
            cerr << "Queue Overflow" << endl;
        }
    }

    double Dequeue() // Remove and return the front element of the queue
    {
        if (IsEmpty()) // Queue is empty
        {
            cerr << "Queue Underflow" << endl;
            return INT_MIN;
        }
        double item = q[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    double Front() // Get the front element of the queue
    {
        if (IsEmpty()) // Queue is empty
        {
            cerr << "Queue Underflow" << endl;
            return INT_MIN;
        }
        return q[front];
    }

    double Rear() // Get the rear element of the queue
    {
        if (IsEmpty()) // Queue is empty
        {
            cerr << "Queue Underflow" << endl;
            return INT_MIN;
        }
        return q[rear];
    }

    void DisplayQueue() // Display all elements in the queue
    {
        cout << "Max capacity: " << capacity << endl
             << "Current size: " << size << endl;
        if (IsEmpty()) // If Queue is empty
        {
            cout << "Empty Queue" << endl;
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << "Element " << i << ": " << q[(front + i) % capacity] << endl;
        }
        cout << endl;
    }

    void DisplayAll() // Display all elements in the queue
    {
        DisplayQueue();
    }

private:
    int front, rear;
    int size;
    int capacity;
    double *q;
};

int main()
{
    MyQueue queue(5);
    queue.Enqueue(10);
    queue.Enqueue(20);
    queue.Enqueue(30);
    queue.Enqueue(40);
    queue.Enqueue(50);
    queue.DisplayQueue();
    cout << "Dequeued: " << queue.Dequeue() << endl;
    queue.Enqueue(60);
    queue.DisplayQueue();
    cout << "Front: " << queue.Front() << endl;
    cout << "Rear: " << queue.Rear() << endl;
    return 0;
}
