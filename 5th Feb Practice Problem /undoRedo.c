#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
typedef struct Stack
{
    int top;
    char* array;
}Stack;
Stack* createStack()
{
    Stack* stack=(Stack *)malloc(sizeof(Stack));
    stack->top=-1;
    stack->array=(char *)malloc(MAX_SIZE*sizeof(char));
    return stack;
}
int isFull(Stack* s)
{
    return s->top==MAX_SIZE-1;
}
void push(Stack* s,char ch)
{
    if(isFull(s))
    {
        printf("Stack Overflow \n");
        return;
    }
    s->top++;
    s->array[s->top]=ch;
}
void type(Stack* s,char ch)
{
    push(s,ch);
}
int isEmpty(Stack* s)
{
    return s->top==-1;
}
char pop(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow \n");
        return '\0';
    }
    return s->array[(s->top)--];
}
void undo(Stack* s1,Stack* s2)
{
    if(isEmpty(s1))
    {
        printf("Undo can't be performed \n");
        return;
    }
    char lastChar=pop(s1);
    push(s2,lastChar);
    printf("Undo : %c \n",lastChar);
}
void redo(Stack* s1,Stack* s2)
{
    if(isEmpty(s2))
    {
        printf("Redo Can't be performed \n");
        return;
    }
    char lastChar=pop(s2);
    push(s1,lastChar);
    printf("Redo :%c \n",lastChar);
}
void display(Stack* s)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty \n");
        return;
    }
    for(int iteratorI=0;iteratorI<=s->top;iteratorI++)
    {
        printf("%c",s->array[iteratorI]);
    }
    printf("\n");
}
int main()
{
    Stack* s1=createStack();
    Stack* s2=createStack();
    int choice;
    char ch;
    while(1)
    {
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("Enter the character \n");
            scanf(" %c",&ch);
            type(s1,ch);
            break;
            case 2:
            undo(s1,s2);
            break;
            case 3:
            redo(s1,s2);
            break;
            case 4:
            display(s1);
            break;
            default :
            printf("Invalid Choice \n");
        }
    }
}