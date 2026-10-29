#include <stdio.h>

#define PREFIXES 9
char p[] = "BKMGTPEZY";
double siq[PREFIXES],b2q[PREFIXES];

int main() {
    double v;
    char u[5];
    int i, in_p = 0, j = PREFIXES - 1;
    siq[0] = b2q[0] = 1;
    for(i=1;i<PREFIXES;i++) { siq[i] = siq[i-1] * 1000; b2q[i] = b2q[i-1] * 1024; }
    scanf("%lf %s", &v, u);
    for (i = 0; i < PREFIXES; i++) if (p[i] == u[0]) in_p = i;
    double bytes = v * siq[in_p];
    while (j > 0 && bytes < b2q[j]) j--;
    printf("%.2f %ciB\n", bytes / b2q[j], p[j]);
    return 0;
}

