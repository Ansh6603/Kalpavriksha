#include <stdio.h>
#include <stdlib.h>

struct Queue 
{
    int size;
    int front;
    int rear;
    int *arr;
};

struct Queue* createQueue(int size) 
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = size;
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int*)malloc(queue->size * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) 
{
    return queue->front == -1;
}

int isFull(struct Queue* queue) 
{
    return queue->rear == queue->size - 1;
}

void enqueue(struct Queue* queue, int data) 
{
    if (isFull(queue)) 
    {
        printf("Queue is Full\n");
        return;
    }
    if (queue->front == -1) 
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->arr[queue->rear] = data;
}

int dequeue(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear) 
    {
        queue->front = -1;
        queue->rear = -1;
    }
    return data;
}

void printQueue(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is Empty\n");
        return;
    }
    for (int iteratorI = queue->rear; iteratorI >= queue->front; iteratorI--) 
    {
        printf("%d ", queue->arr[iteratorI]);
    }
    printf("\n");
}


void push(struct Queue* queue, int data) 
{
    enqueue(queue, data);
    int size = queue->rear - queue->front + 1;
    for (int iteratorI = 0; iteratorI < size - 1; iteratorI++) 
    {
        int data = dequeue(queue);
        enqueue(queue, data);
    }
}

int pop(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return dequeue(queue);
}

int peek(struct Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int main() 
{
    struct Queue* queue1 = createQueue(100); 
    int choice, data;

    while (1) 
    {
        printf("\nStack Operations\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Is Stack Empty\n");
        printf("5. Size of Stack\n");
        printf("6. Print Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(queue1, data);
                break;
            case 2:
                data = pop(queue1);
                if (data != -1) 
                {
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                data = peek(queue1);
                if (data != -1) 
                {
                    printf("Peek: %d\n", data);
                }
                break;
            case 4:
                if (isEmpty(queue1)) 
                {
                    printf("Stack is empty\n");
                } 
                else 
                {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Size of Stack: %d\n", queue1->rear - queue1->front + 1);
                break;
            case 6:
                printf("Current Stack: ");
                printQueue(queue1);
                break;
            case 7:
                free(queue1->arr);
                free(queue1);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
