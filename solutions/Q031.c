#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    node *next;
};

node *start = NULL;

void display() {
    printf("Linked List:");
    node *p = start;
    while (p) {
        printf("->%d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        node *p1 = (node*)malloc(sizeof(node));
        p1->data = val;
        p1->next=start;
        start = p1;
    }
    display();
    return 0;
}
