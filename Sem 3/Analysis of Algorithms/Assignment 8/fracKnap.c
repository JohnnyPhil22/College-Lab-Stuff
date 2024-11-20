// Fractional Knapsack using greedy algorithm
#include <stdio.h>
#include <stdlib.h>

struct item
{
    int profit, weight, ratio;
};

int compare(const void *a, const void *b)
{
    struct item *itemA = (struct item *)a;
    struct item *itemB = (struct item *)b;
    return (itemB->ratio - itemA->ratio) > 0 ? 1 : -1;
}

double fracKnap(struct item *items, int n, int capacity)
{
    qsort(items, n, sizeof(struct item), compare);

    double totProfit = 0.0;
    int currWeight = 0, i;

    for (i = 0; i < n; i++)
    {
        if (currWeight + items[i].weight <= capacity)
        {
            currWeight += items[i].weight;
            totProfit += items[i].profit;
        }
        else
        {
            int remainingCapacity = capacity - currWeight;
            totProfit += items[i].profit * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }
    return totProfit;
}

void main()
{
    int n = 3, capacity = 50;
    struct item items[3] = {{60, 10}, {100, 20}, {120, 30}};
    for (int i = 0; i < n; i++)
    {
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }
    printf("Maximum value in Knapsack = %.2f\n", fracKnap(items, n, capacity));
}