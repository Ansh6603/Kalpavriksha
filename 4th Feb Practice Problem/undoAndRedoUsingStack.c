#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack 
{
    char array[MAX_SIZE];
    int top;
} Stack;

Stack* createStack() 
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

int isFull(Stack* stack) 
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack* stack, char c) 
{
    if (isFull(stack)) 
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++(stack->top)] = c;
}

char pop(Stack* stack)
{
    if (isEmpty(stack)) 
    {
        printf("Stack Underflow\n");
        return '\0';  
    }
    return stack->array[(stack->top)--];
}

char peek(Stack* stack)
{
    if (isEmpty(stack))
    {
        return '\0';  
    }
    return stack->array[stack->top];
}

void printStack(Stack* stack) 
{
    if (isEmpty(stack)) 
    {
        printf("Empty\n");
        return;
    }
    for (int iteratorI = 0; iteratorI <= stack->top; iteratorI++) 
    {
        printf("%c", stack->array[iteratorI]);
    }
    printf("\n");
}

void type(Stack* undoStack, Stack* redoStack, char c)
{
    push(undoStack, c);
    redoStack->top = -1;
}

void undo(Stack* undoStack, Stack* redoStack) 
{
    if (isEmpty(undoStack)) 
    {
        printf("Nothing to Undo.\n");
        return;
    }
    char lastChar = pop(undoStack);
    push(redoStack, lastChar);
    printf("Undo performed.\n");
}

void redo(Stack* undoStack, Stack* redoStack) 
{
    if (isEmpty(redoStack)) 
    {
        printf("Nothing to Redo.\n");
        return;
    }
    char lastUndoneChar = pop(redoStack);
    push(undoStack, lastUndoneChar);
    printf("Redo performed.\n");
}

int main() 
{
    Stack* undoStack = createStack();
    Stack* redoStack = createStack();
    
    char input;
    
    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Type a character\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Display Text\n");
        printf("5. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        getchar();  
        
        switch (choice) 
        {
            case 1:
                printf("Enter a character to type: ");
                input = getchar();
                getchar();  
                type(undoStack, redoStack, input);
                break;
            case 2:
                undo(undoStack, redoStack);
                break;
            case 3:
                redo(undoStack, redoStack);
                break;
            case 4:
                printf("Current text: ");
                printStack(undoStack);
                break;
            case 5:
                printf("Exit\n");
                free(undoStack);
                free(redoStack);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
