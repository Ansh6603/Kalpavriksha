#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Queue
{
    char name[200];
    int screenNo;
    int seatNo;
    int price;
    char status[10];
    struct Queue* next;
}Queue;
Queue* bookedFront;
Queue* bookedEnd;
Queue* approvedFront;
Queue* approvedEnd;
void stringCopy(char* dest,char* src)
{
    int iteratorI=0;
    while(src[iteratorI]!='\0')
    {
        dest[iteratorI++]=src[iteratorI++];
    }
    dest[iteratorI]='\0';
}
void bookedTicket()
{
    Queue* queue=(Queue *)malloc(sizeof(Queue));
    getchar();
    printf("Enter Movie Name \n");
    char character;
    int iteratorI=0;
    while((character=getchar())!='\n' && character!=EOF)
    {
        queue->name[iteratorI]=character;
        iteratorI++;
    }
    queue->name[iteratorI]='\0';
    printf("Enter Screen Number \n");
    scanf("%d",&queue->screenNo);
    printf("Enter Seat Number \n");
    scanf("%d",&queue->seatNo);
    printf("Enter amount \n");
    scanf("%d",&queue->price);
    stringCopy(queue->status,"Pending");
    queue->next=NULL;
    if(bookedFront==NULL)
    {
        bookedFront=bookedEnd=queue;
    }
    else
    {
        bookedEnd->next=queue;
        bookedEnd=queue;
    }
}
void approvedTicket()
{
    if (bookedFront == NULL) 
    {
        printf("No tickets to approve\n");
        return;
    }
    Queue* temp=bookedFront;
    bookedFront=bookedFront->next;
    temp->next=NULL;
    stringCopy(temp->status,"Approved");
    if(approvedFront==NULL)
    {
        approvedFront=approvedEnd=temp;
    }
    else
    {
        approvedEnd->next=temp;
        approvedEnd=temp;
    }
    if(bookedFront==NULL)
    {
        bookedEnd=NULL;
    }
}
void printTicket(Queue* forward,Queue* backward)
{
    if(forward==NULL)
    {
        printf("No tickets\n");
        return;
    }
    while(forward!=NULL)
    {
        printf("Movie Name : %s \n",forward->name);
        printf("Movie Screen Number : %d \n",forward->screenNo);
         printf("Seat Number: %d\n", forward->seatNo);
        printf("Amount: %d\n", forward->price);
        printf("Status: %s\n", forward->status);
        if(forward==backward)
        {
            break;
        }
        forward=forward->next;
    }
}
int main()
{
    printf("Ticket Booking System \n");
    int choice;
    while(1)
    {
        printf("1. Book Ticket\n2. Approve Ticket\n3. Print Booked\n4. Print Approved\n5. Exit\n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            bookedTicket();
            break;
            case 2:
            approvedTicket();
            break;
            case 3:
            printTicket(bookedFront,bookedEnd);
            break;
            case 4:
            printTicket(approvedFront,approvedEnd);
            break;
            case 5:
            exit(0);
            default:
            printf("Invalid Choice \n");
        }
    }
}