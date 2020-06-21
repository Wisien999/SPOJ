#include <bits/stdc++.h>

using namespace std;

void simpleSieveOfErathosthenes(int max, vector<int> &primes)
{
    bool mark[max + 1];
    memset(mark, true, sizeof(mark));

    for (int p = 2; p * p < max; p++)
    {
        if (mark[p])
        {
            for (int i = p*2; i <= max; i += p)
            {
                mark[i] = false;
            }
        }
    }

    for (int i = 2; i <= max; ++i)
    {
        if (mark[i])
        {
            primes.push_back(i);
        }
    }
}

void segmentedSieve(int start, int end)
{
    if (start == 1)
        start = 2;
    // Store all primes from 2 to sqrt(end) in primes
    vector<int> primes;
    int limit = floor(sqrt(end)) + 1;
    simpleSieveOfErathosthenes(limit, primes);

    // Divide range in parts of sqrt(end) length
    int range = end - start + 1;
    bool mark[range + 1];
    memset(mark, true, sizeof(mark));

    // use previously found primes to mark their multiples as not prime
    for (int p = 0; p < primes.size(); p++)
    {
        // find the smallest multiple of the current prime in the range
        int prime = (int)(floor(start / primes[p])) * primes[p];
        if (prime < start)
            prime += primes[p];

        // Skip marking first prime if it is in wanted interval
        if (start <= primes[p])
            prime += primes[p];

        // mark multiplies as not prime
        for (int i = prime; i <= end; i += primes[p])
            mark[i - start] = false;
    }

    // add primes from current range to answer tab
    for (int i = start; i <= end; i++)
    {
        if (mark[i - start])
        {
            printf("%d\n", i);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        segmentedSieve(a, b);
        if (T != 0)
            printf("\n");
    }
    return 0;
}
