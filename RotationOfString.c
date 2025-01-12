#include <stdio.h>
#include <stdlib.h>

int substring(char *temp, char *rotatedString)
{
    int iteratorI = 0, iteratorJ = 0;

    while (*(temp + iteratorI) != '\0') 
    {
        if (*(temp + iteratorI + iteratorJ) == *(rotatedString + iteratorJ)) 
        {
            iteratorJ++;
            if (*(rotatedString + iteratorJ) == '\0')
            {
                return 1;
            }
        } 
        else
        {
            iteratorJ = 0;
            iteratorI++;
        }
    }
    return 0;
}

void rotation(char *inputString, char *rotatedString, int length) 
{
    char *temp = (char *)malloc((2 * length + 1) * sizeof(char));
    int iteratorI = 0, iteratorJ = 0;

    while (*(inputString + iteratorI) != '\0') 
    {
        *(temp + iteratorJ) = *(inputString + iteratorI);
        iteratorI++;
        iteratorJ++;
    }
    iteratorI = 0;
    while (*(inputString + iteratorI) != '\0') 
    {
        *(temp + iteratorJ) = *(inputString + iteratorI);
        iteratorI++;
        iteratorJ++;
    }
    *(temp + iteratorJ) = '\0';

    if (substring(temp, rotatedString))
    {
        printf("True\n");
    } 
    else 
    {
        printf("False\n");
    }

    free(temp);
}

int main() 
{
    char *inputString = (char *)malloc(100 * sizeof(char));
    char *rotatedString = (char *)malloc(100 * sizeof(char));

    printf("Enter Input String: \n");
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(inputString + iteratorI) = character;
        iteratorI++;
    }
    *(inputString + iteratorI) = '\0';

    iteratorI = 0;
    printf("Enter Rotated String: \n");
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(rotatedString + iteratorI) = character;
        iteratorI++;
    }
    *(rotatedString + iteratorI) = '\0';

    rotation(inputString, rotatedString, iteratorI);

    free(inputString);
    free(rotatedString);

    return 0;
}
