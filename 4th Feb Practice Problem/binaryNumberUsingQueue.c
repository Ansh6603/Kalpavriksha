#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct Queue
{
    int front;
    int rear ;
    char* array[MAX_SIZE];
}Queue;
Queue* createQueue()
{
    Queue* queue=(Queue *)malloc(sizeof(Queue));
    queue->front=0;
    queue->rear=-1;
    return queue;
}
int isFull(Queue* queue)
{
    return queue->rear==MAX_SIZE-1;
}
int isEmpty(Queue* queue)
{
    return queue->front>queue->rear;
}
void enqueue(Queue* queue,char* data)
{
    if(isFull(queue))
    {
        printf("Queue Overflow \n");
        return ;
    }
    queue->rear++;
    queue->array[queue->rear]=data;
}
char* dequeue(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue Empty \n");
        return '\0';
    }
    return queue->array[(queue->front)++];
}
void binaryNumber(Queue* queue,int n)
{
    char* firstBinary=(char *)malloc(2*sizeof(char));
    firstBinary[0]='1';
    firstBinary[1]='\0';
    enqueue(queue,firstBinary);
    for(int iteratorI=1;iteratorI<=n;iteratorI++)
    {
        char* current=dequeue(queue);
        printf("%s \n",current);
        int len=0;
        while(current[len]!='\0')
        {
            len++;
        }
        char* binary0=(char *)malloc((len+2)*sizeof(char));
        char* binary1=(char *)malloc((len+2)*sizeof(char));
        for(int iteratorI=0;iteratorI<len;iteratorI++)
        {
            binary0[iteratorI]=current[iteratorI];
        }
        binary0[len]='0';
        binary0[len+1]='\0';
        for(int iteratorI=0;iteratorI<len;iteratorI++)
        {
            binary1[iteratorI]=current[iteratorI];
        }
        binary1[len]='1';
        binary1[len+1]='\0';
        enqueue(queue,binary0);
        enqueue(queue,binary1);
        free(current);
    }
    free(queue);
}
int main()
{
    printf("Enter value of N \n");
    int n;
    scanf("%d",&n);
    Queue* queue=createQueue();
    binaryNumber(queue,n);
}