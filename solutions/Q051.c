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

void dequeue() {
    struct node* t;
    t = f;
    if (f == NULL) return;
    if (f == r) {
        f = r = NULL;
    } else {
        f = f->next;
        r->next = f;
    }
    free(t);
}

void display() {
    struct node* t;
    t = f;
    if (f == NULL) return;
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != f);
    printf("\n");
}

int main() {
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}

