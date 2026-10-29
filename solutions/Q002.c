#include <stdio.h>

int main() {
    int n, i, count = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        double width, height;
        scanf("%lf %lf", &width, &height);
        if(width/height>=1.6 && width/height<=1.7)
            count++;
        else if(height/width >=1.6 && height/width<=1.7)
            count++;
    }
    if(count >= 0) {
        printf("%d", count);
    }
    return 0;
}
