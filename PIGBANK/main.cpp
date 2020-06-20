#include <bits/stdc++.h>
using namespace std;
#define INTMAX 9999999

void unboundedKnapsack_min(int amountOfDifferentCoins, int val[], int wt[], int wantedWeight)
{
    int dp[wantedWeight + 1];
    for (int i = 1; i < wantedWeight + 1; ++i)
    {
        dp[i] = INTMAX;
    }
    dp[0] = 0;

    for (int i = 1; i <= wantedWeight; ++i)
    {
        for (int k = 0; k < amountOfDifferentCoins; ++k)
        {
            if (wt[k] <= i)
            {
                dp[i] = min(dp[i], dp[i - wt[k]] + val[k]);
            }
        }
    }

    if (dp[wantedWeight] == INTMAX)
        printf("This is impossible.\n");
    else
        printf("The minimum amount of money in the piggy-bank is %d.\n", dp[wantedWeight]);
}

int main()
{
    int t, pig, bank, coinVariety, i;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &pig, &bank, &coinVariety);
        int val[coinVariety + 1], wt[coinVariety + 1];
        int w = bank - pig;
        for (i = 0; i < coinVariety; i++)
            scanf("%d%d", &val[i], &wt[i]);
        unboundedKnapsack_min(coinVariety, val, wt, w);
    }

    return 0;
}
