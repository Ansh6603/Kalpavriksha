#include<stdio.h>
#include<stdlib.h>
typedef struct Stack 
{
    char* array;
    int top;
}Stack;
Stack* createStack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->array=(char *)malloc(200*sizeof(char));
    stack->top=-1;
    return stack;
}
void readInputString(char* paranthesis)
{
    int iteratorI=0;
    char character;
    while((character=getchar())!='\n' && character!=EOF)
    {
        *(paranthesis+iteratorI)=character;
        iteratorI++;
    }
    *(paranthesis+iteratorI)='\0';
}
int stringLength(char* paranthesis)
{
    int iteratorI=0;
    while(*(paranthesis+iteratorI)!='\0')
    {
        iteratorI++;
    }
    return iteratorI;
}
void push(Stack *stack, char data)
{
    stack->top++;
    stack->array[stack->top]=data;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
int pop(Stack *stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    return stack->array[(stack->top)--];
}
int peek(Stack *stack)
{
    if(isEmpty(stack))
    {
        return -1;
    }
    return stack->array[(stack->top)];
}
int main()
{
    char* paranthesis=(char *)malloc(200*sizeof(char));
    readInputString(paranthesis);
    int length=stringLength(paranthesis);
    Stack* stack=createStack();
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        char ch=paranthesis[iteratorI];
        if(ch=='(' || ch=='{' || ch=='[')
        {
            push(stack,ch);
        }
        else if((ch==')' && peek(stack)=='(')|| (ch=='}' && peek(stack)=='{')||( ch==']' && peek(stack)=='['))
        {
            pop(stack);
        }
        else
        {
            printf("False\n");
            return 0; 
        }
    }
    if(isEmpty(stack))
    {
        printf("True");
    }
    else 
    {
        printf("False");
    }
    free(paranthesis);
    free(stack->array);
    free(stack);
    return 0;
}