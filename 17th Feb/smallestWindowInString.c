// Problem Statement:
// Given two strings s and t, return the minimum window substring of s that contains all the characters
// of t. If no such substring exists, return an empty string.
// Input:
// • A string s and a string t.
// Output:
// • A string representing the smallest window.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
int stringLength(char *inputString)
{
    int iteratorI=0;
    while(*(inputString+iteratorI)!='\0')
    {
        iteratorI++;
    }
    return iteratorI;
}
void smallestWindow(char* inputString1,char* inputString2)
{
    int countT[128]={0};
    int length1=stringLength(inputString1);
    int length2=stringLength(inputString2);
    if(length1<length2)
    {
        printf("No Window possible");
        return ;
    }
    for(int iteratorI=0;iteratorI<length2;iteratorI++)
    {
        countT[(unsigned char)inputString2[iteratorI]]++;
    }
    int iteratorJ=0;
    int minLength=INT_MAX;
    int countS[128]={0};
    int startingIndex=-1;
    int count=0;
    for(int iteratorI=0;iteratorI<length1;iteratorI++)
    {
        countS[(unsigned char)inputString1[iteratorI]]++;
        if (countT[(unsigned char)inputString1[iteratorI]] > 0 &&
            countS[(unsigned char)inputString1[iteratorI]] <= countT[(unsigned char)inputString1[iteratorI]])
        {
            count++;
        }
        while(count==length2)
        {
            if(minLength>iteratorI-iteratorJ+1)
            {
                minLength=iteratorI-iteratorJ+1;
                startingIndex=iteratorJ;
            }
            countS[(unsigned char)inputString1[iteratorJ]]--;
            if (countT[(unsigned char)inputString1[iteratorJ]] > 0 &&
                countS[(unsigned char)inputString1[iteratorJ]] < countT[(unsigned char)inputString1[iteratorJ]])
            {
                count--;
            }
            iteratorJ++;
        }
    }
    if(startingIndex==-1)
    {
        printf("No Window possible \n");
    }
    else
    {
        for(int iteratorI=startingIndex;iteratorI<startingIndex+minLength;iteratorI++)
        {
            printf("%c",inputString1[iteratorI]);
        }
        printf("\n");
    }
}
int main()
{
    char* inputString1=(char *)malloc(200*sizeof(char));
    printf("Enter Input String 1 \n");
    readInputString(inputString1);
    char* inputString2=(char *)malloc(200*sizeof(char));
    printf("Enter Input String 2 \n");
    readInputString(inputString2);
    smallestWindow(inputString1, inputString2);

    free(inputString1);
    free(inputString2);

    return 0;
}