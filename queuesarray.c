#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// int queue[MAX];
// int front = -1;
// int rear = -1;
// int cap = 0;

typedef struct{
    int queue[MAX];
    int front;
    int rear;
    int capacity;
}Queue;

void initQueue(Queue *q){
    q->capacity = 0;
    q->front = -1;
    q->rear = -1;
}


void enqueue(Queue *q, int x){
    if (q->capacity == MAX) {
        printf("Queue is Full\n");
        return;
    }
    if (q->capacity == 0) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX; 
    }
    q->queue[q->rear] = x;
    q->capacity++;
}

void dequeue(Queue *q){
    if (q->capacity == 0) {
        printf("Queue is Empty\n");
        return;
    }
    if (q->capacity == 1) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    q->capacity--;
}

void peek(Queue *q){
   if (q->capacity == 0) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front Element: %d\n", q->queue[q->front]);
}

void size(Queue *q){
    printf("Size: %d\n", q->capacity);

}
int isEmpty(Queue *q){
    return q->capacity == 0;
}

void print(Queue *q) {
    if (q->capacity == 0) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue Elements: ");
    for (int i = 0; i < q->capacity; i++) {
        int index = (q->front + i) % MAX;
        printf("%d ", q->queue[index]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    printf("Queue implementation using Struct:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
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
                enqueue(&q, n);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peek(&q);
                break;
            case 4:
                res = isEmpty(&q);
                printf("\n");
                if (res == 1) {
                    printf("Is empty: True\n");
                } else {
                    printf("Is empty: False\n");
                }
                break;
            case 5:
                print(&q);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
}