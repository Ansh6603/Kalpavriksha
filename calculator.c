#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_SIZE 100

int operation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("Error: Division by zero.\n");
            exit(1);
        }
        return a / b;
    default:
        return 0;
    }
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int evaluate(char *exp)
{
    int stack1[MAX_SIZE], top1 = -1;
    char stack2[MAX_SIZE], top2 = -1;
    int i = 0;
    int lastOperator = 1;
    while (exp[i] != '\0' && exp[i] != '\n')
    {
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }
        if (exp[i] == '-' && (i == 0 || lastOperator))
        {
            i++;
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            stack1[++top1] = -num;
            lastOperator = 0;
            continue;
        }
        if (isdigit(exp[i]))
        {
            int num = 0;
            while (isdigit(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            stack1[++top1] = num;
            lastOperator = 0;
            continue;
        }
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            if (lastOperator)
            {
                printf("Error: Invalid expression.\n");
                exit(1);
            }
            while (top2 != -1 && precedence(stack2[top2]) >= precedence(exp[i]))
            {
                int b = stack1[top1--];
                int a = stack1[top1--];
                char op = stack2[top2--];
                stack1[++top1] = operation(a, b, op);
            }
            stack2[++top2] = exp[i];
            lastOperator = 1;
        }
        else
        {
            printf("Error: Invalid expression.\n");
            exit(1);
        }
        i++;
    }
    while (top2 != -1)
    {
        int b = stack1[top1--];
        int a = stack1[top1--];
        char op = stack2[top2--];
        stack1[++top1] = operation(a, b, op);
    }
    return stack1[0];
}

int main()
{
    char exp[MAX_SIZE];
    printf("Enter your expression: ");
    fgets(exp, MAX_SIZE, stdin);
    int res = evaluate(exp);
    printf("Output: %d\n", res);
    return 0;
}