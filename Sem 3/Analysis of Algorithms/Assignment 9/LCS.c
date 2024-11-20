// Use dynamic programming to solve LCS problem
#include <stdio.h>
#include <string.h>

void lcs(const char *s1, const char *s2)
{
    int m = strlen(s1), n = strlen(s2), i, j;
    int arr[m + 1][n + 1];

    for (i = 0; i <= m; i++)
    {
        arr[i][0] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        arr[0][j] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }
            else
            {
                arr[i][j] = (arr[i - 1][j] > arr[i][j - 1]) ? arr[i - 1][j] : arr[i][j - 1];
            }
        }
    }
    printf("Length of LCS: %d", arr[m][n]);

    i = m;
    j = n;
    char string[100];
    int ind = arr[m][n];
    string[ind] = '\0';
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            string[--ind] = s1[i - 1];
            i--;
            j--;
        }
        else if (arr[i - 1][j] > arr[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("\nLCS String: %s", string);
}

void main()
{
    char s1[] = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    char s2[] = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    lcs(s1, s2);
}