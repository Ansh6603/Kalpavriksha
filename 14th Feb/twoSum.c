#include<stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 100004
typedef struct
{
    int index;
    int num;
    int status;
}Element;


Element hashTable[TABLE_SIZE];

void init()
{
    for(int iteratorI=0;iteratorI<TABLE_SIZE;iteratorI++)
    {
        hashTable[iteratorI].status=0;
    }
}
int hashFunction(int data)
{
    return data%TABLE_SIZE;
}
void insert(int dataindex,int data)
{
    int index=hashFunction(data);
    int currIdx=index;
    while(hashTable[currIdx].status!=0)
    {
        currIdx=(currIdx+1)%TABLE_SIZE;
        if(currIdx==index)
        {
            return;
        }
    }
    hashTable[currIdx].num=data;
    hashTable[currIdx].index=dataindex;
    hashTable[currIdx].status=1;
}

int search(int data)
{
    int index=hashFunction(data);
    int currIdx=index;
    while(hashTable[currIdx].status!=0)
    {
        if(hashTable[currIdx].num==data && hashTable[currIdx].status==1)
        {
            return hashTable[currIdx].index;
        }
        if(currIdx==index)
        {
            return -1;
        }
    }
    return -1;
}
void printHashTable()
{
    for(int iteratorI = 0; iteratorI < TABLE_SIZE; iteratorI++)
    {
        if(hashTable[iteratorI].status == 1)
        {
            printf("Hash Index %d: %d, actual index %d\n", iteratorI, hashTable[iteratorI].num,hashTable[iteratorI].index);
        }
    }
}

void twoSum(int target)
{
    for(int iteratorI=0;iteratorI<TABLE_SIZE;iteratorI++)
    {
        if(hashTable[iteratorI].status==1)
        {
            int num1=hashTable[iteratorI].num;
            int num2=target-num1;
            int iteratorI1=hashTable[iteratorI].index;
            int iteratorI2 = search(num2);
            if (iteratorI2 != -1) {
                printf("%d, %d\n", iteratorI1, iteratorI2);
                return;
            }
        }
    }
    printf("Not found");
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        scanf("%d",&arr[iteratorI]);
    }
    for(int iteratorI=0;iteratorI<n;iteratorI++)
    {
        insert(iteratorI,arr[iteratorI]);
    }
    int target;
    scanf("%d",&target);
    twoSum(target);
}
