#include <stdio.h>

int queue[105];
int front = 0, rear = -1;

void enqueue(int data) {
    queue[++rear] = data;
}

void print_queue() {
    int i;
    for(i=front;i<=rear;i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void dequeue() {
    front++;
    print_queue();
}

int main() {
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }
    printf("Dequeuing elements:\n");
    while (front < rear) {
        dequeue();
    }
    return 0;
}

