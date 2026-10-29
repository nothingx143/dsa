#include <stdio.h>

int rotLeft(int arr[],int n,int d) {
    d %= n;
    int temp[105];
    for (int i = 0; i < n; i++) temp[i] = arr[(i + d) % n];
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    return 0;
}

int rotRight(int arr[],int n,int d) {
    d %= n;
    int temp[105];
    for (int i = 0; i < n; i++) temp[i] = arr[(i - d + n) % n];
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    return 0;
}

int main() {
    int n, d, a[105];
    char dir;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d %c", &d, &dir);
    if (dir == 'L') rotLeft(a, n, d);
    else rotRight(a, n, d);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

