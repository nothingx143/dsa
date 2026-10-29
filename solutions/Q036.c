#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    node *next;
};

node *head = NULL, *tail = NULL;

void create() {
    int val;
    scanf("%d", &val);
    node *nn = (node*)malloc(sizeof(node));
    nn->data = val;
    nn->next = NULL;
    if (!head) head = nn;
    else tail->next = nn;
    tail = nn;
}

void display() {
    printf("Linked List:");
    node *p = head;
    while (p) {
        printf("->%d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, d, i;
    scanf("%d", &n);
    for(i=0;i<n;i++) create();
    scanf("%d", &d);
    while (d-- && head) {
        head = head->next;
    }
    display();
    return 0;
}

