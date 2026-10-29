#include <stdio.h>
#include <string.h>

#define IF_COND(c) if (c)
#define FOR_LOOP(i, n) for (int i = 0; i < n; i++)

char str[200005], cL[800005], cR[800005];
int pr[800005], sf[800005], mx[800005], sz[800005];

void pull(int k,int l,int r) {
    int a = 2 * k, b = a + 1;
    cL[k] = cL[a]; cR[k] = cR[b];
    sz[k] = sz[a] + sz[b];
    pr[k] = pr[a]; sf[k] = sf[b];
    int m = (mx[a] > mx[b]) ? mx[a] : mx[b];
    IF_COND(cR[a] == cL[b]) {
        IF_COND(sf[a] + pr[b] > m) m = sf[a] + pr[b];
        IF_COND(pr[a] == sz[a]) pr[k] = sz[a] + pr[b];
        IF_COND(sf[b] == sz[b]) sf[k] = sz[b] + sf[a];
    }
    mx[k] = m;
}

void build(int k, int l, int r) {
    IF_COND(l == r) {
        cL[k] = cR[k] = str[l];
        pr[k] = sf[k] = mx[k] = sz[k] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(2 * k, l, m);
    build(2 * k + 1, m + 1, r);
    pull(k, l, r);
}

void update(int k, int l, int r, int pos) {
    IF_COND(l == r) {
        cL[k] = cR[k] = cL[k] ^ 1;
        return;
    }
    int m = (l + r) / 2;
    IF_COND(pos <= m) update(2 * k, l, m, pos);
    else update(2 * k + 1, m + 1, r, pos);
    pull(k, l, r);
}

int main() {
    scanf("%s", str + 1);
    int n = strlen(str + 1), m, pos;
    build(1, 1, n);
    scanf("%d", &m);
    FOR_LOOP(i, m) {
        scanf("%d", &pos);
        update(1, 1, n, pos);
        printf("%d ", mx[1]);
    }
    printf("\n");
    return 0;
}

