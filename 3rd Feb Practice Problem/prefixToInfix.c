#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack 
{
    char* array[MAX_SIZE];
    int top;
} Stack;

void push(Stack* s, char* data) 
{
    if (s->top == MAX_SIZE - 1) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->array[++(s->top)] = data;
}

char* pop(Stack* s) 
{
    if (s->top == -1) 
    {
        printf("Stack underflow\n");
        return NULL;
    }
    return s->array[(s->top)--];
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

int stringLength(char* inputString) 
{
    int length = 0;
    while (inputString[length] != '\0') 
    {
        length++;
    }
    return length;
}

void concatenate(char *dest, char *src)
{
    int len = stringLength(dest);
    int iteratorI = 0;
    while (src[iteratorI] != '\0')
    {
        dest[len++] = src[iteratorI++];
    }
    dest[len] = '\0';
}

void prefixToInfix(char* inputString) 
{
    Stack s;
    s.top = -1; 
    int n = stringLength(inputString);

    for (int iteratorI = n - 1; iteratorI >= 0; iteratorI--) 
    {
        char ch = inputString[iteratorI];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
        {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = ch;
            operand[1] = '\0';
            push(&s, operand);
        } 
        else if (isOperator(ch)) 
        {
            char* operand1 = pop(&s);
            char* operand2 = pop(&s);
            if (operand1 == NULL || operand2 == NULL) 
            {
                printf("Invalid Expression\n");
                return;
            }

            int size = stringLength(operand1) + stringLength(operand2) + 4;
            char* expression = (char*)malloc(size * sizeof(char));
            expression[0] = '(';
            expression[1] = '\0';

            concatenate(expression, operand1);
            int length = stringLength(expression);
            expression[length] = ch;
            expression[length + 1] = '\0';

            concatenate(expression, operand2);
            length = stringLength(expression);
            expression[length] = ')';
            expression[length + 1] = '\0';

            free(operand1);
            free(operand2);

            push(&s, expression);
        }
    }
    printf("Infix Expression: %s\n", pop(&s));
}

int main() 
{
    char inputString[200];
    printf("Enter prefix expression: ");
    scanf("%s", inputString);
    prefixToInfix(inputString);
    return 0;
}
