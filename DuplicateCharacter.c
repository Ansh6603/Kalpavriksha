#include <stdio.h>
#include <stdlib.h>

void findDuplicateCharacters(char *word) 
{
    int frequency[256] = {0};
    int iteratorI = 0;

    while (*(word + iteratorI) != '\0') 
    {
        frequency[*(word + iteratorI)]++;
        iteratorI++;
    }

    printf("Duplicate characters:\n");
    int foundDuplicate = 0;

    for (iteratorI = 0; iteratorI < 256; iteratorI++) 
    {
        if (frequency[iteratorI] > 1) 
        {
            printf("%c occurs %d times\n", iteratorI, frequency[iteratorI]);
            foundDuplicate = 1;
        }
    }

    if (!foundDuplicate) 
    {
        printf("No duplicate characters found.\n");
    }
}

int main()
{
    char *word;
    int length;

    printf("Enter the length of the word: ");
    scanf("%d", &length);

    word = (char *)malloc((length + 1) * sizeof(char));

    printf("Enter the word: ");
    getchar();
    fgets(word, length + 1, stdin);

    for (int iteratorI = 0; *(word + iteratorI) != '\0'; iteratorI++)
    {
        if (*(word + iteratorI) == '\n') 
        {
            *(word + iteratorI) = '\0';
        }
    }

    findDuplicateCharacters(word);

    free(word);

    return 0;
}
