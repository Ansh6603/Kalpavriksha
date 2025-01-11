#include <stdio.h>
#include <stdlib.h>

void countVowelsAndConsonants(char *inputString) 
{
    int vowelCount = 0, consonantCount = 0, iteratorI = 0;

    while (inputString[iteratorI] != '\0') 
    {
        char currentChar = inputString[iteratorI];
        if (currentChar >= 'A' && currentChar <= 'Z') 
        {
            currentChar = currentChar + 32;
        }
        if (currentChar >= 'a' && currentChar <= 'z') 
        {
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') 
            {
                vowelCount++;
            } 
            else
            {
                consonantCount++;
            }
        }
        iteratorI++;
    }

    printf("Vowels: %d\n", vowelCount);
    printf("Consonants: %d\n", consonantCount);
}

int main() 
{
    char *inputString;
    int stringLength;

    printf("Enter the length of the string: ");
    scanf("%d", &stringLength);

    inputString = (char *)malloc((stringLength + 1) * sizeof(char));

    printf("Enter the string: ");
    getchar();
    for (int iteratorI = 0; iteratorI < stringLength; iteratorI++) 
    {
        scanf("%c", &inputString[iteratorI]);
    }
    inputString[stringLength] = '\0';

    countVowelsAndConsonants(inputString);

    free(inputString);

    return 0;
}
