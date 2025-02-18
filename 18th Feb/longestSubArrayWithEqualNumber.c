// Problem Statement:
// Given a binary array arr (containing only 0s and 1s), find the length of the longest contiguous
// subarray with an equal number of 0s and 1s.
// Input:
// • An integer array arr containing only 0s and 1s.
// Output:
// Example:
// Input: arr = [0, 1, 0, 1, 0, 0, 1, 1]
// Output: 6
// • An integer representing the length of the longest subarray.
#include <stdio.h>
#include <stdlib.h>

void readInputString(char* inputString)
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

int findMaxLength(int* arr, int size)
{
    int maxLength = 0;
    int cumulativeSum = 0;
    int* hashMap = (int*)malloc((2 * size + 1) * sizeof(int));

    for (int iteratorI = 0; iteratorI < 2 * size + 1; iteratorI++)
    {
        hashMap[iteratorI] = -2;
    }

    for (int iteratorI = 0; iteratorI < size; iteratorI++)
    {
        cumulativeSum += (arr[iteratorI] == 0) ? -1 : 1;
        int index = cumulativeSum + size;

        if (hashMap[index] == -2)
        {
            hashMap[index] = iteratorI;
        }
        else
        {
            int length = iteratorI - hashMap[index];
            if (length > maxLength)
            {
                maxLength = length;
            }
        }
    }

    free(hashMap);
    return maxLength;
}

int main()
{
    char* inputString = (char*)malloc(200 * sizeof(char));
    printf("Enter Array: \n");
    readInputString(inputString);

    int* array = (int*)malloc(200 * sizeof(int));
    int size;
    convertStringIntoInteger(inputString, array, &size);

    int length = findMaxLength(array, size);
    printf("Longest Subarray with Equal 0s and 1s: %d\n", length);

    free(inputString);
    free(array);
    
    return 0;
}
