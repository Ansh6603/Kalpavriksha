// Problem Statement:
// Given an array of integers arr and an integer K, determine if it is possible to pair all elements of the
// array such that the sum of every pair is divisible by K.
// Input:
// • An integer array arr and an integer K.
// Output:
// • A boolean value (true or false).
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
void readInputString(char* inputString)
{
    int iteratorI=0;
    char character;
    while((character=getchar())!='\n' && character!=EOF)
    {
        *(inputString+iteratorI)=character;
        iteratorI++;
    }
    *(inputString+iteratorI)='\0';
}
bool pairDivisibility(int* array,int K,int length)
{
    int freq[K];
    for(int iteratorI=0;iteratorI<K;iteratorI++)
    {
        freq[iteratorI]=0;
    }
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        freq[array[iteratorI]%K]++;
    }
    for(int iteratorI=0;iteratorI<K;iteratorI++)
    {
        if(iteratorI==0)
        {
            if(freq[iteratorI]%2!=0)
            {
                return false;
            }
        }
        else if(2*iteratorI==K)
        {
            if(freq[iteratorI]%2!=0)
            {
                return false;
            }
        }
        else
        {
            if(freq[iteratorI]!=freq[K-iteratorI])
            {
                return false;
            }
        }
    }
    return true;
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
int main()
{
    char* inputString=(char *)malloc(200*sizeof(char));
    printf("Enter Array \n");
    readInputString(inputString);
    int* array = (int *)malloc(200 * sizeof(int));
    int size;
    convertStringIntoInteger(inputString, array, &size);
    int K;
    printf("Enter value of K \n");
    scanf("%d",&K);
    if(pairDivisibility(array,K,size))
    {
        printf("True \n");
    }
    else
    {
        printf("False \n");
    }
    return 0;
}