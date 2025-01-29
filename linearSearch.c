#include <stdio.h>
#include <stdlib.h>

//linear search In a linked list searching and putting the element to the front of the linked list
// O(N) for searching and operations are just link shifting so considering as O(1)

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *head = NULL;


void create_ll(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = data;
    new_node->next = NULL;

    if (head == NULL) {

        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}


int searchAndMove(Node **head, int target) {
    if (*head == NULL) {
        return 0;
    }

    Node *prev = NULL;
    Node *curr = *head;


    while (curr != NULL && curr->val != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {

        return 0;
    }

    if (prev != NULL) {

        prev->next = curr->next;
        curr->next = *head;
        *head = curr;
    }


    return 1;
}


void display_ll(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    create_ll(1);
    create_ll(2);
    create_ll(3);
    create_ll(4);

    printf("Original ");
    display_ll(head);

    int target = 3;
    if (searchAndMove(&head, target)) {
        printf("%d found\n", target);
    } else {
        printf("%d not found\n", target);
    }

    printf("Modification: ");
    display_ll(head);

    return 0;
}