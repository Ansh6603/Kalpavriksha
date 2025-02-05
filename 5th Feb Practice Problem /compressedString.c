#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define MAX_SIZE 100
typedef struct Stack 
{
    char* data;
    int top;
}Stack;
Stack* createStack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    stack->data=(char *)malloc(MAX_SIZE*sizeof(char));
    return stack;
}
int isEmpty(Stack* stack)
{
    return stack->top==-1;
}
int isFull(Stack* stack)
{
    return stack->top==MAX_SIZE-1;
}
void push(Stack* stack ,char data)
{
    if(isFull(stack))
    {
        printf("Stack Overflow\n");
        return ;
    }
    stack->top++;
    stack->data[stack->top]=data;
}
char pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow \n");
        return '\0';
    }
    return stack->data[(stack->top)--];
}
char peek(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow \n");
        return '\0';
    }
    return stack->data[stack->top];
}
int isDigit(char ch)
{
    return ch>='0' && ch<='9';
}
void decodedString(Stack* stack,char* compressedString)
{
    int iteratorI=0;
    while(*(compressedString+iteratorI)!='\0')
    {
        if(*(compressedString+iteratorI)!=']')
        {
            push(stack,*(compressedString+iteratorI));
        }
        else
        {
            char tempArray[200];
            char numArray[200];
            int iteratorJ=0;
            while(!isEmpty(stack) && peek(stack)!='[')
            {
                tempArray[iteratorJ++]=pop(stack);
            }
            pop(stack);
            char reversedArray[200];
            int iteratorM=0;
            for(iteratorM=0;iteratorM<iteratorJ;iteratorM++)
            {
                reversedArray[iteratorM]=tempArray[iteratorJ-iteratorM-1];
            }
            int iteratorK=0;
            while(!isEmpty(stack) && isDigit(peek(stack)))
            {
                numArray[iteratorK++]=pop(stack);
            }
            int repeat=0;
            for(int iteratorL=0;iteratorL<iteratorK;iteratorL++)
            {
                repeat=repeat*10+(numArray[iteratorK-iteratorL-1]-'0');
            }
            for(int iteratorN=0;iteratorN<repeat;iteratorN++)
            {
                for(int iteratorZ=0;iteratorZ<iteratorJ;iteratorZ++)
                {
                    push(stack,reversedArray[iteratorZ]);
                }
            }
        }
        iteratorI++;
    }
    char result[200];
    int index=0;
    while(stack->top!=-1)
    {
        result[index++]=pop(stack);
    }
    result[index]='\0';
    for(int iteratorJ=0;iteratorJ<index/2;iteratorJ++)
    {
        char temp=result[iteratorJ];
        result[iteratorJ]=result[index-iteratorJ-1];
        result[index-iteratorJ-1]=temp;
    }
    printf("Decoded String : %s \n",result);
} 
int main()
{
    printf("Enter the compressed String : \n");
    char *compressedString=(char *)malloc(200*sizeof(char));
    scanf("%s",compressedString);
    Stack* stack=createStack();
    decodedString(stack,compressedString);
    return 0;
}