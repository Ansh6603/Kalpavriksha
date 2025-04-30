#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
#define MAX_URL_LENGTH 100
typedef struct Stack 
{
    char array[MAX_SIZE][MAX_URL_LENGTH];
    int top;
}Stack;
Stack* createStack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    return stack;
}
int isFull(Stack* stack)
{
    return stack->top==MAX_SIZE-1;
}
int isEmpty(Stack* stack)
{
    return stack->top==-1;
}
int stringLength(char *dest)
{
    int iteratorI=0;
    while(*(dest+iteratorI)!='\0')
    {
        iteratorI++;
    }
    return iteratorI;
}
void stringCopy(char* dest,char* src)
{
    int iteratorI=0;
    int length=0;
    while(src[iteratorI]!='\0')
    {
        dest[length++]=src[iteratorI++];
    }
    dest[length]='\0';
}
void push(Stack* stack ,char* url)
{
    if(isFull(stack))
    {
        printf("Stack Overflow \n");
        return;
    }
    stack->top++;
    stringCopy(stack->array[stack->top],url);
}
void pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack UnderFlow \n");
        return ;
    }
    stack->top--;
}
void read(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("No websites in history.\n");
        return ;
    }
    printf("Browser History:\n");
    for(int iteratorI=stack->top;iteratorI>=0;iteratorI--)
    {
        printf("%d. %s \n",stack->top-iteratorI+1,stack->array[iteratorI]);
    }
}
void peek(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("No websites in history.\n");
        return ;
    }
    printf("Most recent Website : %s \n",stack->array[stack->top]);
}
void clearHistory(Stack* stack)
{
    stack->top=-1;
    printf("History cleared.\n");
}
void editURL(Stack* stack,int index,char* newURL)
{
    if(index<1 || index>stack->top+1)
    {
        printf("Invalid Index \n");
        return;
    }
    stringCopy(stack->array[stack->top-index+1],newURL);
}
void readUrl(char* inputString)
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
int main()
{
    Stack* stack=createStack();
    int choice;
    int index;
    char url[MAX_URL_LENGTH];
    while(1)
    {
        printf("Enter the choice \n");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            printf("Enter the URL \n");
            readUrl(url);
            push(stack,url);
            break;
            case 2:
            read(stack);
            break;
            case 3:
            printf("Enter new URL \n");
            readUrl(url);
            printf("Enter index \n");
            scanf("%d",&index);
            getchar();
            editURL(stack,index,url);
            break;
             case 4:
                pop(stack);
                break;
            case 5:
                clearHistory(stack);
                break;
            case 6:
                peek(stack);
                break;
            case 7:
                printf("Exit\n");
                free(stack);  
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
}