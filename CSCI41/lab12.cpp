#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class PriorityQueue
{
private:
    // Each element is a pair of (priority, item)
    vector<pair<int, string>> heap;

    // Helper function to maintain heap property (up-heap bubbling)
    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[index].first < heap[parent].first)
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    // Helper function to maintain heap property (down-heap bubbling)
    void heapifyDown(int index)
    {
        int size = heap.size();
        while (index < size)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left].first < heap[smallest].first)
                smallest = left;
            if (right < size && heap[right].first < heap[smallest].first)
                smallest = right;

            if (smallest != index)
            {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else
            {
                break;
            }
        }
    }

public:
    // Insert item with a given priority
    void insert(string item, int priority)
    {
        heap.push_back({priority, item}); // Add new element at the end
        heapifyUp(heap.size() - 1);       // Restore heap property
    }

    // Remove and return the item with the highest priority
    string poll()
    {
        if (heap.empty()) // Check if heap is empty
        {
            throw runtime_error("Priority Queue Empty");
        }
        string res = heap[0].second; // Store the root element (highest priority)
        heap[0] = heap.back();       // Move the last element to the root
        heap.pop_back();             // Remove the last element
        heapifyDown(0);              // Restore heap property
        return res;                  // Return the highest priority item
    }

    // Return the item with the highest priority without removing it
    string peek() const
    {
        if (heap.empty()) // Check if heap is empty
        {
            throw runtime_error("Priority Queue Empty");
        }
        return heap[0].second; // Return the root element (highest priority)
    }

    // Utility to display the entire heap
    void display() const
    {
        cout << "Priority Queue Contents: ";
        for (const auto &elem : heap)
        {
            cout << "(" << elem.first << ": " << elem.second << ") "; // (priority, item)
        }
        cout << endl;
    }
};

// Main function to demonstrate functionality
int main()
{
    PriorityQueue pq;

    pq.insert("Task A", 4);
    pq.insert("Task B", 2);
    pq.insert("Task C", 5);
    pq.insert("Task D", 1);

    pq.display();

    cout << "Peek (highest priority): " << pq.peek() << endl;

    cout << "Polling (removing highest priority): " << pq.poll() << endl;
    pq.display();

    cout << "Polling again: " << pq.poll() << endl;
    pq.display();

    pq.insert("Task E", 3);
    pq.display();

    return 0;
}
