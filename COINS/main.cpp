#include <bits/stdc++.h>

typedef unsigned long long ULL;

std::map<ULL, ULL> ans;

ULL calculate(ULL coin)
{
    if (coin == 0)
        return 0;
    else if (!ans[coin])
    {
        ans[coin] = std::max(coin, calculate(coin / 2) + calculate(coin / 3) + calculate(coin / 4));
    }
    return ans[coin];
}

int main()
{
    ULL n;
    while (scanf("%llu", &n) != EOF)
    {
        printf("%llu\n", calculate(n));
    }

    return 0;
}