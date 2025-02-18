#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct BookMark
{
    int *page;
} BookMark;

typedef struct Stack
{
    BookMark* bookmark;
    int top;
} Stack;

BookMark* createBookMark()
{
    BookMark* bookmark = (BookMark *)malloc(sizeof(BookMark));
    bookmark->page = (int *)malloc(MAX_SIZE * sizeof(int));
    return bookmark;
}

Stack* createStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->bookmark = createBookMark();
    s->top = -1;
    return s;
}

int isFull(Stack* s)
{
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack* s)
{
    return s->top == -1;
}

void addBookMark(Stack* s, int data)
{
    if (isFull(s))
    {
        printf("BookMark Full\n");
        return;
    }
    s->top++;
    s->bookmark->page[s->top] = data;
}

int deleteBookMark(Stack* s)
{
    if (isEmpty(s))
    {
        printf("No bookmarks\n");
        return -1;
    }
    return s->bookmark->page[(s->top)--];
}

void sortBookmarks(int *arr, int n)
{
    for (int iteratorI = 0; iteratorI < n - 1; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < n - iteratorI - 1; iteratorJ++)
        {
            if (arr[iteratorJ] > arr[iteratorJ + 1])
            {
                int temp = arr[iteratorJ];
                arr[iteratorJ] = arr[iteratorJ + 1];
                arr[iteratorJ + 1] = temp;
            }
        }
    }
}

void display(Stack* s)
{
    if (isEmpty(s))
    {
        printf("No bookmarks\n");
        return;
    }
    int *tempArr = (int *)malloc((s->top + 1) * sizeof(int));
    for (int iteratorI = 0; iteratorI <= s->top; iteratorI++)
    {
        tempArr[iteratorI] = s->bookmark->page[iteratorI];
    }
    sortBookmarks(tempArr, s->top + 1);
    for (int iteratorI = 0; iteratorI <= s->top; iteratorI++)
    {
        printf("%d ", tempArr[iteratorI]);
    }
    printf("\n");
    free(tempArr);
}

int compareStrings(char *str1, char *str2)
{
    int iteratorI = 0;
    while (str1[iteratorI] != '\0' && str2[iteratorI] != '\0')
    {
        if (str1[iteratorI] != str2[iteratorI]) return 0;
        iteratorI++;
    }
    return (str1[iteratorI] == '\0' && str2[iteratorI] == '\0');
}

int main()
{
    int n;
    scanf("%d", &n);
    
    Stack* s = createStack();
    
    char command[10];
    int page;
    
    for (int iteratorI = 0; iteratorI < n; iteratorI++)
    {
        scanf("%s", command);
        
        int operation = -1;
        
        if (compareStrings(command, "BOOKMARK"))
        {
            operation = 1;
        }
        else if (compareStrings(command, "DELETE"))
        {
            operation = 2;
        }
        else if (compareStrings(command, "LIST"))
        {
            operation = 3;
        }
        
        switch (operation)
        {
            case 1:
                scanf("%d", &page);
                if (page >= 1 && page <= 1000)
                {
                    addBookMark(s, page);
                }
                break;
            case 2:
                deleteBookMark(s);
                break;
            case 3:
                display(s);
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    free(s->bookmark->page);
    free(s->bookmark);
    free(s);

    return 0;
}
