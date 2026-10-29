#include <stdio.h>
#include <string.h>

int max(int a,int b) {
    return a > b ? a : b;
}

#define SOLVE { \
    int n, k, p; \
    scanf("%d %d %d", &n, &k, &p); \
    int dp[1505]; \
    memset(dp, 0, sizeof(dp)); \
    for(int i = 0;i < n;i++) { \
        int pref[35]; pref[0] = 0; \
        for (int j = 1; j <= k; j++) { \
            int val; scanf("%d", &val); \
            pref[j] = pref[j - 1] + val; \
        } \
        for (int j = p; j >= 0; j--) { \
            for (int x = 1; x <= k && x <= j; x++) { \
                dp[j] = max(dp[j], dp[j - x] + pref[x]); \
            } \
        } \
    } \
    printf("%d\n", dp[p]); \
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) SOLVE
    return 0;
}
