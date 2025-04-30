#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory Allocation Failed \n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void readInputString(char* inputString)
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
void convertIntoInteger(char* inputString,int* size,int* array)
{
    int iteratorI=0;
    int iteratorJ=0;
    while(inputString[iteratorI]!='\0')
    {
        int currentNumber=0;
        int sign=1;
        if(strncmp(&inputString[iteratorI],"->",2)==0)
        {
            iteratorI+=2;
        }
        else if(inputString[iteratorI]=='-')
        {
            sign=-1;
            iteratorI++;
        }
        else if(inputString[iteratorI]>='0' && inputString[iteratorI]<='9')
        {
            while(inputString[iteratorI]>='0' && inputString[iteratorI]<='9')
            {
                currentNumber=currentNumber*10+(inputString[iteratorI]-'0');
                iteratorI++;
            }
            array[iteratorJ]=currentNumber*sign;
            iteratorJ++;
        }
    }
    *size=iteratorJ;
}
void connectEnd(struct Node** head,int data)
{
    struct Node* newNode=createNode(data);
    if(*head==NULL)
    {
        *head=newNode;
    }
    else
    {
        struct Node* temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
struct Node* createLinkedList(char* inputString,int *size)
{
    struct Node* res=NULL;
    int* array=(int *)malloc(200*sizeof(int));
    convertIntoInteger(inputString,size,array);
    for(int iteratorI=0;iteratorI<*size;iteratorI++)
    {
        connectEnd(&res,array[iteratorI]);
    }
    return res;
}
void swap(struct Node* a, struct Node* b)
{
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}
void bubbleSort(struct Node* head)
{
    if (head == NULL) return;
    struct Node* ptr1;
    struct Node* ptr2;
    int swapped=0;
    do
    {
        ptr1=head;
        swapped = 0;
        while(ptr1!=NULL && ptr1->next!=NULL)
        {
            ptr2=ptr1->next;
            if(ptr1->data>ptr2->data)
            {
                swap(ptr1,ptr2);
                swapped=1;
            }
            ptr1=ptr1->next;
        }
    }while(swapped);
}
struct Node* reverse(struct Node* head,int k)
{
    struct Node* current=head;
    struct Node* prev=NULL;
    struct Node* next=NULL;
    int count=0;
    while(current!=NULL && count<k)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    return prev;
}
struct Node* sortKthGroup(struct Node* head , int k)
{
    struct Node* dummy=(struct Node *)malloc(sizeof(struct Node));
    dummy->next=head;
    struct Node* groupPrev=dummy;
    struct Node* groupEnd=dummy;
    while(groupEnd!=NULL)
    {
        for(int iteratorI=0;iteratorI<k && groupEnd!=NULL;iteratorI++)
        {
            groupEnd=groupEnd->next;
        }
        if(groupEnd==NULL)
        {
            break;
        }
        struct Node* groupStart=groupPrev->next;
        struct Node* nextGroup=groupEnd->next;
        groupEnd->next=NULL;
        bubbleSort(groupStart);
        groupPrev->next=reverse(groupStart,k);
        groupStart->next=nextGroup;
        groupPrev=groupStart;
        groupEnd=groupPrev;
    }
    return dummy->next;
}
void printList(struct Node* head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        if(temp->next!=NULL)
        {
            printf("->");
        }
        temp=temp->next;
    }
}
int main()
{
    char* inputString=(char *)malloc(200*sizeof(char));
    readInputString(inputString);
    int size;
    struct Node* head=createLinkedList(inputString,&size);
    int k;
    printf("Enter Value of K \n");
    scanf("%d",&k);
    head=sortKthGroup(head,k);
    printList(head);
    return 0;
}