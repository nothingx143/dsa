#include <stdio.h>
#include <stdlib.h>

#define LEN 20

int main() {
    char var[3][LEN];
    char inp[3][LEN];
    double v[90] = {0};
    scanf("%s %s %s %s %s %s", var[0], inp[0], var[1], inp[1], var[2], inp[2]);
    v[(int)var[0][0]] = atof(inp[0]);
    v[(int)var[1][0]] = atof(inp[1]);
    v[(int)var[2][0]] = atof(inp[2]);
    int q = (inp[0][0] == '?') * var[0][0] + (inp[1][0] == '?') * var[1][0] + (inp[2][0] == '?') * var[2][0];
    if (q == 'M') printf("M %.2f\n", -v['D'] * v['X']);
    if (q == 'D') printf("d %.2f\n", -v['M'] / v['X']);
    if (q == 'X') printf("x %.2f\n", -v['M'] / v['D']);
    return 0;
}
