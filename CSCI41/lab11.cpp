#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class ChainedList
{
private:
    Node *head;

    // Helper to get the tail of the list
    Node *getTail(Node *node)
    {
        while (node && node->next)
            node = node->next;
        return node;
    }

    // Partition the list for quicksort
    Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
    {
        Node *pivot = end;
        Node *prev = nullptr, *cur = head, *tail = pivot;

        *newHead = nullptr;
        *newEnd = nullptr;

        while (cur != pivot)
        {
            if (cur->data < pivot->data)
            {
                if (!*newHead)
                    *newHead = cur;

                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                    prev->next = cur->next;

                Node *tmp = cur->next;
                cur->next = nullptr;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (!*newHead)
            *newHead = pivot;

        *newEnd = tail;
        return pivot;
    }

    // Recursive quicksort
    Node *quickSortRecur(Node *head, Node *end)
    {
        if (!head || head == end)
            return head;

        Node *newHead = nullptr, *newEnd = nullptr;

        Node *pivot = partition(head, end, &newHead, &newEnd);

        // Sort the list before pivot
        if (newHead != pivot)
        {
            // Find the node before pivot to end the first half
            Node *temp = newHead;
            while (temp->next != pivot)
            {
                temp = temp->next;
            }
            temp->next = nullptr;

            // Recur for the list before pivot
            newHead = quickSortRecur(newHead, temp);

            // Connect the end of the first half to pivot
            Node *temp2 = getTail(newHead);
            temp2->next = pivot;
        }

        // Sort the list after pivot
        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

public:
    ChainedList() : head(nullptr) {}

    void insert(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void display() // Display the list
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }

    void quickSort()
    {
        head = quickSortRecur(head, getTail(head));
    }

    static ChainedList mergeSortedLists(ChainedList &list1, ChainedList &list2)
    {
        ChainedList result;
        Node dummy(0);
        Node *tail = &dummy;

        Node *a = list1.head;
        Node *b = list2.head;

        // Merge the two lists
        while (a && b)
        {
            if (a->data <= b->data) // If a's data is smaller or equal
            {
                tail->next = a;
                a = a->next;
            }
            else // If b's data is smaller
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        // Attach the remaining elements
        tail->next = (a) ? a : b;

        // Set the head of the result list
        result.head = dummy.next;
        list1.head = nullptr; // Clear list1
        list2.head = nullptr; // Clear list2

        return result;
    }
};

int main()
{
    // Example: Insert and display
    ChainedList list;
    list.insert(3);
    list.insert(1);
    list.insert(7);
    list.insert(5);
    cout << "Original List: ";
    list.display();

    // Example: QuickSort
    list.quickSort();
    cout << "Sorted List using QuickSort: ";
    list.display();

    // Example: Merge two sorted lists
    ChainedList listA, listB;
    listA.insert(10);
    listA.insert(5);
    listA.insert(1);
    listA.quickSort();

    listB.insert(9);
    listB.insert(4);
    listB.insert(2);
    listB.quickSort();

    cout << "List A: ";
    listA.display();
    cout << "List B: ";
    listB.display();

    ChainedList merged = ChainedList::mergeSortedLists(listA, listB);
    cout << "Merged Sorted List: ";
    merged.display();

    return 0;
}
