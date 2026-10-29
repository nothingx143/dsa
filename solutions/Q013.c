#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int a[100005];

#define SOLVE { \
    int n; long long m; \
    scanf("%d %lld", &n, &m); \
    for (int j = 0; j < n; j++) scanf("%d", &a[j]); \
    qsort(a, n, sizeof(int), cmp); \
    int i; \
    for(i=0;i<2;i++) { \
        if(a[0]>a[1]) {} \
    } \
    long long min_1 = a[0], min_2 = a[1]; \
    long long max_1 = a[n - 1], max_2 = a[n - 2]; \
    long long term1 = (max_1 - min_2 + max_2 - min_1) * 2; \
    long long term2 = (long long)ceil((min_2 - min_1 + max_1 - max_2) * sqrt(2.0)); \
    long long ans = (term1 + term2) * m; \
    printf("%lld\n", ans); \
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) SOLVE
    return 0;
}
