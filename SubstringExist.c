#include <stdio.h>
#include <stdlib.h>

void substringExist(char *inputString, char *substring) 
{
    char **words = (char **)malloc(100 * sizeof(char *));
    for (int iteratorI = 0; iteratorI < 100; iteratorI++)
    {
        *(words + iteratorI) = (char *)malloc(20 * sizeof(char));
    }

    int iteratorI = 0, iteratorJ = 0, wordCount = 0;

    while (*(inputString + iteratorI) != '\0') 
    {
        if ((*(inputString + iteratorI) >= 'a' && *(inputString + iteratorI) <= 'z') || 
            (*(inputString + iteratorI) >= 'A' && *(inputString + iteratorI) <= 'Z')) 
        {
            *((*(words + wordCount)) + iteratorJ) = *(inputString + iteratorI);
            iteratorJ++;
        } 
        else 
        {
            if (iteratorJ > 0)
            {  
                *((*(words + wordCount)) + iteratorJ) = '\0';
                wordCount++;
                iteratorJ = 0;
            }
        }
        iteratorI++;
    }

    if (iteratorJ > 0)
    {  
        *((*(words + wordCount)) + iteratorJ) = '\0';
        wordCount++;
    }

    for (int iteratorI = 0; iteratorI < wordCount; iteratorI++) 
    {
        int iteratorK = 0;
        while (1) 
        {
            char wordChar = *((*(words + iteratorI)) + iteratorK);
            char subChar = *(substring + iteratorK);
            
            if (wordChar >= 'A' && wordChar <= 'Z') {
                wordChar += 'a' - 'A';  
            }
            if (subChar >= 'A' && subChar <= 'Z') {
                subChar += 'a' - 'A';  
            }

            if (wordChar != subChar || wordChar == '\0' || subChar == '\0') 
            {
                break;
            }
            iteratorK++;
        }

        if (*(substring + iteratorK) == '\0') 
        {
            printf("Substring '%s' found in word: %d\n", substring, iteratorI+1);
        }
    }

    for (int iteratorI = 0; iteratorI < 100; iteratorI++) 
    {
        free(*(words + iteratorI));
    }
    free(words);
}

int main()
{
    char *inputString = (char *)malloc(100 * sizeof(char));
    char *substring = (char *)malloc(20 * sizeof(char));

    printf("Enter Input String: \n");
    char character;
    int iteratorI = 0;
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(inputString + iteratorI) = character;
        iteratorI++;
    }
    *(inputString + iteratorI) = '\0';

    iteratorI = 0;
    printf("Enter Substring:\n");
    while ((character = getchar()) != '\n' && character != EOF) 
    {
        *(substring + iteratorI) = character;
        iteratorI++;
    }
    *(substring + iteratorI) = '\0';

    substringExist(inputString, substring);

    free(inputString);
    free(substring);

    return 0;
}
