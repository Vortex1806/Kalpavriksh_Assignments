#include <stdio.h>
#include <stdlib.h>

// bubble sorting an array using swapping links and also counting no of swaps and returning them
/*
    Creating the linked list: O(n^2)
    Sorting the linked list: O(n^2)
    Displaying the linked list: O(n)
    Bubble sort O(n^2)
*/

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *head = NULL;

void create_ll(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->val = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}
int bubbleSort() {
    if (head == NULL || head->next == NULL) {
        return 0; 
    }

    int swapCount = 0;
    Node *end = NULL; 
    Node *prev = NULL;

    do {
        Node *ptr = head; 
        prev = NULL; 
        swapCount = 0;

        while (ptr->next != end) {
            if (ptr->val > ptr->next->val) {

                Node *nextNode = ptr->next;
                ptr->next = nextNode->next;
                nextNode->next = ptr;

                if (prev == NULL) {

                    head = nextNode;
                } else {

                    prev->next = nextNode;
                }

                prev = nextNode; 
                swapCount++; 
            } else {
                prev = ptr; 
                ptr = ptr->next; 
            }
        }

        end = ptr; 
    } while (swapCount > 0); 

    return swapCount;
}
void display_ll() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int arr[10] = {4, 1, 7, 8, 6, 8, 1, 3, 8, 3};
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        create_ll(arr[i]);
    }

    printf("Original Linked List: ");
    display_ll();

    int swaps = bubbleSort();
    printf("Sorted Linked List: ");
    display_ll();
    printf("Number of swaps performed: %d\n", swaps);

    return 0;
}