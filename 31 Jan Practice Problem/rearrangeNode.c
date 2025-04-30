// Given a link list of size N, modify the list such that all the even numbers
// appear before all the odd numbers in the modified list. The order of
// appearance of numbers within each segregation should be same as that in
// the original list.
// NOTE: Don't create a new linked list, instead rearrange the provided one.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

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

void numberFromString(char* inputString, int* data, int* size)
{
    int iteratorI = 0;
    int iteratorJ = 0;
    while (*(inputString + iteratorI) != '\0')
    {
        int currentNumber = 0;
        int sign = 1;
        if (strncmp(inputString + iteratorI, "->", 2) == 0)
        {
            iteratorI += 2; 
        }
        else if (*(inputString + iteratorI) == '-')
        {
            sign = -1;
            iteratorI++;
        }
        else if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9')
        {
            while (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9')
            {
                currentNumber = currentNumber * 10 + (*(inputString + iteratorI) - '0');
                iteratorI++;
            }
            *(data + iteratorJ) = currentNumber * sign;
            iteratorJ++;
        }
        else
        {
            iteratorI++;
        }
    }
    *size = iteratorJ;
}

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed \n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* createLinkedList(char* inputString)
{
    int data[200];
    int size;
    numberFromString(inputString, data, &size);
    struct Node* result = NULL;
    for (int iteratorI = 0; iteratorI < size; iteratorI++)
    {
        insertEnd(&result, *(data + iteratorI));
    }
    return result;
}

struct Node* rearrangeNode(struct Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node* evenHead = NULL, *evenTail = NULL;
    struct Node* oddHead = NULL, *oddTail = NULL;
    struct Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = evenTail = temp;
            }
            else
            {
                evenTail->next = temp;
                evenTail = temp;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = oddTail = temp;
            }
            else
            {
                oddTail->next = temp;
                oddTail = temp;
            }
        }
        temp = temp->next;
    }

    if (oddTail != NULL)
    {
        oddTail->next = NULL;
    }

    if (evenTail != NULL)
    {
        evenTail->next = oddHead;
    }

    return evenHead != NULL ? evenHead : oddHead;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    char* inputString = (char*)malloc(200 * sizeof(char));
    printf("Enter Linked List: \n");
    readInputString(inputString);
    struct Node* head = createLinkedList(inputString);
    head = rearrangeNode(head);
    printList(head);
    return 0;
}
