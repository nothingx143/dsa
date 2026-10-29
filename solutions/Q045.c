#include <stdio.h>

int main() {
    int n, k, i;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    long long curr = arr[0], max_sum;
    for (i = 1; i < k; i++) {
        curr += arr[n - i];
    }
    max_sum = curr;
    for (i = 1; i < k; i++) {
        curr += arr[i] - arr[n - k + i];
        if (curr > max_sum) max_sum = curr;
    }
    printf("%lld\n", max_sum);
    return 0;
}

