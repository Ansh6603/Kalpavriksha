#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void readInputFromString(char *inputString) 
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
int isDigit(char c) 
{
    return (c >= '0' && c <= '9');
}
int convertStringToInteger(int *array, char *inputString) 
{
    int iteratorK = 0;
    int iteratorI = 0;
    int valid = 1;

    while (*(inputString + iteratorK) != '\0') 
    {
        int sign = 1;
        int currentNumber = 0;

        if (*(inputString + iteratorK) == '-') 
        {
            sign = -1;
            iteratorK++;
        }

        if (isdigit(*(inputString + iteratorK))) 
        {
            while (isdigit(*(inputString + iteratorK))) 
            {
                currentNumber = currentNumber * 10 + (*(inputString + iteratorK) - '0');
                iteratorK++;
            }
            *(array + iteratorI) = sign * currentNumber;
            iteratorI++;
        } 
        else 
        {
            valid = 0;
            break;
        }

        if (*(inputString + iteratorK) == ',' ||  *(inputString + iteratorK) == ' ')
        {
            iteratorK++;
        } 
        else if (*(inputString + iteratorK) != '\0') 
        {
            valid = 0;
            break;
        }
    }

    if (!valid) 
    {
        printf("Invalid Input\n");
        return 0;
    }

    printf("Converted Numbers: ");
    for (int i = 0; i < iteratorI; i++) 
    {
        printf("%d ", *(array + i));
    }
    printf("\n");

    return iteratorI;
}

int main() 
{
    char *inputString = (char *)malloc(100 * sizeof(char));
    printf("Enter a string of numbers:\n");
    readInputFromString(inputString);

    int *array = (int *)malloc(100 * sizeof(int));
    if (convertStringToInteger(array, inputString) > 0) 
    {
        printf("Conversion successful.\n");
    }

    free(inputString);
    free(array);

    return 0;
}
