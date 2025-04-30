#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef struct Task
{
    char task[MAX_SIZE][100];
    char status[MAX_SIZE][15];
    int size;
} Task;

Task* createTask()
{
    Task* task = (Task*)malloc(sizeof(Task));
    task->size = -1;
    return task;
}

void stringCopy(char* dest, char* src)
{
    int iteratorI = 0;
    while (*(src + iteratorI) != '\0')
    {
        *(dest + iteratorI) = *(src + iteratorI);
        iteratorI++;
    }
    *(dest + iteratorI) = '\0';
}

void addTask(Task* t, char* task)
{
    if (t->size == MAX_SIZE - 1)
    {
        printf("Task Full \n");
        return;
    }
    t->size++;
    stringCopy(t->task[t->size], task);
    stringCopy(t->status[t->size], "PENDING");
}

int stringCompare(char* str1, char* str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == *str2);
}

void completeTask(Task* t, char* task)
{
    for (int iteratorI = 0; iteratorI <= t->size; iteratorI++)
    {
        if (stringCompare(t->task[iteratorI], task))
        {
            stringCopy(t->status[iteratorI], "COMPLETE");
        }
    }
}

void pendingTask(Task* t)
{
    int found = 0;
    for (int iteratorI = 0; iteratorI <= t->size; iteratorI++)
    {
        if (stringCompare(t->status[iteratorI], "PENDING"))
        {
            printf("%s\n", t->task[iteratorI]);
            found = 1;
        }
    }
    if (!found)
    {
        printf("All tasks completed\n");
    }
}

int main()
{
    Task* t = createTask();
    int n;
    scanf("%d", &n);
    getchar();
    
    for (int iteratorI = 0; iteratorI < n; iteratorI++)
    {
        char command[10];
        char task[100];
        scanf("%s", command);

        if (stringCompare(command, "ADD"))
        {
            scanf(" %[^\n]", task);
            addTask(t, task);
        }
        else if (stringCompare(command, "COMPLETE"))
        {
            scanf(" %[^\n]", task);
            completeTask(t, task);
        }
        else if (stringCompare(command, "PENDING"))
        {
            pendingTask(t);
        }
    }

    free(t);
    return 0;
}
