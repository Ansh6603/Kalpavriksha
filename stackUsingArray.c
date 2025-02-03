#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isEmpty()
{
    return top == -1;
}

int size()
{
    return top + 1;
}

void push(int value)
{
    if (top < MAX_SIZE - 1)
    {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

int peek()
{
    if (top >= 0)
    {
        return stack[top];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Stack Empty\n");
        printf("5. Stack size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            value = pop();
            if (value != -1)
            {
                printf("Popped value: %d\n", value);
            }
            break;
        case 3:
            value = peek();
            if (value != -1)
            {
                printf("Top element is: %d\n", value);
            }
            break;
        case 4:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            break;
        case 5:
            printf("Stack size is: %d\n", size());
            break;
        case 6:
            printf("Exit \n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
