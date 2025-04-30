// Problem: Find the k-th node from the end in a single traversal without calculating list length.

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
int countElement(struct Node* head)
{
    struct Node* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void KthNodeFromEnd(struct Node* head,int position)
{
    struct Node* temp=head;
    int index=0;
    while(index<position && temp!=NULL)
    {
        index++;
        temp=temp->next;
    }
    if(temp!=NULL)
    {
        printf("%d",temp->data);
    }
    else
    {
        printf("Out of Range \n");
    }
}
int main()
{
    char inputString1[100];

    printf("Enter Linked List : \n");
    readInputString(inputString1);
    int k;
    printf("Enter value of k \n");
    scanf("%d",&k);
    struct Node* head = createLinkedList(inputString1);
    int count = countElement(head);
    int valueFromStart=count-k;
    KthNodeFromEnd(head,valueFromStart);
    return 0;
}
