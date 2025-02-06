// Problem: Split a circular linked list into two halves. If odd, extra node goes to the first list.

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
    newNode->next = newNode;
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
        while (temp->next != *result)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=*result;
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
void printList(struct Node* head) {
    if (head == NULL)
        return;
    struct Node* temp = head;
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head)
            printf(" -> ");
    } while (temp != head);
    printf("\n");
}
void splitCircularList(struct Node* head) 
{
    if (head == NULL || head->next == head)
    {
        return;
    }
    struct Node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* head1 = head;
    struct Node* head2 = slow->next;
    slow->next = head1;  
    struct Node* temp=head2;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head2;
    printf("List1: ");
    printList(head1);
    printf("List2: ");
    printList(head2);
}
int main()
{
    char inputString1[100];

    printf("Enter Linked List : \n");
    readInputString(inputString1);
    struct Node* head = createLinkedList(inputString1);
    splitCircularList(head);
    return 0;
}
