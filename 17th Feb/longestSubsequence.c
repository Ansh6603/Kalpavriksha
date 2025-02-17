// Problem Statement:
// Given an unsorted array of integers arr, find the length of the longest subsequence where the
// elements form a consecutive sequence (not necessarily contiguous).
// Input:
// • An integer array arr.
// Output:
// • An integer representing the length of the longest consecutive subsequence.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void readInputString(char *inputString)
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
void convertStringIntoInteger(char* inputString,int* array,int* size)
{
    int iteratorI=0;
    int iteratorJ=0;
    while(*(inputString+iteratorI)!='\0')
    {
        int currentNumber=0;
        int sign=1;
        if(*(inputString+iteratorI)=='-')
        {
            sign=-1;
            iteratorI++;
        }
        if(*(inputString+iteratorI)==',')
        {
            iteratorI++;
            continue;
        }
        else if(*(inputString+iteratorI)>='0' && *(inputString+iteratorI)<='9')
        {
            while(*(inputString+iteratorI)>='0' && *(inputString+iteratorI)<='9')
            {
                currentNumber=currentNumber*10+(*(inputString+iteratorI)-'0');
                iteratorI++;
            }
            *(array+iteratorJ)=currentNumber*sign;
            iteratorJ++;
        }
    }
    *size=iteratorJ;
}
void bubbleSort(int* array,int* size)
{
    for(int iteratorI=0;iteratorI<*size-1;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<*size-iteratorI-1;iteratorJ++)
        {
            if(*(array+iteratorJ)>*(array+iteratorJ+1))
            {
                int temp=array[iteratorJ];
                array[iteratorJ]=array[iteratorJ+1];
                array[iteratorJ+1]=temp;
            }
        }
    }
}
int longestSubsequence(int* array,int* size)
{
    int maxLength=1;
    int length=1;
    bubbleSort(array,size);
    for(int iteratorI=1;iteratorI<*size;iteratorI++)
    {
        if(array[iteratorI]==array[iteratorI-1])
        {
            continue;
        }
        if(array[iteratorI]==array[iteratorI-1]+1)
        {
            length++;
        }
        else
        {
            if(maxLength<length)
            {
                maxLength=length;
            }
            length=1;
        }
    }
    if(maxLength<length)
    {
        maxLength=length;
    }
    return maxLength;
}
int main()
{
    char* inputString=(char *)malloc(200*sizeof(char));
    printf("Enter Array Element \n");
    readInputString(inputString);
    int* array=(int *)malloc(200*sizeof(int));
    int size;
    convertStringIntoInteger(inputString,array,&size);
    int length=longestSubsequence(array,&size);
    printf("%d",length);
    return 0;
}