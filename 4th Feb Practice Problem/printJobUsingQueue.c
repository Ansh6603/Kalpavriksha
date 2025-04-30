#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct PrintJob 
{
    char documentName[200];
    int pageNumber;
} PrintJob;

typedef struct Queue 
{
    PrintJob job[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue() 
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isFull(Queue* queue) 
{
    return queue->rear == MAX_SIZE - 1;
}

int isEmpty(Queue* queue) 
{
    return queue->front > queue->rear;
}

void stringCopy(char* dest, char* src) 
{
    int iteratorI = 0;
    while (src[iteratorI] != '\0')
    {
        dest[iteratorI] = src[iteratorI];
        iteratorI++;
    }
    dest[iteratorI] = '\0';
}

void readInputString(char* inputString, int maxLength) 
{
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        if (iteratorI < maxLength - 1)
        {
            inputString[iteratorI++] = character;
        }
    }
    inputString[iteratorI] = '\0';
}

void enqueue(Queue* queue, char* documentName, int numPage) 
{
    if (isFull(queue)) 
    {
        printf("Queue Full \n");
        return;
    }
    PrintJob newJob;
    stringCopy(newJob.documentName, documentName);
    newJob.pageNumber = numPage;
    queue->rear++;
    queue->job[queue->rear] = newJob;
    printf("Print job added: %s, Pages: %d\n", documentName, numPage);
}

void dequeue(Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue Underflow \n");
        return;
    }
    PrintJob job = queue->job[queue->front];
    printf("Printing: %s, Pages: %d\n", job.documentName, job.pageNumber);
    queue->front++;
    if (queue->front > queue->rear) 
    {
        queue->front = 0;
        queue->rear = -1;
    }
}

void cancelJob(Queue* queue, int index) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue Underflow \n");
        return;
    }
    if (index < 1 || index > (queue->rear - queue->front + 1)) 
    {
        printf("Invalid Job \n");
        return;
    }
    int cancelIndex = queue->front + index - 1;
    for (int iteratorI = cancelIndex; iteratorI < queue->rear; iteratorI++) 
    {
        queue->job[iteratorI] = queue->job[iteratorI + 1];
    }
    queue->rear--;
    if (queue->front > queue->rear) 
    {
        queue->front = 0;
        queue->rear = -1;
    }
}

void updateJob(Queue* queue, int index, char* documentName, int pageNumber) 
{
    if (isEmpty(queue)) 
    {
        printf("Queue is empty \n");
        return;
    }
    if (index < 1 || index > (queue->rear - queue->front + 1))
    {
        printf("Invalid Job \n");
        return;
    }
    int updateIndex = queue->front + index - 1;
    stringCopy(queue->job[updateIndex].documentName, documentName);
    queue->job[updateIndex].pageNumber = pageNumber;
}

void displayJobs(Queue* queue) 
{
    if (isEmpty(queue)) 
    {
        printf("No pending jobs in the queue.\n");
        return;
    }
    printf("Pending Print Jobs:\n");
    for (int iteratorI = queue->front; iteratorI <= queue->rear; iteratorI++) 
    {
        printf("%d. Document: %s, Pages: %d\n", iteratorI - queue->front + 1, queue->job[iteratorI].documentName, queue->job[iteratorI].pageNumber);
    }
}

int main() 
{
    Queue* queue = createQueue();
    int choice, numPages, index;
    char documentName[200];

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
            case 1:
                printf("Enter the document name: ");
                readInputString(documentName, sizeof(documentName));

                printf("Enter the number of pages: ");
                scanf("%d", &numPages);

                enqueue(queue, documentName, numPages);
                break;

            case 2:
                displayJobs(queue);
                break;

            case 3:
                printf("Enter the job index to update: ");
                scanf("%d", &index);
                getchar();
                printf("Enter the new document name: ");
                readInputString(documentName, sizeof(documentName));
                printf("Enter the new number of pages: ");
                scanf("%d", &numPages);

                updateJob(queue, index, documentName, numPages);
                break;

            case 4:
                dequeue(queue);
                break;

            case 5:
                printf("Enter the job index to cancel: ");
                scanf("%d", &index);
                cancelJob(queue, index);
                break;

            case 6:
                free(queue);
                return 0;

            default:
                printf("Invalid choice \n");
        }
    }
}