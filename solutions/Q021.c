#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005
#define read(x) scanf("%d", &(x))

int s[MAXN];

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void sol() {
    int n;
    if (scanf("%d", &n) != 1) return;
    for (int i = 0; i < n; i++) {
        read(s[i]);
    }
    qsort(s, n, sizeof(int), cmp);
    int treats = 1;
    long long total = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1]) treats++;
        total += treats;
    }
    printf("%lld\n", total);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) sol();
    }
    return 0;
}
