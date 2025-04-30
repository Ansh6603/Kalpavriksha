#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct Stack 
{
    int array[MAX_SIZE];
    int top;
}Stack;
void push(Stack *s,int data)
{
    if(s->top==MAX_SIZE-1)
    {
        printf("Stack Overflow \n");
        return ;
    }
    s->top++;
    s->array[s->top]=data;
}
int pop(Stack *s)
{
    if(s->top==-1)
    {
        printf("Stack Empty \n");
        return -1;
    }
    return s->array[(s->top)--];
}
int peek(Stack *s)
{
    if(s->top==-1)
    {
        printf("Stack Empty \n");
        return -1;
    }
    return s->array[s->top];
}
void nextSmallest(int* array,int n)
{
    int* nextSmallest=(int *)malloc(n*sizeof(int));
    Stack s;
    s.top=-1;
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        while(s.top!=-1 && (peek(&s))>=array[iteratorI])
        {
            pop(&s);
        }
        if(s.top==-1)
        {
            nextSmallest[iteratorI]=-1;
        }
        else 
        {
            nextSmallest[iteratorI]=peek(&s);
        }
        push(&s,array[iteratorI]);
    }
    printf("Next Smaller Elements: ");
    for (int iteratorI = 0; iteratorI < n; iteratorI++)
    {
        printf("%d ", nextSmallest[iteratorI]);
    }
    printf("\n");

    free(nextSmallest);
}
int main()
{
    int n;
    printf("Enter number of elements \n");
    scanf("%d",&n);
    int* array=(int *)malloc(n*sizeof(int));
    printf("Enter Array elements \n");
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        scanf("%d", &array[iteratorI]);
    }
    nextSmallest(array,n);
    return 0;
}