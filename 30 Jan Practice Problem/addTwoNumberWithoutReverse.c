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

int getLength(struct Node* head)
{
    int length = 0;
    while (head != NULL) 
    {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* padList(struct Node* head, int padding) 
{
    for (int iteratorI = 0; iteratorI < padding; iteratorI++) 
    {
        struct Node* newNode = createNode(0);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct Node* addHelper(struct Node* head1, struct Node* head2, int* carry) 
{
    if (head1 == NULL && head2 == NULL) 
    {
        return NULL;
    }

    struct Node* nextNode = addHelper(head1->next, head2->next, carry);

    int sum = head1->data + head2->data + *carry;
    *carry = sum / 10;

    struct Node* resultNode = createNode(sum % 10);
    resultNode->next = nextNode;

    return resultNode;
}

struct Node* addTwoNumber(struct Node* head1, struct Node* head2) 
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    if (len1 < len2) 
    {
        head1 = padList(head1, len2 - len1);
    } 
    else if (len2 < len1) 
    {
        head2 = padList(head2, len1 - len2);
    }

    int carry = 0;
    struct Node* result = addHelper(head1, head2, &carry);

    if (carry) 
    {
        struct Node* newNode = createNode(carry);
        newNode->next = result;
        result = newNode;
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

struct Node* createLinkedList(char* inputString)
{
    int size = 0;
    int data[200];
    numberFromString(inputString, &size, data);

    struct Node* result = NULL;
    for (int iteratorI = 0; iteratorI < size; iteratorI++) 
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
    char inputString1[200];
    char inputString2[200];

    printf("Enter Linked List 1\n");
    readInputString(inputString1);

    printf("Enter Linked List 2\n");
    readInputString(inputString2);

    struct Node* head1 = createLinkedList(inputString1);
    struct Node* head2 = createLinkedList(inputString2);

    struct Node* head = addTwoNumber(head1, head2);

    printList(head);

    return 0;
}
