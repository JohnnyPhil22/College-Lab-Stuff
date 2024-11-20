// Use dynamic programming to solve matrix chain multiplication
#include <stdio.h>
#include <limits.h>

void parentheses(int i, int j, int n, int *bracket, char *name)
{
    if (i == j)
    {
        printf("%c", name[i - 1]);
        return;
    }
    printf("(");
    parentheses(i, *((bracket + i * n) + j), n, bracket, name);
    parentheses(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    printf(")");
}

void matrixChain(int arr[], int n)
{
    int i, j, k, chLen;
    int minMults[n][n], bracket[n][n];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            minMults[i][j] = 0;
            bracket[i][j] = 0;
        }
    }

    for (chLen = 2; chLen < n; chLen++)
    {
        for (i = 1; i < n - chLen + 1; i++)
        {
            j = i + chLen - 1;
            minMults[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                int q = minMults[i][k] + minMults[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < minMults[i][j])
                {
                    minMults[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    char name[n];
    for (i = 0; i < n; i++)
    {
        name[i] = 'A' + i;
    }

    printf("Optimal Parenthesization: ");
    parentheses(1, n - 1, n, (int *)bracket, name);
    printf("\nOptimal Cost: %d\n", minMults[1][n - 1]);
}

void main()
{
    int arr[] = {100, 10, 50, 20, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    matrixChain(arr, size);
}