#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while(t-->0) {
        int n;
        scanf("%d", &n);
        int v[2005], h[2005];
        int min_c = 100000, max_c = -100000;
        for(int i = 0;i < n;i++) {
            int x, y;
            scanf("%d %d %d", &x, &y, &h[i]);
            v[i] = 2 * (x - y);
            if (v[i] < min_c) min_c = v[i];
            if (v[i] > max_c) max_c = v[i];
        }
        int l = min_c - 1, r = max_c + 1, ok = 0;
        while(l<= r) {
            int mid = (l+r)/2;
            long long pl = 0, pr = 0;
            for(int i = 0;i < n;i++) {
                if (v[i] < mid) pl += h[i];
                if (v[i] > mid) pr += h[i];
            }
            if (pl == pr) {
                ok = 1;
                break;
            }
            if (pl < pr) l = mid + 1;
            else r = mid - 1;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
