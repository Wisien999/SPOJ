#include <stdio.h>

int n, x;
bool isPrime;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        isPrime = true;
        scanf("%d", &x);
        if(x%2 == 0){
            isPrime = false;
        }
        else {
            for(int j = 3; j*j < x; x+=2){
                if(x%j == 0){
                    isPrime = false;
                }
            }
        }
        if(isPrime) printf("%s", "YES");
        else printf("%s", "NO");
    }
}