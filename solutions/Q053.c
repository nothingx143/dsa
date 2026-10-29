#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if (f == NULL) {
        f = r = n;
        r->next = f;
    } else {
        r->next = n;
        r = n;
        n->next = f;
    }
}

void display() {
    struct node* t;
    t = f;
    if (f == NULL) return;
    do {
        printf("%d\n", t->data);
        t = t->next;
    } while (t != f);
}

int main() {
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    display();
    return 0;
}

