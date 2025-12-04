#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <type_traits>
#include <algorithm>
#include <string>

#include "vector-heap.cpp"
#include "tree-heap.cpp"

using namespace std;
using namespace std::chrono;

// Keep the 100 smallest using a max-heap PQ of fixed size 100
template <typename T, typename PQ>
vector<T> find100Smallest(const vector<T> &data, PQ &pq)
{
    const int K = 100;
    for (int i = 0; i < (int)data.size(); ++i)
    {
        if (pq.size() < K)
        {
            pq.insert(data[i]);
        }
        else if (data[i] < pq.max())
        {
            pq.delMax();
            pq.insert(data[i]);
        }
    }

    vector<T> res;
    while (!pq.empty())
    {
        res.push_back(pq.delMax()); // from largest to smallest among the 100
    }
    sort(res.begin(), res.end()); // ascending
    return res;
}

// Generate N random values of type T
template <typename T>
vector<T> generateData(int N)
{
    static random_device rd;
    static mt19937_64 gen(rd());

    vector<T> v(N);

    if constexpr (is_floating_point<T>::value)
    {
        uniform_real_distribution<long double> dist(0.0L, 1e6L);
        for (int i = 0; i < N; ++i)
        {
            v[i] = static_cast<T>(dist(gen));
        }
    }
    else
    {
        uniform_int_distribution<long long> dist(0, 1000000);
        for (int i = 0; i < N; ++i)
        {
            v[i] = static_cast<T>(dist(gen));
        }
    }

    return v;
}

// Run 5 times for one type, for both implementations, and print average time
template <typename T>
void benchmarkType(const string &typeName)
{
    const int N = 100000;
    const int RUNS = 5;

    double arrayTotalMs = 0.0;
    double treeTotalMs = 0.0;

    cout << "=== Type: " << typeName << " ===\n";

    for (int r = 0; r < RUNS; ++r)
    {
        auto data = generateData<T>(N);

        // ----- Array-based heap -----
        {
            VectorHeapPQ<T> pq;
            auto start = high_resolution_clock::now();
            auto smallest = find100Smallest(data, pq);
            auto end = high_resolution_clock::now();
            arrayTotalMs += duration<double, milli>(end - start).count();

            // Print the 100 smallest once (first run) for assignment requirement
            if (r == 0)
            {
                cout << "[Vector Heap Priority Queue] 100 smallest (" << typeName << "):\n";
                for (const auto &x : smallest)
                    cout << x << " ";
                cout << "\n\n";
            }
        }

        // ----- Tree-based heap -----
        {
            TreeHeapPQ<T> pq;
            auto start = high_resolution_clock::now();
            auto smallest = find100Smallest(data, pq);
            auto end = high_resolution_clock::now();
            treeTotalMs += duration<double, milli>(end - start).count();

            // Print the 100 smallest once (first run)
            if (r == 0)
            {
                cout << "[Tree Heap Priority Queue] 100 smallest (" << typeName << "):\n";
                for (const auto &x : smallest)
                    cout << x << " ";
                cout << "\n\n";
            }
        }
    }

    cout << "Average over " << RUNS << " runs (" << typeName << "):" << endl
         << "    Vector heap: " << (arrayTotalMs / RUNS) << " ms" << endl
         << "    Tree heap: " << (treeTotalMs / RUNS) << " ms" << endl << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    benchmarkType<int>("int");
    benchmarkType<long>("long");
    benchmarkType<long long>("long long");
    benchmarkType<float>("float");
    benchmarkType<double>("double");
    benchmarkType<long double>("long double");

    return 0;
}