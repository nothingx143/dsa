#include <stdio.h>

int queue[105];
int front = 0, rear = -1;

void enqueue(int data) {
    queue[++rear] = data;
    int i;
    for(i=front;i<=rear;i++) {
        printf("%d%s", queue[i], (i == rear) ? "" : " ");
    }
}

int main() {
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        printf("Enqueuing %d\n", data);
        enqueue(data);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}

