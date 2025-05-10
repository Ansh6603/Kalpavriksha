#include<stdio.h>
#include<stdlib.h>

void readInputString(char *inputString) 
{
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(inputString + iteratorI) = character;
        iteratorI++;
    }
    *(inputString + iteratorI) = '\0';
}

void findWordCount(char *inputString) 
{
    int iteratorI = 0;
    int wordCount = 0;
    int isWord = 0;

    while (*(inputString + iteratorI) != '\0') 
    {
        char character = *(inputString + iteratorI);

        if (character >= 'A' && character <= 'Z') 
        {
            character = character + 32;
        }

        if (character >= 'a' && character <= 'z') 
        {
            if (isWord == 0) 
            {
                wordCount++;
                isWord = 1;
            }
        } 
        else 
        {
            isWord = 0;
        }

        iteratorI++;
    }

    printf("Word count: %d\n", wordCount);
}

int main() 
{
    int length;
    printf("Enter the length of string: \n");
    scanf("%d", &length);
    getchar();

    char *inputString = (char *)malloc((length + 1) * sizeof(char));
    if (inputString == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter Input String: \n");
    readInputString(inputString);
    
    findWordCount(inputString);

    free(inputString);
    return 0;
}
