#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** result, int data) 
{
    struct Node* newNode = createNode(data);
    if (*result == NULL) 
    {
        *result = newNode;
    }
    else 
    {
        struct Node* temp = *result;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int binaryToDecimal(struct Node* head) 
{
    int result = 0;
    struct Node* current = head;

    while (current != NULL) 
    {
        result = result * 2 + current->data;
        current = current->next;
    }

    return result;
}

void readInputString(char* inputString) 
{
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(inputString + iteratorI) = character;
        iteratorI++;
    }
    *(inputString + iteratorI) = '\0';
}

struct Node* createLinkedList(char* inputString)
{
    int size = 0;
    int data[200];

    int iteratorI = 0, iteratorJ = 0;
    while (*(inputString + iteratorI) != '\0')
    {
        if (*(inputString + iteratorI) == '1' || *(inputString + iteratorI) == '0')
        {
            data[iteratorJ++] = *(inputString + iteratorI) - '0';
        }
        iteratorI++;
    }

    struct Node* result = NULL;
    for (int iteratorI = 0; iteratorI < iteratorJ; iteratorI++) 
    {
        insertEnd(&result, data[iteratorI]);
    }

    return result;
}

void printList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->data);
        if (temp->next != NULL) 
        {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    char inputString[200];

    printf("Enter Binary Linked List\n");
    readInputString(inputString);

    struct Node* head = createLinkedList(inputString);

    int decimalValue = binaryToDecimal(head);

    printf("Decimal Equivalent: %d\n", decimalValue);

    return 0;
}
