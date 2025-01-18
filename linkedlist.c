#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void insertAtBeginning(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failure\n");
        return;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int pos, int value)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        insertAtBeginning(value);
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display()
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void updateAtPosition(int pos, int value)
{
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    temp->data = value;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    if (pos < 1)
    {
        printf("Invalid pos\n");
        return;
    }
    if (pos == 1)
    {
        deleteAtBeginning();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int h = 0; h < n; h++)
    {
        int ch;
        scanf("%d", &ch);
        if (ch == 1)
        {
            int value;
            scanf("%d", &value);
            insertAtEnd(value);
        }
        else if (ch == 2)
        {
            int value;
            scanf("%d", &value);
            insertAtBeginning(value);
        }
        else if (ch == 3)
        {
            int pos;
            int value;
            scanf("%d %d", &pos, &value);
            insertAtPosition(pos, value);
        }
        else if (ch == 4)
        {
            display();
        }
        else if (ch == 5)
        {
            int pos, value;
            scanf("%d %d", &pos, &value);
            updateAtPosition(pos, value);
        }
        else if (ch == 6)
        {
            deleteAtBeginning();
        }
        else if (ch == 7)
        {
            deleteAtEnd();
        }
        else if (ch == 8)
        {
            int pos;
            scanf("%d", &pos);
            deleteAtPosition(pos);
        }
        else
        {
            printf("Invalid choice");
        }
    }
}
