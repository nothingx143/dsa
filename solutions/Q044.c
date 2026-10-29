#include <stdio.h>

int main() {
    int n, top = -1, ans = 0;
    scanf("%d", &n);
    int a[n], stck[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        while (top!=-1 && stck[top]<a[i]) {
            ans++;
            top--;
        }
        if (top != -1) ans++;
        stck[++top] = a[i];
    }
    printf("%d\n", ans);
    return 0;
}

