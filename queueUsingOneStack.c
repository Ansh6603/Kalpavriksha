#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack 
{
    int top;
    int *arr;
    int size;  
};

struct Stack* createStack() 
{
    struct Stack* stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    stack->size = 0;
    return stack;
}

int isFull(struct Stack* stack) 
{
    return stack->size == MAX_SIZE;
}

int isEmpty(struct Stack* stack) 
{
    return stack->size == 0;
}

void push(struct Stack* stack, int data) 
{
    if (isFull(stack))
    {
        printf("Queue Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
    stack->size++;
}

int pop(struct Stack* stack)
{
    if (isEmpty(stack)) 
    {
        printf("Queue Underflow\n");
        return -1;
    }
    stack->size--;
    return stack->arr[stack->top--];
}

int peek(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int queueSize(struct Stack* stack) 
{
    return stack->size;
}

int dequeueFunc(struct Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Queue is empty\n");
        return -1;
    }

    if (stack->size == 1) 
    {
        return pop(stack);
    }

    int frontElement = pop(stack);
    int dequeued = dequeueFunc(stack);

    push(stack, frontElement);

    return dequeued;
}

void enqueue(struct Stack* stack, int data) 
{
    push(stack, data);
}

int dequeue(struct Stack* stack) 
{
    return dequeueFunc(stack);
}

int main() 
{
    struct Stack* stack = createStack();
    int choice, data;

    while (1) {
        printf("\nQueue Operations :\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Queue Empty\n");
        printf("5. Queue Size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(stack, data);
                break;
            case 2:
                data = dequeue(stack);
                if (data != -1) 
                {
                    printf("Dequeued: %d\n", data);
                }
                break;
            case 3:
                data = peek(stack);
                if (data != -1) 
                {
                    printf("Front element: %d\n", data);
                }
                break;
            case 4:
                if (isEmpty(stack))
                {
                    printf("Queue is empty\n");
                } 
                else 
                {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Queue size: %d\n", queueSize(stack));
                break;
            case 6:
                free(stack->arr);
                free(stack);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
