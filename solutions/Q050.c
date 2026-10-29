#include <stdio.h>
#include <stdlib.h>

long get_lint() {
    long x;
    scanf("%ld", &x);
    return x;
}

void put_lint (long li,char lc) {
    printf("%ld%c", li, lc);
}

long solve(long *a, long n, long k) {
    if (n == 1) return (k % 2 == 0) ? a[0] : -1;
    if (k == 1) return a[1];
    if (k <= n) return a[k - 2];
    return a[n - 1];
}

int main() {
    long n = get_lint();
    long k = get_lint();
    long *a = (long *)malloc(n * sizeof(long));
    for (long i = 0; i < n; i++) {
        a[i] = get_lint();
    }
    long ans = solve(a, n, k);
    put_lint (ans, '\n');
    return 0;
}
