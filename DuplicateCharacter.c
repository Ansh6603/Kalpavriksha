#include <stdio.h>
#include <stdlib.h>

void readInputString(char *inputString) 
{
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(inputString+iteratorI) = character;
        iteratorI++;
    }
    inputString[iteratorI] = '\0';
}

void duplicateCharacter(char *inputString) 
{
    int count[256] = {0};
    int iteratorI = 0;

    while (*(inputString+iteratorI) != '\0') 
    {
        char character = *(inputString+iteratorI);
        if (character >= 'A' && character <= 'Z') 
        {
            character = character + 32;
        }

        if ((character >= 'a' && character <= 'z')) 
        {
            count[(unsigned char)character]++;
        }
        iteratorI++;
    }

    printf("Duplicate characters:\n");
    for (int iteratorJ = 0; iteratorJ < 256; iteratorJ++) 
    {
        if (*(count+iteratorJ) > 1) 
        {
            printf("%c occurs %d times\n", iteratorJ, *(count+iteratorJ));
        }
    }
}

int main() 
{
    int length;
    printf("Enter String length : \n");
    scanf("%d", &length);
    getchar(); 

    char *inputString = (char *)malloc((length + 1) * sizeof(char));
    if (!inputString) 
    {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    printf("Enter Input String :\n");
    readInputString(inputString);

    duplicateCharacter(inputString);

    free(inputString);

    return 0;
}
