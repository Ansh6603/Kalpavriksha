#include <stdio.h>
#include <string.h>
#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LEN 50

int isVowel(char character)
{
    if (character >= 'A' && character <= 'Z')
    {
        character = character + 32;
    }
    return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u');
}

int stringLength(char inputString[])
{
    int stringLength = 0;
    while (inputString[stringLength] != '\0')
    {
        stringLength++;
    }
    return stringLength;
}

void stringCopy(char finalString[], char inputString[])
{
    int iteratorI = 0;
    while (inputString[iteratorI] != '\0')
    {
        finalString[iteratorI] = inputString[iteratorI];
        iteratorI++;
    }
    finalString[iteratorI] = '\0';
}

int main()
{
    int row, column;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LEN + 1];
    int countVowel = 0;
    char longestNames[MAX_ROWS * MAX_COLS][MAX_NAME_LEN + 1];
    int longestLength = 0;
    int longestCount = 0;

    printf("Enter number of rows :");
    scanf("%d", &row);
    if (row < 1 || row > 10)
    {
        printf("Invalid input for rows.\n");
        return 1;
    }

    printf("Enter number of columns :");
    scanf("%d", &column);
    if (column < 1 || column > 101)
    {
        printf("Invalid input for columns.\n");
        return 1;
    }

    printf("Enter the names:\n");
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column; iteratorJ++)
        {
            printf("Name at (%d,%d): ", iteratorI, iteratorJ);
            scanf("%s", names[iteratorI][iteratorJ]);
        }
    }

    printf("The 2D array of names is:\n");
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column; iteratorJ++)
        {
            printf("%s ", names[iteratorI][iteratorJ]);
        }
        printf("\n");
    }

    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < column; iteratorJ++)
        {
            if (isVowel(names[iteratorI][iteratorJ][0]))
            {
                countVowel++;
            }

            int currentLength = stringLength(names[iteratorI][iteratorJ]);
            if (currentLength > longestLength)
            {
                longestLength = currentLength;
                longestCount = 0;
                stringCopy(longestNames[longestCount], names[iteratorI][iteratorJ]);
                longestCount++;
            }
            else if (currentLength == longestLength)
            {
                stringCopy(longestNames[longestCount], names[iteratorI][iteratorJ]);
                longestCount++;
            }
        }
    }

    printf("Number of names starting with a vowel: %d\n", countVowel);
    printf("The longest names:\n");
    for (int iteratorI = 0; iteratorI < longestCount; iteratorI++)
    {
        printf("%s\n", longestNames[iteratorI]);
    }

    return 0;
}