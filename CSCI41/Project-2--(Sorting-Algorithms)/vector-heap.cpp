#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class VectorHeapPQ
{
private:
    vector<T> heap;

    // Swim (up-heap) - move element up to restore heap property
    void swim(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) // Max-heap: larger values bubble up
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
                break;
        }
    }

    // Sink (down-heap) - move element down to restore heap property
    void sink(int index)
    {
        int size = heap.size();
        while (index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
                break;
        }
    }

public:
    VectorHeapPQ() {}

    // Insert element into heap
    void insert(T value)
    {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    // Delete and return maximum element
    T delMax()
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        T maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            sink(0);
        return maxVal;
    }

    // Peek at maximum element without removing it
    T max() const
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        return heap[0];
    }

    bool empty() const { return heap.empty(); }
    int size() const { return heap.size(); }
    void clear() { heap.clear(); }
};