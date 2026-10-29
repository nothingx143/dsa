#include <stdio.h>

void makeheap(int x[],int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        int val = x[i], s = i;
        while (2 * s + 1 < n) {
            int child = 2 * s + 1;
            if (child + 1 < n && x[child + 1] > x[child]) child++;
            if (val >= x[child]) break;
            x[s] = x[child];
            s = child;
        }
        x[s] = val;
    }
}

void heapsort(int x[],int n) {
    makeheap(x, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = x[0];
        x[0] = x[i];
        x[i] = temp;
        int val = x[0], s = 0;
        while (2 * s + 1 < i) {
            int child = 2 * s + 1;
            if (child + 1 < i && x[child + 1] > x[child]) child++;
            if (val >= x[child]) break;
            x[s] = x[child];
            s = child;
        }
        x[s] = val;
    }
}

int a[100005];

int main() {
    int T;
    if (scanf("%d", &T) == 1) {
        while (T--) {
            int n;
            long long b;
            scanf("%d %lld", &n, &b);
            for (int i = 0; i < n; i++) scanf("%d", &a[i]);
            makeheap(a,n);
            heapsort(a,n); 
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (b >= a[i]) {
                    b -= a[i];
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
