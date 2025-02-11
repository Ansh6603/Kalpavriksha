#include <stdio.h>
#include <stdlib.h>
int stringLength(char *str)
{
    int iteratorI = 0;
    while (*(str + iteratorI) != '\0')
    {
        iteratorI++;
    }
    return iteratorI;
}
char findNonRepeatingCharacter(char *str)
{
    int count[256] = {0};
    int length = stringLength(str);
    for (int iteratorI = 0; iteratorI < length; iteratorI++)
    {
        count[(unsigned char)str[iteratorI]]++;
    }
    for (int iteratorI = 0; iteratorI < length; iteratorI++)
    {
        if (count[(unsigned char)str[iteratorI]] == 1)
        {
            return str[iteratorI];
        }
    }
    return '\0';
}
int main()
{
    char str[100];
    printf("Enter a string \n");
    scanf("%s", str);
    char result = findNonRepeatingCharacter(str);
    if (result)
    {
        printf("%c \n", result);
    }
    else
    {
        printf("null \n");
    }
}