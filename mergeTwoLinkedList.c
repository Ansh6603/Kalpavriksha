// Problem Statement:
// Given two sorted linked lists, merge them into a single sorted linked list.

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

void readInputString(char *inputString)
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

void numberFromString(char* inputString, int* size, int* data) 
{
    int iteratorI = 0;
    int iteratorJ = 0;
    int currentNumber = 0;
    int isNegative = 0;

    while (*(inputString + iteratorI) != '\0') 
    {
        if (strncmp(inputString + iteratorI, "->", 2) == 0)  
        {
            *(data + iteratorJ) = currentNumber * (isNegative ? -1 : 1);
            iteratorJ++;
            currentNumber = 0;
            isNegative = 0;
            iteratorI++;
        } 
        else if (*(inputString + iteratorI) == '-') 
        {
            isNegative = 1;
        } 
        else if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
        {
            currentNumber = currentNumber * 10 + (*(inputString + iteratorI) - '0');
        }

        iteratorI++;
    }
    if (*(inputString + iteratorI - 1) != '-' && *(inputString + iteratorI - 1) != '\0') 
    {
        *(data + iteratorJ) = currentNumber * (isNegative ? -1 : 1);
        iteratorJ++;
    }

    *size = iteratorJ;
}

void insertAtEnd(struct Node** result, int data) 
{
    struct Node* newNode = createNode(data);
    struct Node* temp = *result;
    if (*result == NULL)
    {
        *result = newNode;
    } 
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* createLinkedList(char *inputString) 
{
    int data[100];
    int size = 0;
    numberFromString(inputString, &size, data);
    struct Node* result = NULL;
    for (int iteratorI = 0; iteratorI < size; iteratorI++) 
    {
        insertAtEnd(&result, data[iteratorI]);
    }
    return result;
}

struct Node* mergeTwoSortedList(struct Node* head1, struct Node* head2) 
{
    struct Node* head = NULL;
    struct Node* tail = NULL;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data < head2->data) 
    {
        head = tail = createNode(head1->data);
        head1 = head1->next;
    } 
    else 
    {
        head = tail = createNode(head2->data);
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL)
    {
        struct Node* newNode;
        if (head1->data < head2->data) 
        {
            newNode = createNode(head1->data);
            head1 = head1->next;
        } 
        else 
        {
            newNode = createNode(head2->data);
            head2 = head2->next;
        }
        tail->next = newNode;
        tail = newNode;
    }

    while (head1 != NULL) 
    {
        struct Node* newNode = createNode(head1->data);
        tail->next = newNode;
        tail = newNode;
        head1 = head1->next;
    }

    while (head2 != NULL) 
    {
        struct Node* newNode = createNode(head2->data);
        tail->next = newNode;
        tail = newNode;
        head2 = head2->next;
    }

    return head;
}

void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d", head->data);
        head = head->next;
        if (head) 
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() 
{
    char inputString1[100];
    char inputString2[100];
    printf("Enter Linked List 1: ");
    readInputString(inputString1);
    printf("Enter Linked List 2: ");
    readInputString(inputString2);
    
    struct Node* head1 = createLinkedList(inputString1);
    struct Node* head2 = createLinkedList(inputString2);
    
    struct Node* head = mergeTwoSortedList(head1, head2);
    
    printf("Merged Sorted Linked List:\n");
    printList(head);
    
    return 0;
}
