// Write a C program to simulate an office game using a circular linked list where employees
// are standing in a circle. Initially, the program will collect the IDs of employees playing the game
// from the user. Each employee ID follows the format "ITT/XXX", where "X" represents any
// number from 0 to 9. The game eliminates every kth employee, and the counting resumes from
// the next employee until only one employee remains in the game. Your program should return a
// singly linked list containing the names of eliminated employees, with the last node representing
// the ID of the winning employee.
// Note: Program should include proper error handling.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char id[100];
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
void numberFromString(char *inputString,int* size,char data[][100])
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
            currentIndex++;
            iteratorI++;
        }
    }
    data[iteratorJ][currentIndex]='\0';
    *size=iteratorJ+1;
}
struct Node* createNode(char* data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    strcpy(newNode->id, data);  
    newNode->next = newNode;
    return newNode;
}
void insertEnd(struct Node** result,char* data)
{
    struct Node* newNode = createNode(data);
    if (*result == NULL) 
    {
        *result = newNode;
    } 
    else 
    {
        struct Node* temp = *result;
        while (temp->next != *result) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next=*result;
    }
}
struct Node* createLinkedList(char *inputString)
{
    int size;
    char data[200][100];
    numberFromString(inputString,&size,data);
    struct Node* result=NULL;
    for(int iteratorI=0;iteratorI<size;iteratorI++)
    {
        insertEnd(&result,data[iteratorI]);
    }
    return result;
}
void removeKNode(struct Node** head,int position)
{
    if (*head == NULL || position <= 0) 
    {
        return;
    }
    struct Node* temp=*head;
    struct Node* prev=NULL;
    while(temp->next!=temp)
    {
        for(int iteratorI=1;iteratorI<position;iteratorI++)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("%s ",temp->id);
        prev->next=temp->next;
        free(temp);
        temp=prev->next;
    }
    printf("%s ",temp->id);
    free(temp);
}
int main()
{
    char *inputString=(char *)malloc(200*sizeof(struct Node));
    printf("Enter Linked List \n");
    readInputString(inputString);
    int k;
    printf("Enter value of k \n");
    scanf("%d",&k);
    struct Node* head=createLinkedList(inputString);
    removeKNode(&head,k);
    return 0;
}