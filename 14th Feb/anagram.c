#include <stdio.h>

void sort(char str[])
{
    for (int iteratorI = 0; str[iteratorI] != '\0'; iteratorI++)
    {
        for (int iteratorJ = iteratorI + 1; str[iteratorJ] != '\0'; iteratorJ++)
        {
            if (str[iteratorI] > str[iteratorJ])
            {
                char temp = str[iteratorI];
                str[iteratorI] = str[iteratorJ];
                str[iteratorJ] = temp;
            }
        }
    }
}

int isAnagram(char str1[], char str2[])
{
    int iteratorI;
    for (iteratorI = 0; str1[iteratorI] != '\0'; iteratorI++)
    {
        if (str2[iteratorI] == '\0')
        {
            return 0;
        }
    }
    if (str2[iteratorI] != '\0')
    {
        return 0;
    }
    sort(str1);
    sort(str2);
    for (iteratorI = 0; str1[iteratorI] != '\0'; iteratorI++)
    {
        if (str1[iteratorI] != str2[iteratorI])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);
    if (isAnagram(str1, str2))
    {
        printf("Anagram\n");
    }
    else
    {
        printf("Not an Anagram\n");
    }
}
