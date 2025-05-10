// Problem Statement:
// Given an array of integers arr of size N and an integer K, find the number of distinct elements in
// every contiguous subarray of size K.
// Input:
// • An integer array arr of size N.
// • An integer K (1 <= K <= N).
// Output:
// • A list of integers representing the number of distinct elements in each subarray of size K.
#include <stdio.h>
#include <stdlib.h>

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

void convertStringIntoInteger(char* inputString, int* array, int* size)
{
    int iteratorI = 0, iteratorJ = 0;
    while (*(inputString + iteratorI) != '\0') 
    {
        int currentNumber = 0, sign = 1;

        if (*(inputString + iteratorI) == '-') 
        {
            sign = -1;
            iteratorI++;
        }
        if (*(inputString + iteratorI) == ',') 
        {
            iteratorI++;
            continue;
        } 
        else if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
        {
            while (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
            {
                currentNumber = currentNumber * 10 + (*(inputString + iteratorI) - '0');
                iteratorI++;
            }
            *(array + iteratorJ) = currentNumber * sign;
            iteratorJ++;
        }
    }
    *size = iteratorJ;
}

void countDistinctElements(int* array, int K, int length) 
{
    int count[100000] = {0};
    int distinct = 0;

    for (int iteratorI = 0; iteratorI < K; iteratorI++) 
    {
        if (count[array[iteratorI]] == 0)
        {
            distinct++;
        }
        count[array[iteratorI]]++;
    }
    printf("%d ", distinct);

    for (int iteratorI = K; iteratorI < length; iteratorI++)
    {
        count[array[iteratorI - K]]--;
        if (count[array[iteratorI - K]] == 0) 
        {
            distinct--;
        }
        if (count[array[iteratorI]] == 0)
        {
            distinct++;
        }
        count[array[iteratorI]]++;

        printf("%d ", distinct);
    }
}

int main() 
{
    char* inputString = (char *)malloc(200 * sizeof(char));
    printf("Enter Array Elements: ");
    readInputString(inputString);

    int* array = (int *)malloc(200 * sizeof(int));
    int size;
    convertStringIntoInteger(inputString, array, &size);

    int K;
    printf("Enter value of K: ");
    scanf("%d", &K);

    countDistinctElements(array, K, size);
    
    free(inputString);
    free(array);
    return 0;
}
