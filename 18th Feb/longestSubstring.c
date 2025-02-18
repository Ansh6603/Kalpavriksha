#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
int stringLength(char* inputString)
{
    int iteratorI=0;
    while(*(inputString+iteratorI)!='\0')
    {
        iteratorI++;
    }
    return iteratorI;
}
int longestSubstring(char* inputString,int K)
{
    int length=stringLength(inputString);
    int distinct=0;
    int count[128]={0};
    int iteratorJ=0;
    int maxLength=INT_MIN;
    for(int iteratorI=0;iteratorI<length;iteratorI++)
    {
        if(count[(unsigned char)inputString[iteratorI]]==0)
        {
            distinct++;
        }
        count[(unsigned char)inputString[iteratorI]]++;
        while(distinct>K)
        {
            count[(unsigned char)inputString[iteratorJ]]--;
            if(count[(unsigned char)inputString[iteratorI]]==0)
            {
                distinct--;
            }
            iteratorJ++;
        }
        if(distinct==K)
        {
            int length=iteratorI-iteratorJ+1;
            if(maxLength<length)
            {
                maxLength=length;
            }
        }
    }
    return maxLength;
}
int main()
{
    char* inputString=(char *)malloc(200*sizeof(char));
    printf("Enter string \n");
    readInputString(inputString);
    int K;
    printf("Enter value of K \n");
    scanf("%d",&K);
    int longest=longestSubstring(inputString,K);
    printf("%d",longest);
    return 0;
}