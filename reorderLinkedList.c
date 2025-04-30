// Problem Statement:
// Given a singly linked list, reorder it to L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

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
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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

void numberFromString(char* inputString, int* size, int* data)
{
    int iteratorI = 0, currentNumber = 0, sign = 1, iteratorJ = 0;
    while (*(inputString + iteratorI) != '\0')
    {
        if (strncmp(inputString + iteratorI, "->", 2) == 0)
        {
            *(data + iteratorJ) = currentNumber * sign;
            currentNumber = 0;
            iteratorJ++;
            iteratorI++;
            sign = 1;
        }
        else if (*(inputString + iteratorI) == '-')
        {
            sign = -1;
        }
        else if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9')
        {
            currentNumber = currentNumber * 10 + (*(inputString + iteratorI) - '0');
        }
        iteratorI++;
    }
    if (*(inputString + iteratorI - 1) != '-' && *(inputString + iteratorI - 1) != '\0')
    {
        *(data + iteratorJ) = currentNumber * sign;
        iteratorJ++;
    }
    *size = iteratorJ;
}

void insertEnd(struct Node** result, int data)
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

struct Node* createLinkedList(char* inputString)
{
    int size = 0;
    int data[100];
    numberFromString(inputString, &size, data);
    struct Node* result = NULL;
    for (int iteratorI = 0; iteratorI < size; iteratorI++)
    {
        insertEnd(&result, *(data + iteratorI));
    }
    return result;
}
void reOrderLinkedList(struct Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    struct Node* slow=head;
    struct Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct Node* prev=NULL;
    struct Node* curr=slow;
    while(curr!=NULL)
    {
        struct Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    struct Node* first=head;
    struct Node* second=prev;
    while(second->next!=NULL)
    {
        struct Node* temp1 = first->next;
        struct Node* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
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

    printf("Enter Linked List : \n");
    readInputString(inputString1);

    struct Node* head = createLinkedList(inputString1);
    reOrderLinkedList(head);
    printList(head);
    return 0;
}
