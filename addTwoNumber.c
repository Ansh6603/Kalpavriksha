// Problem Statement:
// Two non-negative integers are represented as linked lists, where each node contains a single digit,
// and the digits are stored in reverse order. Write a function to add the two numbers and return the
// sum as a linked list.

#include<stdio.h>
#include<stdlib.h>
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
struct Node* insertNode()
{
    int n;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter the elements of Linked List\n");
    struct Node* head=NULL;
    struct Node* temp=NULL;
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        int data;
        scanf("%d",&data);
        struct Node* newNode=createNode(data);
        if(head==NULL)
        {
            head=newNode;
            temp=head;
        }
        else
        {
            temp->next=newNode;
            temp=temp->next;
        }
    }
    return head;
}
void insertEnd(struct Node** result,int value)
{
    struct Node* newNode=createNode(value);
    struct Node* temp=*result;
    if(*result==NULL)
    {
        *result=newNode;
        temp=*result;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
struct Node* addTwoNumber(struct Node* number1,struct Node* number2)
{
    struct Node* result=NULL;
    int carry=0;
    while(number1!=NULL||number2!=NULL||carry!=0)
    {
        int sum=carry;
        if(number1!=NULL)
        {
            sum+=number1->data;
            number1=number1->next;
        }
        if(number2!=NULL)
        {
            sum+=number2->data;
            number2=number2->next;
        }
        carry=sum/10;
        int value=sum%10;
        insertEnd(&result,value);
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
            printf(" → ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* number1=insertNode();
    struct Node* number2=insertNode();
    struct Node* result=addTwoNumber(number1,number2);
    printf("Sum: ");
    printList(result);
    return 0;
}