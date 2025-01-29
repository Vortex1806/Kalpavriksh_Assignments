#include <stdio.h>
#include <stdlib.h>

// Selection Sort 
// O(n²) for all the cases time complexity is the same as current is getting traversed and for each all are getting traversed

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

void display_ll()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swap(Node *node1, Node *node2) {
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
}


void selectionSort()
{
    if (head == NULL)
        return;

    Node *current = head;
    while (current != NULL)
    {
        Node *minNode = current;
        Node *nextNode = current->next;

        
        while (nextNode != NULL)
        {
            if (nextNode->val < minNode->val)
            {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        
        if (minNode != current)
        {
            swap(current, minNode);
        }
        current = current->next;
    }
}

int main()
{
    int arr[10] = {4, 1, 7, 8, 6, 8, 1, 3, 8, 3};
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        create_ll(arr[i]);
    }

    printf("Original LL: ");
    display_ll();

    selectionSort();

    printf("Sorted LL: ");
    display_ll();

    return 0;
}


