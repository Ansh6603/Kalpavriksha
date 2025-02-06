#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Stack
{
    char string[20];
    struct Stack *next;
}node;

node *top = NULL;


void push(char string[10])
{   
    node *newNode = malloc(sizeof(node));
    strcpy(newNode->string,string);
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if(top == NULL)
    {
        return;
    }
    node *temp = top;
    top = top->next;
    free(temp);
}

void printFolder(node *temp)
{
    if(temp == NULL)
    {
        printf("/");
        return;
    }
    printFolder(temp->next);
    printf("%s/",temp->string);
    
}

int main()
{
    int count = 4;
    while(count--)
    {
        char string[20];
        scanf("cd ");
        scanf("%[^\n]s",string);
        getchar();
        string[strcspn(string,"/")] = '\0';
        if(strcmp(string,"..")==0)
        {
            pop();
        }
        else if(strcmp(string,".") == 0)
        {
            continue;
        }
        else
        {
            push(string);
        }
    }
    printFolder(top);
}