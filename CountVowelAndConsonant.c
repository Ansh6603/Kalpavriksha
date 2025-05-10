#include <stdio.h>
#include <stdlib.h>

void readInput(char *input, int length) 
{
    int iteratorI = 0;
    char character;
    while (iteratorI < length && (character = getchar()) != '\n' && character != EOF) 
    {
        *(input + iteratorI) = character;
        iteratorI++;
    }
    *(input + iteratorI) = '\0';
}

void countVowelAndConsonant(char *inputString) 
{
    int iteratorI = 0, countVowel = 0, countConsonant = 0;
    while (*(inputString + iteratorI) != '\0') 
    {
        char currentChar = *(inputString + iteratorI);
        if (currentChar >= 'A' && currentChar <= 'Z') 
        {
            currentChar += 32;
        }
        if (currentChar >= 'a' && currentChar <= 'z') 
        {
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || 
                currentChar == 'o' || currentChar == 'u') {
                countVowel++;
            } 
            else 
            {
                countConsonant++;
            }
        }
        iteratorI++;
    }
    printf("Vowel Count: %d\n", countVowel);
    printf("Consonant Count: %d\n", countConsonant);
}

int main() 
{
    int length;
    printf("Enter length of the string: ");
    scanf("%d", &length);
    getchar();
    char *inputString = (char *)malloc((length + 1) * sizeof(char));
    if (inputString == NULL) 
    {
        return 1;
    }
    printf("Enter the string: ");
    readInput(inputString, length);
    countVowelAndConsonant(inputString);
    free(inputString);
    return 0;
}
