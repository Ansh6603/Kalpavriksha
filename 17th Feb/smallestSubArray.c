// Problem Statement:
// Given an array arr, find the smallest contiguous subarray that contains all occurrences of the most
// frequent element.
// Input:
// • An integer array arr of size N.
// Output:
// • A pair of integers representing the start and end indices of the smallest subarray.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_SIZE 100001
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
void smallestSubArray(int* array,int *size)
{
    int count[MAX_SIZE]={0};
    int firstOccurence[MAX_SIZE];
    int lastOccurence[MAX_SIZE];
    for(int iteratorI=0;iteratorI<MAX_SIZE;iteratorI++)
    {
        firstOccurence[iteratorI]=-1;
        lastOccurence[iteratorI]=-1;
    }
    int startingIndex=0;
    int endingIndex=0;
    int maxFrequency=0;
    for(int iteratorI=0;iteratorI<*size;iteratorI++)
    {
        count[array[iteratorI]]++;
        if(firstOccurence[array[iteratorI]]==-1)
        {
            firstOccurence[array[iteratorI]]=iteratorI;
        }
        lastOccurence[array[iteratorI]]=iteratorI;
        if(count[array[iteratorI]]>maxFrequency)
        {
            maxFrequency=count[array[iteratorI]];
        }
    }
    int minLength=INT_MAX;
    for(int iteratorI=0;iteratorI<*size;iteratorI++)
    {
        if(maxFrequency==count[array[iteratorI]])
        {
            int start=firstOccurence[array[iteratorI]];
            int end=lastOccurence[array[iteratorI]];
            int length=end-start+1;
            if(length<minLength)
            {
                startingIndex=start;
                endingIndex=end;
                minLength=length;
            }
        }
    }
    printf("[%d,%d]",startingIndex,endingIndex);
}
int main()
{
    char* inputString=(char *)malloc(200*sizeof(char));
    printf("Enter Array Element \n");
    readInputString(inputString);
    int* array=(int *)malloc(200*sizeof(int));
    int size;
    convertStringIntoInteger(inputString,array,&size);
    smallestSubArray(array,&size);
    return 0;
}