// Problem Statement:
// Given an integer array arr and an integer K, return the number of subarrays that contain exactly K
// different integers.
// Input:
// • An integer array arr of size N.
// • An integer K.
// Output:
// • An integer representing the number of subarrays with exactly K distinct integers.
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
int longestSubArray(int* array,int K,int length)
{
    int maxLength=0;
    int iteratorJ=0;
    int count[128]={0};
    int distinct=0;
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        if(count[(unsigned int)array[iteratorI]]==0)
        {
            distinct++;
        }
        count[(unsigned int)array[iteratorI]]++;
        while(distinct>K)
        {
            count[(unsigned int)array[iteratorJ]]--;
            if(count[(unsigned int)array[iteratorJ]]==0)
            {
                distinct--;
            }
            iteratorJ++;
        }
        maxLength+=iteratorI-iteratorJ+1;
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
    int K;
    printf("Enter value of K \n");
    scanf("%d",&K);
    int count=longestSubArray(array,K,size)-longestSubArray(array,K-1,size);
    printf("%d",count);
    return 0;
}