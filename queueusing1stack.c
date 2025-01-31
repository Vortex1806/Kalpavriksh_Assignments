#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
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

int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node *temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    s->cap--;
    return data;
}


int isEmpty(Stack *s) {
    return s->cap == 0;
}

int peek(Stack *s) {
    if (s->top == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return s->top->data;
}


void printStack(Stack *s) {
    Node* temp = s->top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

typedef struct {
    Stack s1;
} Queue;


void initQueue(Queue *q) {
    initStack(&q->s1);
}


void qpush(Queue *q, int x) {
    
    if (isEmpty(&q->s1)) {
        push(&q->s1, x);
        return;
    }
    int topElement = pop(&q->s1);
    qpush(q, x);
    push(&q->s1, topElement);
}

int qpop(Queue *q) {
    if (isEmpty(&q->s1)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return pop(&q->s1);
}


void qpeek(Queue *q) {
    if (isEmpty(&q->s1)) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", peek(&q->s1));
    }
}


void qprint(Queue *q) {
    printStack(&q->s1);
}

int isEmptyQueue(Queue *q) {
    return isEmpty(&q->s1);
}

int main() {
    Queue q;
    initQueue(&q);
    
    printf("\nQueue implementation using Stacks: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. isEmpty\n");
    printf("5. Print All\n");
    printf("6. Exit\n");
    
    int ch, n;
    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &n);
                qpush(&q, n);
                break;
            case 2:
                printf("Dequeued: %d\n", qpop(&q));
                break;
            case 3:
                qpeek(&q);
                break;
            case 4:
                printf("Is empty: %s\n", isEmptyQueue(&q) ? "True" : "False");
                break;
            case 5:
                qprint(&q);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
