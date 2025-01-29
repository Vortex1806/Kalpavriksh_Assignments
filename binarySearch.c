#include <stdio.h>
#include <stdlib.h>

//Implementing binary search using linked list
// O(N * log(N)) as there is no direct random access to mid we have to traverse to mid every time

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

Node* findMiddle(Node* start, Node* end) {
    if (start == NULL) return NULL;

    Node* slow = start;
    Node* fast = start->next;

    while (fast != end && fast->next != end) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int binarySearch(Node* head, int target) {
    Node* start = head;
    Node* end = NULL;

    do {
        Node* mid = findMiddle(start, end);

        if (mid == NULL) return 0;

        if (mid->val == target) return 1;

        if (mid->val < target) {
            start = mid->next;
        } else {
            end = mid;
        }
    } while (end == NULL || end != start);

    return 0;
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
    create_ll(5);
    create_ll(6);
    create_ll(7);

    printf("Original ");
    display_ll(head);

    int target = 12;
    if (binarySearch(head, target)) {
        printf("%d found\n", target);
    } else {
        printf("%d not found\n", target);
    }

    return 0;
}