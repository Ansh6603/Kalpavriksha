#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100  

struct Stack
{
    int top;
    int capacity;
    int *arr;
};

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = MAX_SIZE;  
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Queue is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int queueSize(struct Stack* inputStack, struct Stack* outputStack)
{
    return (inputStack->top + 1) + (outputStack->top + 1);
}

void enqueue(struct Stack* inputStack, int data)
{
    push(inputStack, data);
}

int dequeue(struct Stack* inputStack, struct Stack* outputStack)
{
    if (isEmpty(outputStack)) 
    {
        while (!isEmpty(inputStack)) 
        {
            push(outputStack, pop(inputStack));
        }
    }

    if (isEmpty(outputStack))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(outputStack);
}

int main()
{
    int choice, data;

    struct Stack* inputStack = createStack();
    struct Stack* outputStack = createStack();

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Queue Empty\n");
        printf("5. Queue size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(inputStack, data);
                break;
            case 2:
                data = dequeue(inputStack, outputStack);
                if (data != -1) 
                {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                data = peek(outputStack);
                if (data == -1) 
                {
                    data = peek(inputStack);
                }
                if (data != -1)
                {
                    printf("Front element: %d\n", data);
                }
                break;
            case 4:
                if (isEmpty(inputStack) && isEmpty(outputStack)) 
                {
                    printf("Queue is empty\n");
                } 
                else 
                {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Queue size: %d\n", queueSize(inputStack, outputStack));
                break;
            case 6:
                free(inputStack->arr);
                free(outputStack->arr);
                free(inputStack);
                free(outputStack);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
