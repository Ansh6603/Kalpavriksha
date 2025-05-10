#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

typedef struct Node 
{
    int key;
    int count;
    struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE] = {NULL};

int hashFunction(int key) 
{
    return abs(key) % TABLE_SIZE;
}

void insert(int key)
 {
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    while (temp!=NULL) {
        if (temp->key == key)
        {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void findDuplicates(int arr[], int n) 
{
    for (int iteratorI = 0; iteratorI < n; iteratorI++) 
    {
        insert(arr[iteratorI]);
    }
    for (int iteratorI = 0; iteratorI < TABLE_SIZE; iteratorI++) 
    {
        Node *temp = hashTable[iteratorI];
        while (temp!=NULL) 
        {
            if (temp->count > 1) 
            {
                printf("Duplicate: %d (Count: %d)\n", temp->key, temp->count);
            }
            temp = temp->next;
        }
    }
}

int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int iteratorI = 0; iteratorI < n; iteratorI++) 
    {
        scanf("%d", &arr[iteratorI]);
    }
    findDuplicates(arr, n);
    free(arr);
    return 0;
}