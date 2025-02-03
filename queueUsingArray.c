#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() 
{
    return front == -1;
}

int size() 
{
    if(isEmpty())
    {
        return 0;
    } 
    return rear - front + 1;
}

void enqueue(int data) 
{
    if(rear == MAX_SIZE - 1) 
    {
        printf("Queue Overflow\n");
    } 
    else 
    {
        if(front == -1){
            front = 0;
        }
        queue[++rear] = data;
        printf("%d added to queue\n", data);
    }
}

int dequeue() 
{
    if(isEmpty()) 
    {
        printf("Queue is Empty\n");
        return -1;
    } 
    else 
    {
        int value = queue[front];
        if(front == rear) 
        {
            front = rear = -1;
        }
        else 
        {
            front++;
        }
        return value;
    }
}

int peek() 
{
    if(isEmpty()) 
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

int main() 
{
    int choice, data;

    while(1) 
    {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Queue Empty\n");
        printf("5. Queue size\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if(data != -1) 
                {
                    printf("Dequeued value: %d\n", data);
                }
                break;
            case 3:
                data = peek();
                if(data != -1)
                {
                    printf("Front element is: %d\n", data);
                } 
                break;
            case 4:
                if(isEmpty()) 
                {
                    printf("Queue is empty\n");
                }
                else 
                {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Queue size is: %d\n", size());
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
