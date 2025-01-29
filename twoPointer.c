/*
Maximum Water Container
You are given an array of integers height where each element represents the height of a 
vertical line at position i. Find two lines that, together with the x-axis, 
form a container that can hold the maximum amount of water. Return the maximum 
amount of water the container can store.

It is taking O(n^2) time complexity as there is calculation and iteration of width which is taking time we can reduce it 
by incorporating the index logic to linked list but then it will be an array itself

*/

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void create_dll(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void display_dll() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int maxArea() {
    if (head == NULL || head->next == NULL) return 0;

    int max_area = 0;
    Node *left = head;
    Node *right = tail;

    while (left != right) {
        int current_height = (left->val < right->val) ? left->val : right->val;
        int width = 0;

        Node *temp = left;
        while (temp != right) {
            temp = temp->next;
            width++;
        }

        int current_area = current_height * width;
        if (current_area > max_area) {
            max_area = current_area;
        }

        if (left->val < right->val) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    return max_area;
}

int main() {
    int height1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n1 = sizeof(height1) / sizeof(height1[0]);

    for (int i = 0; i < n1; i++) {
        create_dll(height1[i]);
    }

    printf("DLL:\n");
    display_dll();

    printf("Max Water Area: %d\n", maxArea());

    return 0;
}
