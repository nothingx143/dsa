#include <stdio.h>

int arr[10];
int top1 = -1;
int top2 = 10;

void push1(int x) {
    arr[++top1] = x;
}

void push2(int x) {
    arr[--top2] = x;
}

int pop1() {
    return arr[top1--];
}

int pop2() {
    return arr[top2++];
}

int main() {
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    push1(a);
    push2(b);
    push1(c);
    push2(d);
    push1(e);
    printf("Popped element from stack1 is:%d\n", pop1());
    printf("Popped element from stack2 is:%d\n", pop2());
    return 0;
}

