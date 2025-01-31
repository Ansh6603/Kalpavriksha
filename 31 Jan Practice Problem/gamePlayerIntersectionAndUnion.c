//  In our office, we're playing the games: foosball and table tennis. We have two sets of lists,
// where the first list contains the IDs of employees playing foosball, and the second contains the
// IDs of those playing table tennis. Each employee ID follows the format "ITT/XXX", where "X"
// represents any number from 0 to 9. It's possible that some employees are participating in both
// games.
// Write a C program that asks the user to input two lists of employee IDs stored using linked lists.
// Your program should create and output two new linked lists:
// 1. A linked list containing the IDs of employees who are participating in both foosball and table
// tennis.
// 2. A linked list containing all unique employee IDs from both the foosball and table tennis lists.
// Note: Program should include proper error handling.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node 
{
    char id[100];
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

void numberFromString(char* inputString, char data[][100], int* size) 
{
    int iteratorI = 0;
    int iteratorJ = 0;
    int currentIndex = 0;
    
    while (*(inputString + iteratorI) != '\0')
    {
        if (strncmp(inputString + iteratorI, "->", 2) == 0)
        {
            data[iteratorJ][currentIndex] = '\0';  
            iteratorJ++;
            currentIndex = 0;
            iteratorI += 2;  
        } 
        else 
        {
            data[iteratorJ][currentIndex] = *(inputString + iteratorI);
            currentIndex++;
            iteratorI++;
        }
    }
    data[iteratorJ][currentIndex] = '\0';  
    *size = iteratorJ + 1;
}

struct Node* createNode(char* data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    strcpy(newNode->id, data);  
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

struct Node* createLinkedList(char* inputString)
{
    int size;
    char data[200][100];  
    numberFromString(inputString, data, &size);
    struct Node* result = NULL;
    for (int iteratorI = 0; iteratorI < size; iteratorI++) 
    {
        insertEnd(&result, data[iteratorI]);
    }
    return result;
}

int isCommon(struct Node* head, char* data)
{
    struct Node* temp = head;
    while (temp != NULL) 
    {
        if (strcmp(temp->id, data) == 0) 
        {  
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

struct Node* intersection(struct Node* list1, struct Node* list2) 
{
    struct Node* result = NULL;
    struct Node* temp = list1;
    while (temp != NULL) {
        if (isCommon(list2, temp->id)) 
        {
            insertEnd(&result, temp->id);  
        }
        temp = temp->next;
    }
    return result;
}

struct Node* unionLists(struct Node* list1, struct Node* list2) 
{
    struct Node* result = NULL;
    struct Node* temp = list1;
    while (temp != NULL) 
    {
        insertEnd(&result, temp->id);  
        temp = temp->next;
    }
    temp = list2;
    while (temp != NULL)
    {
        if (!isCommon(result, temp->id))
        {  
            insertEnd(&result, temp->id);
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
        printf("%s ", temp->id);  
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    char inputString1[200];
    printf("Enter id of football \n");
    readInputString(inputString1);
    char inputString2[200];
    printf("Enter id of table tennis \n");
    readInputString(inputString2);
    
    struct Node* football = createLinkedList(inputString1);
    struct Node* tableTennis = createLinkedList(inputString2);
    
    struct Node* bothGames = intersection(football, tableTennis);
    struct Node* uniquePlayers = unionLists(football, tableTennis);

    printf("Employees participating in both foosball and table tennis:\n");
    printList(bothGames);

    printf("All unique employees:\n");
    printList(uniquePlayers);

    return 0;
}
