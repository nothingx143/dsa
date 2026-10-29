#include <stdio.h>

#define MOD 1000000007

char cc[500005];
long long last[26];

int main() {
    scanf("%s", cc);
    long long total = 0;
    int i;
    for(i=0;cc[i];i++) {
        int idx = cc[i] - 'a';
        long long add = (total + 1 - last[idx] + MOD) % MOD;
        total = (total + add) % MOD;
        last[idx] = (last[idx] + add) % MOD;
    }
    printf("%lld\n", total);
    return 0;
}

