#include <iostream>
#include <stack>
using namespace std;

// Recursive solution for Tower of Hanoi
void hanoiRecursive(int n, char source, char auxiliary, char target)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    hanoiRecursive(n - 1, source, target, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    hanoiRecursive(n - 1, auxiliary, source, target); // Time complexity: O(2^n)
}

// Iterative (non-recursive) solution for Tower of Hanoi
void hanoiIterative(int n, char source, char auxiliary, char target)
{
    stack<pair<int, pair<char, char>>> s;
    s.push({n, {source, target}});

    while (!s.empty())
    {
        auto [numDisks, rods] = s.top();
        s.pop();
        char fromRod = rods.first;
        char toRod = rods.second;
        char auxRod = 'A' + 'B' + 'C' - fromRod - toRod;

        if (numDisks == 1)
        {
            cout << "Move disk 1 from " << fromRod << " to " << toRod << endl;
        }
        else
        {
            s.push({numDisks - 1, {auxRod, toRod}});
            s.push({1, {fromRod, toRod}});
            s.push({numDisks - 1, {fromRod, auxRod}});
        }
    } // Time complexity: O(2^n)
}

int main()
{
    int numDisks = 3;
    cout << "Recursive Tower of Hanoi:" << endl;
    hanoiRecursive(numDisks, 'A', 'B', 'C');

    cout << "\nIterative Tower of Hanoi:" << endl;
    hanoiIterative(numDisks, 'A', 'B', 'C');

    return 0;
}
