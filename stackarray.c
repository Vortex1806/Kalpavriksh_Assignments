#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int stack[MAX];
    int top;
    int capacity;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->capacity = 0;
}

void push(Stack *s, int x) {
    if (s->capacity == MAX) {
        printf("Stack Overflow\n");
        return;
    }
    s->stack[++s->top] = x;
    s->capacity++;
}

void pop(Stack *s) {
    if (s->top == -1) {
        printf("Invalid\n");
        return;
    }
    s->top--;
    s->capacity--;
}

void size(Stack *s) {
    printf("\n%d", s->capacity);
}

int isEmpty(Stack *s) {
    return s->capacity == 0;
}

void peek(Stack *s) {
    if (s->top == -1) {
        printf("Empty\n");
    } else {
        printf("\n%d", s->stack[s->top]);
    }
}

void print(Stack *s) {
    printf("\n");
    if (s->capacity == 0) {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        if (i > 0) printf(" | ");
        printf("%d", s->stack[i]);
    }
}

int main() {
    Stack s;
    initStack(&s);

    printf("Stack implementation using struct: \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. isEmpty\n");
    printf("5. PrintAll\n");
    printf("6. Exit\n");

    int ch = 0;
    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        int n, res;
        switch (ch) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &n);
                push(&s, n);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                peek(&s);
                break;
            case 4:
                res = isEmpty(&s);
                printf("\n");
                printf("Is empty: %s\n", res ? "True" : "False");
                break;
            case 5:
                print(&s);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}
