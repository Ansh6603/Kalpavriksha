#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct Node 
{
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE] = {NULL};

unsigned int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void insert(int key, int value) 
{
    unsigned int index = hashFunction(key);
    Node* current = hashTable[index];
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            current->value = value;
            return;
        }
        current = current->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(int key) 
{
    unsigned int index = hashFunction(key);
    Node* current = hashTable[index];
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void delete(int key) 
{
    unsigned int index = hashFunction(key);
    Node* current = hashTable[index];
    Node* prev = NULL;
    while (current != NULL) 
    {
        if (current->key == key)
        {
            if (prev == NULL)
            {
                hashTable[index] = current->next;
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
    printf("Key %d not found.\n", key);
}

void display() 
{
    printf("Hash Table:\n");
    for (int iteratorI = 0; iteratorI < TABLE_SIZE; iteratorI++) 
    {
        printf("Index %d: ", iteratorI);
        Node* current = hashTable[iteratorI];
        while (current != NULL)
        {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() 
{
    int choice, key, value;
    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                value = search(key);
                if (value != -1)
                    printf("Value: %d\n", value);
                else
                    printf("Key not found.\n");
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}
