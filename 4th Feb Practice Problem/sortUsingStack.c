#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200
typedef struct Stack 
{
    int* array;
    int top;
}Stack;
Stack* createStack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->array=(int *)malloc(MAX_SIZE*sizeof(int));
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
void push(Stack* stack,int data)
{
    if(isFull(stack))
    {
        printf("Stack Overflow \n");
        return;
    }
    stack->top++;
    stack->array[stack->top]=data;
}
int pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow \n");
        return -1;
    }
    return stack->array[(stack->top)--];
}
int peek(Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        return -1;
    }
    return stack->array[stack->top];
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
void convertStringIntoArray(char* inputString,int* array,int* size)
{
    int iteratorI=0;
    int iteratorJ=0;
    while(*(inputString+iteratorI)!='\0')
    {
        int currentNumber=0;
        if(*(inputString+iteratorI)>='0' && *(inputString+iteratorI)<='9')
        {
            while(*(inputString+iteratorI)>='0' && *(inputString+iteratorI)<='9')
            {
                currentNumber=currentNumber*10+(*(inputString+iteratorI)-'0');
                iteratorI++;
            }
            *(array+iteratorJ)=currentNumber;
            iteratorJ++;
        }
        else
        {
            iteratorI++;
        }
    }
    *size=iteratorJ;
}
void sortArray(Stack* stack,Stack* tempStack,int size)
{
    while(!isEmpty(stack))
    {
        int temp=pop(stack);
        while(!isEmpty(tempStack) && peek(tempStack)>temp)
        {
            push(stack,pop(tempStack));
        }
        push(tempStack,temp);
    }
    while(!isEmpty(tempStack))
    {
        push(stack,pop(tempStack));
    }
    free(tempStack);
}
void printStack(Stack* stack) 
{
    printf("Sorted Stack: ");
    while (!isEmpty(stack)) 
    {
        printf("%d ", pop(stack));
    }
    printf("\n");
}
int main()
{
    Stack* stack=createStack();
    Stack* tempStack=createStack();
    char* inputString=(char *)malloc(200*sizeof(char));
    printf("Enter Input String \n");
    readInputString(inputString);
    int *array=(int *)malloc(200*sizeof(int));
    int size;
    convertStringIntoArray(inputString,array,&size);
    for(int iteratorI=0;iteratorI<size;iteratorI++)
    {
        push(stack,array[iteratorI]);
    }
    sortArray(stack,tempStack,size);
    printStack(stack);

    free(inputString);
    free(array);
    free(stack->array);
    free(stack);
    free(tempStack->array);
    free(tempStack);
}