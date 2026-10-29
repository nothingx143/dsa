#include <stdio.h>
#include <string.h>

char nums[13][256] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE"};

#define ADD(v) for(int i=0;nums[v][i];i++) c[nums[v][i]-'A']++;

int main() {
    char s[99], l[999];
    int n, c[26] = {0}, p = 0;
    while (scanf("%s", s) == 1) {
        int v = 999;
        sscanf(s, "%d", &v);
        int len = strlen(s);
        memcpy(l + p, s, len);
        p += len;
        l[p++] = ' ';
        l[p] = 0;
        if (v >= 0 && v <= 12) {
            ADD(v);
        }
        if (v == 999) {
            l[p - 1] = '.';
            printf("%s", l);
            for(n=0;n<26;n++)
                while (c[n]--) printf(" %c", 'A' + n);
            printf("\n");
            memset(c, 0, sizeof(c));
            p = 0;
        }
    }
    return 0;
}

