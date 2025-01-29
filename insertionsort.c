#include <stdio.h>
#include <stdlib.h>

// Insertion Sort 
// best case O(n) and worst case O(n^2)

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

void insertionSort()
{
    if (head == NULL)
        return;

    Node *sorted = NULL;
    Node *current = head;

    while (current != NULL)
    {
        Node *next = current->next;
        if (sorted == NULL || sorted->val >= current->val)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->val < current->val)
            {
                temp = temp->next;
            }
            
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    head = sorted;  
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

    insertionSort();

    printf("Sorted LL: ");
    display_ll();

    return 0;
}
