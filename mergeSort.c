#include <stdio.h>
#include <stdlib.h>

//Implementing merge sort using linked list 
//Time complexity O(nlogn) logn for recursive division and n for the merge function 

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

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}


Node *split(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *second_half = slow->next;
    slow->next = NULL;

    return second_half;
}


Node *merge(Node *first, Node *second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    if (first->val < second->val)
    {
        first->next = merge(first->next, second);
        return first;
    }
    else
    {
        second->next = merge(first, second->next);
        return second;
    }
}


Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

int main()
{
    int arr[10] = {4, 1, 7, 8, 6, 8, 1, 3, 8, 3};
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        create_ll(arr[i]);
    }
    printf("Before sorting: ");
    printList();

    head = mergeSort(head);

    printf("After Sorting: ");
    printList();

    return 0;
}
