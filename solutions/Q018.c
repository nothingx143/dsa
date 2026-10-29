#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t>0) {
        int n, a[1005], k1, k2;
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        scanf("%d %d", &k1, &k2);
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<n-1-i;j++) {
                if (a[j] > a[j + 1]) {
                    int tmp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tmp;
                }
            }
        }
        long long sum = 0;
        for (int i = k1; i < k2 - 1; i++) sum += a[i];
        printf("%lld\n", sum);
        t--;
    }
    return 0;
}
