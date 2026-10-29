#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void swapNodes(struct node **head_ref, int x, int y) {
    if (x == y) return;
    struct node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
    struct node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
    if (!currX || !currY) return;
    if (prevX) prevX->next = currY;
    else *head_ref = currY;
    if (prevY) prevY->next = currX;
    else *head_ref = currX;
    struct node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void printList(struct node *node) {
    while (node) {
        printf("-->%d", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n, val, x, y;
    struct node *start = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&start, val);
    }
    scanf("%d %d", &x, &y);
    printf("before Swapping:");
    printList(start);
    swapNodes(&start, x, y);
    printf("after Swapping:");
    printList(start);
    return 0;
}

