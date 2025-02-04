#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack 
{
    int top;
    int *array;
} Stack;

Stack* createStack() 
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (int *)malloc(MAX_SIZE * sizeof(int));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack* stack) 
{
    return stack->top == -1;
}

void push(Stack* stack, int data) 
{
    stack->array[++stack->top] = data;
}

int pop(Stack* stack) 
{
    if (isEmpty(stack))
    {
        return -1;
    }
    return stack->array[stack->top--];
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
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        inputString[iteratorI++] = character;
    }
    inputString[iteratorI] = '\0';
}

void convertStringIntoArray(char* inputString, int* array, int* size) 
{
    int iteratorI = 0, iteratorJ = 0;
    while (inputString[iteratorI] != '\0') 
    {
        int currentNumber = 0;
        if (inputString[iteratorI] >= '0' && inputString[iteratorI] <= '9') 
        {
            while (inputString[iteratorI] >= '0' && inputString[iteratorI] <= '9') 
            {
                currentNumber = currentNumber * 10 + (inputString[iteratorI] - '0');
                iteratorI++;
            }
            array[iteratorJ++] = currentNumber;
        } 
        else 
        {
            iteratorI++;
        }
    }
    *size = iteratorJ;
}

int main() 
{
    Stack* stack = createStack();
    char* inputString = (char *)malloc(200 * sizeof(char));

    printf("Enter stock prices:\n");
    readInputString(inputString);

    int *prices = (int *)malloc(200 * sizeof(int));
    int size;
    convertStringIntoArray(inputString, prices, &size);

    int *span = (int *)malloc(size * sizeof(int));

    for (int iteratorI = 0; iteratorI < size; iteratorI++) 
    {
        while (!isEmpty(stack) && prices[peek(stack)] <= prices[iteratorI]) 
        {
            pop(stack);
        }
        span[iteratorI] = (isEmpty(stack)) ? (iteratorI + 1) : (iteratorI - peek(stack));
        push(stack, iteratorI);  
    }

    printf("Stock Span: ");
    for (int iteratorI = 0; iteratorI < size; iteratorI++) 
    {
        printf("%d ", span[iteratorI]);
    }
    printf("\n");

    free(stack->array);
    free(stack);
    free(inputString);
    free(prices);
    free(span);

    return 0;
}
