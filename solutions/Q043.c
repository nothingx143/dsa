#include <stdio.h>
#include <string.h>

typedef struct stack {
    int top;
    char a[1005];
} stack;

void arranging(char *s,int n,stack *p) {
    p->top = -1;
    char temp[1005];
    for (int i = 0; i < n; i++) {
        if (s[i] == '\\') {
            int k = 0;
            while (p->a[p->top] != '/') {
                temp[k++] = p->a[(p->top)--];
            }
            (p->top)--;
            for (int j = 0; j < k; j++) {
                p->a[++(p->top)] = temp[j];
            }
        } else {
            p->a[++(p->top)] = s[i];
        }
    }
    p->a[++(p->top)] = '\0';
    printf("%s\n", p->a);
}

int main() {
    char S[1005];
    stack s1;
    if (scanf("%s", S) == 1) {
        arranging(S,strlen(S),&s1);
    }
    return 0;
}

