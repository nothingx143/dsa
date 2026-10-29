#include <stdio.h>

int main() {
    int T, n, d;
    scanf("%d", &T);
    for(int t=0;t<T;t++){
        scanf("%d %d", &n, &d);
        int bus[n];
        for(int i=n-1;i>=0;i--){
            scanf("%d", &bus[i]);
        }
        int j = 0;
        while(j < n){
            d = d - d % bus[j];
            j++;
        }
        printf("%d\n", d);
    }
    return 0;
}
