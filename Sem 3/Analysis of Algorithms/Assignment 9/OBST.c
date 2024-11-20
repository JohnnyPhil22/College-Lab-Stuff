// Use dynamic programming to solve OBST problem
#include <stdio.h>
#include <limits.h>

int root[100][100] = {0};

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

void printOBSTStructure(int keys[], int root[][100], int n, int i, int j, int level)
{
    if (i > j)
    {
        return;
    }

    int r = root[i][j];

    printf("Root: %d\n", keys[r]);

    if (r > i)
    {
        printf("\nLeft Subtree:\n");
        printOBSTStructure(keys, root, n, i, r - 1, level + 2);
    }

    if (r < j)
    {
        printf("\nRight Subtree:\n");
        printOBSTStructure(keys, root, n, r + 1, j, level + 2);
    }
}

int obst(int keys[], int freq[], int n)
{
    int dp[n][n];

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = freq[i];
        root[i][i] = i;
    }

    for (int chain_len = 2; chain_len <= n; chain_len++)
    {
        for (int i = 0; i < n - chain_len + 1; i++)
        {
            int j = i + chain_len - 1;
            dp[i][j] = INT_MAX;
            int fsum = sum(freq, i, j);

            for (int r = i; r <= j; r++)
            {
                int left_cost = (r > i) ? dp[i][r - 1] : 0;
                int right_cost = (r < j) ? dp[r + 1][j] : 0;
                int total_cost = left_cost + right_cost + fsum;
                if (total_cost < dp[i][j])
                {
                    dp[i][j] = total_cost;
                    root[i][j] = r;
                }
            }
        }
    }
    return dp[0][n - 1];
}

void main()
{
    int keys[] = {10, 12, 20}, freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]), cost = obst(keys, freq, n);

    printf("Cost of OBST: %d\nOBST Structure:\n", cost);
    printOBSTStructure(keys, root, n, 0, n - 1, 0);
}