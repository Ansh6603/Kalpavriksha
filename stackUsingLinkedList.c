#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
int isEmpty()
{
    return top == NULL;
}
void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed \n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", data);
}
int pop()
{
    if (isEmpty())
    {
        printf("Stack is Empty\n");
        return -1;
    }
    struct Node *temp = top;
    int value = top->data;
    top = top->next;
    free(temp);
    return value;
}
int peek()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}
int size()
{
    int count = 0;
    struct Node *temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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