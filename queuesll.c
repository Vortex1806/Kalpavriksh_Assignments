#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
    q->size = 0;
}

bool isEmptyQueue(Queue* q) {
    return q->size == 0;
}

int sizeQueue(Queue* q){
    return q->size;
}

void enqueue(Queue* q, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return data;
}

int peekQueue(Queue* q) {
    return isEmptyQueue(&q) ? -1 : q->front->data;
}

void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Node *front = NULL; 
// Node *rear = NULL;  
// int cap = 0;

// void enqueue(int x) {
//     Node *temp = (Node*)malloc(sizeof(Node));
//     temp->data = x;
//     temp->next = NULL;
//     if (front == NULL && rear == NULL) {
//         front = rear = temp;
//     } else {
//         rear->next = temp;
//         rear = temp;
//     }
//     cap++;
// }

// void dequeue() {
//     if (front == NULL) {
//         printf("Queue is Empty\n");
//         return;
//     }
//     Node *temp = front;
//     front = front->next;
//     free(temp);
//     cap--;
//     if (front == NULL) {
//         rear = NULL;
//     }
// }

// void size() {
//     printf("Size: %d\n", cap);
// }

// void peek() {
//     if (front == NULL) {
//         printf("Queue is Empty\n");
//     } else {
//         printf("Front Element: %d\n", front->data);
//     }
// }

// void print() {
//     if (front == NULL) {
//         printf("Queue is Empty\n");
//         return;
//     }
//     Node *temp = front;
//     printf("Queue Elements: ");
//     while (temp != NULL) {
//         printf("%d -> ", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

int main(){
    Queue q;
    initQueue(&q);
    printf("Queue implementation using Arrays: \n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. isEmpty\n");
    printf("5. Print All\n");
    
    int ch, n;
    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &n);
                enqueue(&q,n);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                peekQueue(&q);
                break;
            case 4:
                printf("Is empty: %s\n", isEmptyQueue(&q) ? "True" : "False");
                break;
            case 5:
                printQueue(&q);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}