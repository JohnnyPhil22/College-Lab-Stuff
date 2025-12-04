#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

template <typename T>
class TreeHeapPQ
{
private:
    // This is NOT linked-list based; we use pointers for tree structure only
    struct Node
    {
        T value;
        Node *left;
        Node *right;
        Node *parent;

        Node(T val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node *root;
    int heapSize;

    // Simple queue implementation for BFS traversal
    struct SimpleQueue
    {
        vector<Node *> data;
        int frontIdx;

        SimpleQueue() : frontIdx(0) {}

        void push(Node *node)
        {
            data.push_back(node);
        }

        Node *front()
        {
            if (empty())
                return nullptr;
            return data[frontIdx];
        }

        void pop()
        {
            if (!empty())
                frontIdx++;
        }

        bool empty() const
        {
            return frontIdx >= data.size();
        }

        void clear()
        {
            data.clear();
            frontIdx = 0;
        }
    };

    // Find position for next insertion (maintains complete binary tree)
    Node *findInsertPosition()
    {
        if (!root)
            return nullptr;

        SimpleQueue q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (!curr->left || !curr->right)
                return curr;

            q.push(curr->left);
            q.push(curr->right);
        }
        return nullptr;
    }

    // Find last node (rightmost node in last level)
    Node *findLastNode()
    {
        if (!root)
            return nullptr;

        SimpleQueue q;
        q.push(root);
        Node *last = nullptr;

        while (!q.empty())
        {
            last = q.front();
            q.pop();

            if (last->left)
                q.push(last->left);
            if (last->right)
                q.push(last->right);
        }
        return last;
    }

    // Swim (up-heap) operation
    void swim(Node *node)
    {
        while (node->parent && node->value > node->parent->value)
        {
            swap(node->value, node->parent->value);
            node = node->parent;
        }
    }

    // Sink (down-heap) operation
    void sink(Node *node)
    {
        while (node)
        {
            Node *largest = node;

            if (node->left && node->left->value > largest->value)
                largest = node->left;
            if (node->right && node->right->value > largest->value)
                largest = node->right;

            if (largest != node)
            {
                swap(node->value, largest->value);
                node = largest;
            }
            else
                break;
        }
    }

    // Helper function to compute height recursively
    int computeHeightHelper(Node *node) const
    {
        if (!node)
            return 0;
        return 1 + max(computeHeightHelper(node->left), computeHeightHelper(node->right));
    }

    // Helper function to count leaves recursively
    int computeLeavesHelper(Node *node) const
    {
        if (!node)
            return 0;
        if (!node->left && !node->right)
            return 1;
        return computeLeavesHelper(node->left) + computeLeavesHelper(node->right);
    }

    // Helper function to lookup a key
    bool lookupHelper(Node *node, T key) const
    {
        if (!node)
            return false;
        if (node->value == key)
            return true;
        return lookupHelper(node->left, key) || lookupHelper(node->right, key);
    }

    // Helper to find depth of a node
    int getDepth(Node *node) const
    {
        int depth = 0;
        Node *curr = node;
        while (curr && curr->parent)
        {
            depth++;
            curr = curr->parent;
        }
        return depth;
    }

    // Helper to get all nodes at a specific depth
    void getNodesAtDepth(Node *node, int targetDepth, int currDepth, vector<Node *> &result) const
    {
        if (!node)
            return;
        if (currDepth == targetDepth)
        {
            result.push_back(node);
            return;
        }
        getNodesAtDepth(node->left, targetDepth, currDepth + 1, result);
        getNodesAtDepth(node->right, targetDepth, currDepth + 1, result);
    }

    // Helper to check if aNode is descendant of current
    bool isDescendantHelper(Node *current, Node *aNode) const
    {
        if (!current)
            return false;
        if (current == aNode)
            return true;
        return isDescendantHelper(current->left, aNode) || isDescendantHelper(current->right, aNode);
    }

    // Helper to delete tree
    void deleteTree(Node *node)
    {
        if (!node)
            return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    TreeHeapPQ() : root(nullptr), heapSize(0) {}

    ~TreeHeapPQ()
    {
        deleteTree(root);
    }

    // Insert element into heap
    void insert(T value)
    {
        Node *newNode = new Node(value);

        if (!root)
        {
            root = newNode;
            heapSize = 1;
            return;
        }

        Node *parent = findInsertPosition();
        newNode->parent = parent;

        if (!parent->left)
            parent->left = newNode;
        else
            parent->right = newNode;

        heapSize++;
        swim(newNode);
    }

    // Delete and return maximum element
    T delMax()
    {
        if (!root)
            throw runtime_error("Heap is empty");

        T maxVal = root->value;

        if (heapSize == 1)
        {
            delete root;
            root = nullptr;
            heapSize = 0;
            return maxVal;
        }

        Node *last = findLastNode();
        root->value = last->value;

        // Remove last node
        if (last->parent)
        {
            if (last->parent->right == last)
                last->parent->right = nullptr;
            else
                last->parent->left = nullptr;
        }
        delete last;
        heapSize--;

        if (root)
            sink(root);

        return maxVal;
    }

    // Peek at maximum element without removing it
    T max() const
    {
        if (!root)
            throw runtime_error("Heap is empty");
        return root->value;
    }

    bool empty() const { return heapSize == 0; }
    int size() const { return heapSize; }

    // i. Compute height of the heap binary tree
    int computeHeight() const
    {
        return computeHeightHelper(root);
    }

    // ii. Compute number of leaves in the heap binary tree
    int computeLeaves() const
    {
        return computeLeavesHelper(root);
    }

    // iii. Lookup - return true if key is found
    bool lookup(const T &key) const
    {
        return lookupHelper(root, key);
    }

    // iv. Get all nodes at the same level as current node
    vector<Node *> sameLevel(Node *current) const
    {
        vector<Node *> result;
        if (!current)
            return result;

        int depth = getDepth(current);
        getNodesAtDepth(root, depth, 0, result);
        return result;
    }

    // v. Check if aNode is a descendant of current node
    bool descendant(Node *current, Node *aNode) const
    {
        if (!current || !aNode || current == aNode)
            return false;
        return isDescendantHelper(current, aNode);
    }

    // Get root node (for testing sameLevel and descendant functions)
    Node *getRoot() const { return root; }
};