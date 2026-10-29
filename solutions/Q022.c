#include <stdio.h>

int main() {
    int N, i, j;
    scanf("%d", &N);
    for(i=1; i<=N; i++) {
        int v = (i % 2) ? 1 : 2;
        for (j = 0; j < i; j++) printf("%d ", v + 2 * j);
        printf("\n");
    }
    return 0;
}
