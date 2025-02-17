// Problem Statement:
// Given a string s and an integer K, find the length of the longest substring that contains exactly K
// distinct characters. If no such substring exists, return -1.
// Input:
// • A string s of length N.
// • An integer K.
// Output:
// • An integer representing the length of the longest substring with exactly K distinct characters.
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
int stringLength(char *inputString)
{
    int iteratorI=0;
    while(*(inputString+iteratorI)!='\0')
    {
        iteratorI++;
    }
    return iteratorI;
}
int longestSubstringLength(char* inputString,int K)
{
    int maxLength=INT_MIN;
    int length=stringLength(inputString);
    int count[128]={0};
    int iteratorJ=0;
    int distinct=0;
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        if(count[(unsigned int)inputString[iteratorI]]==0)
        {
            distinct++;
        }
        count[(unsigned int)inputString[iteratorI]]++;
        while(distinct>K)
        {
            count[(unsigned int)inputString[iteratorJ]]--;
            if(count[(unsigned int)inputString[iteratorJ]]==0)
            {
                distinct--;
            }
            iteratorJ++;
        }
        if(distinct==K)
        {
            int currentLength=iteratorI-iteratorJ+1;
            if(maxLength<currentLength)
            {
                maxLength=currentLength;
            }
        }
    }
    return maxLength;
}
int main()
{
    char* inputString=(char*)malloc(200*sizeof(char));
    printf("Enter Input String \n");
    scanf("%s",inputString);
    int K;
    printf("Enter the value of K \n");
    scanf("%d",&K);
    int length=longestSubstringLength(inputString,K);
    printf("%d \n",length);
    return 0;
}