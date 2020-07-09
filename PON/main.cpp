#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef unsigned long long ULL;

ULL moduloMultiplication(ULL a, ULL b, ULL mod)
{
    ULL res = 0; // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= mod;

    while (b > 0)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;

        b >>= 1; // b = b / 2
    }

    return res;
}

ULL powModulo(ULL base, ULL index, ULL mod) {
    ULL x = 1;

    while(index > 0) {
        if((index&1)) x = moduloMultiplication(x, base, mod);

        base = moduloMultiplication(base, base, mod);
        index >>=1;
    }

    return x;
}
bool miller_rabin(ULL p, int it) {
    if(p < 2) return false;
    if(p == 2) return true;
    if((p&1) == 0) return false;

    ULL pr = p - 1;

    while((pr&1)==0){
        pr >>= 1;
    }

    for(int i = 0; i < it; i++) {
        ULL a = rand()%(p-3)+2;
        ULL temp = pr;
		ULL mod = powModulo(a,temp,p);

		if(mod==-1 || mod==1) continue;

		while(temp!=p-1 && mod!=p-1) {
			mod = moduloMultiplication(mod,mod,p);
            if(mod == 1) return false;
			temp <<= 1;
		}

		if(mod!=p-1) return false;
	}

    return true;
}

int main() {
    int t = 5;
    ULL N;
    srand(time(NULL));


    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        scanf("%llu", &N);
        printf("%s\n",miller_rabin(N,18)? "YES" : "NO");
    }
    return 0;
}