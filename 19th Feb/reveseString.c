#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct Stack 
{
    char *array;
    int top;
}Stack;
Stack* createStack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->array=(char *)malloc(MAX_SIZE*sizeof(char));
    stack->top=-1;
    return stack;
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
int stringLength(char* inputString)
{
    int iteratorI=0;
    while(*(inputString+iteratorI)!='\0')
    {
        iteratorI++;
    }
    return iteratorI;
}
int isFull(Stack* stack)
{
    return stack->top==MAX_SIZE-1;
}
int isEmpty(Stack* stack)
{
    return stack->top==-1;
}
void push(Stack* stack,char data)
{
    if(isFull(stack))
    {
        printf("Stack Overflow \n");
        return ;
    }
    stack->top++;
    stack->array[stack->top]=data;
}
char pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow \n");
        return '\0';
    }
    char data=stack->array[stack->top];
    stack->top--;
    return data;
}
int main()
{
    Stack* stack=createStack();
    char* inputString=(char*)malloc(200*sizeof(char));
    printf("Enter Input String \n");
    readInputString(inputString);
    int length=stringLength(inputString);
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        push(stack,inputString[iteratorI]);
    }
    int iteratorI=0;
    while(!isEmpty(stack))
    {
        *(inputString+iteratorI)=pop(stack);
        iteratorI++;
    }
    printf("Reversed String: %s\n", inputString);
    free(inputString);
}