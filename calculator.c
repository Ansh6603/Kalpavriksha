#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100
#define OPERATORS "+-*/"

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int performOperation(int operandA, int operandB, char operatorChar)
{
    switch (operatorChar)
    {
    case '+':
        return operandA + operandB;
    case '-':
        return operandA - operandB;
    case '*':
        return operandA * operandB;
    case '/':
        if (operandB == 0)
        {
            printf("Error: Division by zero.\n");
            exit(1);
        }
        return operandA / operandB;
    default:
        return 0;
    }
}

int getPrecedence(char operatorChar)
{
    if (operatorChar == '/')
        return 4;
    if (operatorChar == '*')
        return 3;
    if (operatorChar == '+')
        return 2;
    if (operatorChar == '-')
        return 1;
    return 0;
}

void skipWhitespace(char *expression, int *iteratorI)
{
    while (expression[*iteratorI] == ' ')
    {
        (*iteratorI)++;
    }
}

int handleNegativeNumbers(char *expression, int *iteratorI, int *isLastOperator)
{
    if (expression[*iteratorI] == '-' && (*iteratorI == 0 || *isLastOperator))
    {
        (*iteratorI)++;
        int number = 0;
        while (isDigit(expression[*iteratorI]))
        {
            number = number * 10 + (expression[*iteratorI] - '0');
            (*iteratorI)++;
        }
        *isLastOperator = 0;
        return -number;
    }
    return 0;
}

int handleOperands(char *expression, int *iteratorI)
{
    int number = 0;
    while (isDigit(expression[*iteratorI]))
    {
        number = number * 10 + (expression[*iteratorI] - '0');
        (*iteratorI)++;
    }
    return number;
}

void handleOperator(char *expression, int *iteratorI, int *operandStack, int *operandTop, int *operatorStack, int *operatorTop, int *isLastOperator)
{
    while (*operatorTop != -1 && getPrecedence(operatorStack[*operatorTop]) >= getPrecedence(expression[*iteratorI]))
    {
        int operandB = operandStack[*operandTop];
        (*operandTop)--;

        int operandA = operandStack[*operandTop];
        (*operandTop)--;

        char operatorChar = operatorStack[*operatorTop];
        (*operatorTop)--;

        operandStack[++(*operandTop)] = performOperation(operandA, operandB, operatorChar);
    }

    operatorStack[++(*operatorTop)] = expression[*iteratorI];
    *isLastOperator = 1;
}

void evaluateRemainingOperator(int *operandStack, int *operandTop, int *operatorStack, int *operatorTop)
{
    while (*operatorTop != -1)
    {
        int operandB = operandStack[*operandTop];
        (*operandTop)--;

        int operandA = operandStack[*operandTop];
        (*operandTop)--;

        char operatorChar = operatorStack[*operatorTop];
        (*operatorTop)--;

        operandStack[++(*operandTop)] = performOperation(operandA, operandB, operatorChar);
    }
}

int evaluateExpression(char *expression)
{
    int operandStack[MAX_BUFFER_SIZE], operandTop = -1;
    int operatorStack[MAX_BUFFER_SIZE], operatorTop = -1;
    int iteratorI = 0;
    int isLastOperator = 1;

    while (expression[iteratorI] != '\0' && expression[iteratorI] != '\n')
    {
        skipWhitespace(expression, &iteratorI);

        int negativeNumber = handleNegativeNumbers(expression, &iteratorI, &isLastOperator);
        if (negativeNumber != 0)
        {
            operandStack[++operandTop] = negativeNumber;
            continue;
        }

        if (isDigit(expression[iteratorI]))
        {
            int number = handleOperands(expression, &iteratorI);
            operandStack[++operandTop] = number;
            isLastOperator = 0;
            continue;
        }

        if (strchr(OPERATORS, expression[iteratorI]))
        {
            if (isLastOperator)
            {
                printf("Error: Invalid expression.\n");
                exit(1);
            }

            handleOperator(expression, &iteratorI, operandStack, &operandTop, operatorStack, &operatorTop, &isLastOperator);
        }
        else
        {
            printf("Error: Invalid expression.\n");
            exit(1);
        }

        iteratorI++;
    }

    evaluateRemainingOperator(operandStack, &operandTop, operatorStack, &operatorTop);

    return operandStack[operandTop];
}

int main()
{
    char inputExpression[MAX_BUFFER_SIZE];
    printf("Enter your expression: ");
    fgets(inputExpression, MAX_BUFFER_SIZE, stdin);
    system("clear");
    int result = evaluateExpression(inputExpression);
    printf("Output: %d\n", result);

    return 0;
}
