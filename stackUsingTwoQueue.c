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
    struct Queue* Queue = (struct Queue*)malloc(sizeof(struct Queue));
    Queue->size = size;
    Queue->front = -1;
    Queue->rear = -1;
    Queue->arr = (int*)malloc(Queue->size * sizeof(int));
    return Queue;
}

int isEmpty(struct Queue* Queue) 
{
    return Queue->front == -1;
}

int isFull(struct Queue* Queue) 
{
    return Queue->rear == Queue->size - 1;
}

void enqueue(struct Queue* Queue, int data) 
{
    if (isFull(Queue)) 
    {
        printf("Queue is Full\n");
        return;
    }
    if (Queue->front == -1) 
    {
        Queue->front = 0;
    }
    Queue->rear++;
    Queue->arr[Queue->rear] = data;
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
    for (int iteratorI = queue->front; iteratorI <= queue->rear; iteratorI++) 
    {
        printf("%d ", queue->arr[iteratorI]);
    }
    printf("\n");
}

void push(struct Queue* queue, int data) 
{
    enqueue(queue, data);
}

int pop(struct Queue* queue1, struct Queue* queue2) 
{
    if (isEmpty(queue1)) 
    {
        printf("Stack is empty\n");
        return -1;
    }

    while (queue1->front < queue1->rear) 
    {
        int data = dequeue(queue1);
        enqueue(queue2, data);
    }

    int popdata = dequeue(queue1);

    while (!isEmpty(queue2)) 
    {
        int data = dequeue(queue2);
        enqueue(queue1, data);
    }

    return popdata;
}


int peek(struct Queue* queue1) 
{
    if (isEmpty(queue1)) 
    {
        printf("Stack is empty\n");
        return -1;
    }
    struct Queue* queue2 = createQueue(queue1->size);

    while (queue1->front < queue1->rear) 
    {
        int data = dequeue(queue1);
        enqueue(queue2, data);
    }

    int top = dequeue(queue1);

    enqueue(queue1, top);

    while (!isEmpty(queue2)) 
    {
        int data = dequeue(queue2);
        enqueue(queue1, data);
    }

    free(queue2->arr);
    free(queue2);

    return top;
}

int main() 
{
    struct Queue* Queue1 = createQueue(100); 
    struct Queue* Queue2 = createQueue(100);
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
                push(Queue1, data);
                break;
            case 2:
                data = pop(Queue1, Queue2);
                if (data != -1) 
                {
                    printf("Popped: %d\n", data);
                }
                break;
            case 3:
                data = peek(Queue1);
                if (data != -1) 
                {
                    printf("Peek: %d\n", data);
                }
                break;
            case 4:
                if (isEmpty(Queue1)) 
                {
                    printf("Stack is empty\n");
                } 
                else 
                {
                    printf("Stack is not empty\n");
                }
                break;
            case 5:
                printf("Size of Stack: %d\n", Queue1->rear - Queue1->front + 1);
                break;
            case 6:
                printf("Current Stack: ");
                printQueue(Queue1);
                break;
            case 7:
                free(Queue1->arr);
                free(Queue2->arr);
                free(Queue1);
                free(Queue2);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
