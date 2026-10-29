#include <stdio.h>

int top = -1;

int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

void push(int stack[],int data) {
    top++;
    stack[top] = data;
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void print_queue(int q[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

void print_stack(int stack[]) {
    while (top >= 0) {
        printf("%d%s", stack[top], top > 0 ? " " : "");
        top--;
    }
    printf("\n");
}

int main() {
    int n = read_int();
    int queue[n], q_cnt = 0;
    int stack[n];
    for (int i = 0; i < n; i++) {
        int x = read_int();
        if (is_prime(x)) queue[q_cnt++] = x;
        else push(stack, x);
    }
    print_queue(queue, q_cnt);
    print_stack(stack);
    return 0;
}

