#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

typedef struct {
    Node* top;
    int cap;
} Stack;

void initStack(Stack *s) {
    s->top = NULL;
    s->cap = 0;
}

void push(Stack *s, int x) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = s->top;
    s->top = temp;
    s->cap++;
}

void pop(Stack *s) {
    if (s->top == NULL) {
        printf("Invalid\n");
        return;
    }
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->cap--;
}

int isEmpty(Stack *s) {
    return s->cap == 0;
}

void size(Stack *s) {
    printf("\n%d", s->cap);
}

void peek(Stack *s) {
    if (s->top == NULL) printf("NULL\n");
    else printf("\n%d", s->top->data);
}

void print(Stack *s) {
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Stack s;
    initStack(&s);

    printf("Stack implementation using linked list: \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. isEmpty\n");
    printf("5. PrintAll\n");
    printf("6. exit\n");
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
                break;
        }
    }
}