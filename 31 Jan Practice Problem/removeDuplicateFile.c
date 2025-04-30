// Imagine you're working with a large archive of files, but some files might have duplicate names.
// To improve efficiency, you want to create a system to identify and remove these duplicates.
// Here's the challenge: Design a system that takes a stream of filenames (think of it as a linked list
// where each node holds a filename) as input. In a single pass through the stream (single traversal),
// achieve these goals:
// 1. Identify and remove duplicate filenames: Eliminate duplicate filenames from the original
// linked list (no duplicates).
// 2. Maintain Efficiency: Ensure the time complexity is O(n), where n is the number of nodes in
// the input list.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data[100];
    struct Node* next;
};

void readInputString(char *inputString)
{
    int iteratorI=0;
    char character;
    while((character=getchar())!='\n' && character!=EOF)
    {
        *(inputString+iteratorI)=character;
        iteratorI++;
    }
    *(inputString+iteratorI)='\0';
}

void convertIntoString(char* inputString, char data[][100], int* size)
{
    int iteratorI=0;
    int iteratorJ=0;
    int currentIndex=0;
    while(*(inputString+iteratorI)!='\0')
    {
        if(strncmp(inputString+iteratorI,"->",2)==0)
        {
            data[iteratorJ][currentIndex]='\0';
            iteratorJ++;
            iteratorI+=2;
            currentIndex=0;
        }
        else
        {
            data[iteratorJ][currentIndex]=*(inputString+iteratorI);
            iteratorI++;
            currentIndex++;
        }
    }
    data[iteratorJ][currentIndex]='\0';
    *size=iteratorJ+1;
}

struct Node* createNode(char* data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** result, char* data)
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

struct Node* createLinkedList(char *inputString)
{
    int size;
    char data[200][100];
    convertIntoString(inputString, data, &size);
    struct Node* result = NULL;
    for(int iteratorI = 0; iteratorI < size; iteratorI++)
    {
        insertEnd(&result, data[iteratorI]);
    }
    return result;
}

int isCommon(struct Node* head, char* data)
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->data, data) == 0)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

struct Node* uniqueFile(struct Node* list1)
{
    struct Node* temp = list1;
    struct Node* result = NULL;
    while(temp != NULL)
    {
        if(!isCommon(result, temp->data)) 
        {
            insertEnd(&result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

void printList(struct Node* list)
{
    struct Node* temp = list;
    while (temp != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    char *inputString = (char *)malloc(200 * sizeof(char));
    printf("Enter Linked List \n");
    readInputString(inputString);
    struct Node* head = createLinkedList(inputString);
    struct Node* unique = uniqueFile(head);
    printf("Unique File \n");
    printList(unique);
    return 0;
}
