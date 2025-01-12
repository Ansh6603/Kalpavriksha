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

void checkAnagram(char *inputString, char *anagramString) {
    int elementFreq[256] = {0};
    int iteratorI = 0;

    while (*(inputString + iteratorI) != '\0') 
    {
        char character = *(inputString + iteratorI);
        if (character >= 'A' && character <= 'Z') {
            character = character + 32; 
        }
        if (character >= 'a' && character <= 'z') {
            elementFreq[character]++;
        }
        iteratorI++;
    }

    iteratorI = 0;
    while (*(anagramString + iteratorI) != '\0')
    {
        char character = *(anagramString + iteratorI);
        if (character >= 'A' && character <= 'Z')
        {
            character = character + 32;
        }
        if (character >= 'a' && character <= 'z')
        {
            elementFreq[character]--;
        }
        iteratorI++;
    }

    for (int i = 0; i < 256; i++) 
    {
        if (elementFreq[i] != 0) 
        {
            printf("Strings are not anagrams of each other.\n");
            return;
        }
    }
    printf("Strings are anagrams of each other.\n");
}

int main() 
{
    char *inputString = (char *)malloc(100 * sizeof(char));
    printf("Enter a string: ");
    readInputFromString(inputString);

    char *anagramString = (char *)malloc(100 * sizeof(char));
    printf("Enter another string: ");
    readInputFromString(anagramString);

    checkAnagram(inputString, anagramString);

    free(inputString);
    free(anagramString);

    return 0;
}
