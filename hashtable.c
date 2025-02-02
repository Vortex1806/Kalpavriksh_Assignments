#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Node
{
    int key;
    int val;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
} HashTable;

Node *createNode(int key, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}
int hash(int key)
{
    return key % SIZE;
}

void insert(HashTable *table, int key, int value)
{
    int index = hash(key);
    Node *newNode = createNode(key, value);
    if (table[index].head == NULL)
    {
        table[index].head = newNode;
    }
    else
    {
        Node *current = table[index].head;
        while (current->next != NULL)
        {
            if (current->key == key)
            {
                current->val = value;
                free(newNode);
                return;
            }
            current = current->next;
        }
        if (current->key == key)
        {
            current->val = value;
            free(newNode);
        }
        else
        {
            current->next = newNode;
        }
    }
}

int search(HashTable *table, int key)
{
    Node *temp = table[hash(key)].head;
    while (temp)
    {
        if (key == temp->key)
        {
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}

void delete(HashTable *table, int key)
{
    int index = hash(key);
    Node *current = table[index].head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL)
            {
                table[index].head = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            printf("Key %d deleted.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("key %d not found\n", key);
}

void display(HashTable *table)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d : ", i);
        Node *current = table[i].head;
        while (current != NULL)
        {
            printf("(%d,%d)->", current->key, current->val);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    HashTable table[SIZE] = {0};
    int choice, key, value;

    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            insert(table, key, value);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &key);
            value = search(table, key);
            if (value != -1)
            {
                printf("Value: %d\n", value);
            }
            else
            {
                printf("Key not found.\n");
            }
            break;
        case 3:
            printf("Enter key: ");
            scanf("%d", &key);
            delete (table, key);
            break;
        case 4:
            display(table);
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}