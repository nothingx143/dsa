#include <stdio.h>
#include <string.h>

#define MAXP 45
#define BUFLEN 105

char *gems[]={"NONE","Garnet","Amethyst","Aquamarine","Diamond","Emerald","Pearl","Ruby","Peridot","Sapphire","Tourmaline","Topaz","Lapis",0};
char ponies[MAXP][BUFLEN];
int ranks[MAXP];

int match_gem(char *tok) {
    for (int i = 1; gems[i]; i++)
        if (strcmp(tok, gems[i]) == 0) return i;
    return 0;
}

int get_rank(char *name) {
    char tmp[BUFLEN];
    strcpy(tmp, name);
    int best = 0;
    for (char *t = strtok(tmp, " \r\n"); t; t = strtok(NULL, " \r\n")) {
        int r = match_gem(t);
        if (r > best) best = r;
    }
    return best;
}

int should_swap(int a, int b) {
    if (ranks[a] != ranks[b]) return ranks[a] < ranks[b];
    return strcmp(ponies[a],ponies[b])>0;
}

void swap_items(int a, int b) {
    char t[BUFLEN];
    strcpy(t, ponies[a]);
    strcpy(ponies[a], ponies[b]);
    strcpy(ponies[b], t);
    int tr = ranks[a];
    ranks[a] = ranks[b];
    ranks[b] = tr;
}

void sort_step(int n) {
    for (int j = 0; j < n - 1; j++)
        if (should_swap(j, j + 1)) swap_items(j, j + 1);
}

int main() {
    int n = 0;
    while (fgets(ponies[n], BUFLEN, stdin)) {
        ponies[n][strcspn(ponies[n], "\r\n")] = 0;
        if (strcmp(ponies[n], "END") == 0) break;
        ranks[n] = get_rank(ponies[n]);
        n++;
    }
    for (int i = 0; i < n; i++) sort_step(n);
    for (int i = 0; i < n; i++) printf("%s\n", ponies[i]);
    return 0;
}
