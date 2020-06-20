#include <stdio.h>
#include <cstdlib>
#include <time.h>

int n;
long long number;

long long powModulo(long long a, long long p) {
    long long mod = 1;
    for(long long i = 0; i < p; i++) {
        mod = mod*a%p;
    }
    return mod;
}

bool FermatTest(long long p, int t) {
    if(p<2) return false;
    if(p%2==0 && p!=2) return false;
    
    srand(time(NULL));
    long long a;
    for(int i = 0; i < t; i++) {
        a = (random()%(p-1))+1;
        if(a == powModulo(a, p)) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%llu", &number);
        if(FermatTest(number, 1)) printf("YES\n");
        else printf("NO\n");
    }
}