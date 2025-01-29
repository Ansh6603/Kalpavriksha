// Problem Statement:
// Represent two integers as singly linked lists, where each node contains a single digit, and the digits
// are stored in reverse order. Write a function to multiply the two numbers and return the product as a
// linked list.

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
    printf("Enter number of elements \n");
    scanf("%d",&n);
    printf("Enter the elements of Linked List \n");
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
struct Node* reverse(struct Node* head)
{
    struct Node* curr=head;
    struct Node* prev=NULL;
    while(curr!=NULL)
    {
        struct Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
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
struct Node* multiplyNumber(struct Node* number1,struct Node* number2)
{
    struct Node* result=NULL;
    int carry, shift=0;
    for(struct Node* term1=number1;term1!=NULL;term1=term1->next)
    {
        struct Node* tempResult=NULL;
        carry=0;
        for(int i=0;i<shift;i++)
        {
            insertEnd(&tempResult,0);
        }
        for(struct Node* term2=number2;term2!=NULL;term2=term2->next)
        {
            int product=term1->data*term2->data+carry;
            insertEnd(&tempResult,product%10);
            carry=product/10;
        }
        if(carry>0)
        {
            insertEnd(&tempResult,carry);
        }
        struct Node* sumResult=NULL;
        struct Node* temp1=tempResult;
        struct Node* temp2=result;
        carry=0;
        while(temp1!=NULL||temp2!=NULL||carry!=0)
        {
            int sum=carry;
            if(temp1!=NULL)
            {
                sum+=temp1->data;
                temp1=temp1->next;
            }
            if(temp2!=NULL)
            {
                sum+=temp2->data;
                temp2=temp2->next;
            }
            insertEnd(&sumResult,sum%10);
            carry=sum/10;
        }
        result=sumResult;
        shift++;
    }
    return result;
}
void displayNumber(struct Node* result)
{
    struct Node* temp=result;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
int main()
{
    struct Node* number1=insertNode();
    struct Node* number2=insertNode();
    struct Node* result=multiplyNumber(number1,number2);
    struct Node* finalRes=reverse(result);
    displayNumber(finalRes);
    return 0;
}