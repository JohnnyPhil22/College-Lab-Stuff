// Coin exchange using hoffmann coding and dynamic programming
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int coinExchange(int *coins, int coinCount, int targetAmount)
{
    int *dp = (int *)malloc((targetAmount + 1) * sizeof(int));

    for (int i = 0; i <= targetAmount; i++)
    {
        dp[i] = INT_MAX - 1;
    }
    dp[0] = 0;

    for (int i = 1; i <= targetAmount; i++)
    {
        for (int j = 0; j < coinCount; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }

    return (dp[targetAmount] == INT_MAX - 1) ? -1 : dp[targetAmount];
}

int *reconstructCoins(int *coins, int coinCount, int targetAmount, int *coinUsedCount)
{
    int *dp = (int *)malloc((targetAmount + 1) * sizeof(int)), *prevCoin = (int *)malloc((targetAmount + 1) * sizeof(int));

    for (int i = 0; i <= targetAmount; i++)
    {
        dp[i] = INT_MAX - 1;
        prevCoin[i] = -1;
    }
    dp[0] = 0;

    for (int i = 1; i <= targetAmount; i++)
    {
        for (int j = 0; j < coinCount; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                    prevCoin[i] = j;
                }
            }
        }
    }

    int *usedCoins = NULL;
    *coinUsedCount = 0;

    if (dp[targetAmount] != INT_MAX - 1)
    {
        usedCoins = (int *)malloc(dp[targetAmount] * sizeof(int));
        int remaining = targetAmount;

        while (remaining > 0)
        {
            int coinIndex = prevCoin[remaining];
            usedCoins[(*coinUsedCount)++] = coins[coinIndex];
            remaining -= coins[coinIndex];
        }
    }

    return usedCoins;
}

void main()
{
    int coins[] = {1, 25, 50};
    int coinCount = sizeof(coins) / sizeof(coins[0]), targetAmount;
    printf("Enter amount: ");
    scanf("%d", &targetAmount);

    int minCoins = coinExchange(coins, coinCount, targetAmount);

    printf("Minimum coins needed to make %d: %d\n", targetAmount, minCoins);

    int coinUsedCount = 0;
    int *usedCoins = reconstructCoins(coins, coinCount, targetAmount, &coinUsedCount);

    if (usedCoins != NULL)
    {
        printf("Coins used: ");
        for (int i = 0; i < coinUsedCount; i++)
        {
            printf("%d ", usedCoins[i]);
        }
        printf("\n");
    }
}