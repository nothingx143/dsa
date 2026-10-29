#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next; 
};

void sortedInsert(struct Node** head_ref, struct Node* new_node) {
    struct Node* current = *head_ref;
    if (current == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else if (current->data >= new_node->data) {
        while (current->next != *head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        while (current->next != *head_ref && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(struct Node *start) {
    struct Node *temp;
    if (start != NULL) {
        temp = start;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != start);
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node *start = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = val;
        sortedInsert(&start, temp);
    }
    printList(start);
    return 0;
}

