#include <stdio.h>
#include <stdlib.h>

int isPalindrome(char *inputString, int stringLength) 
{
    int iteratorStart = 0, iteratorEnd = stringLength - 1;
    while (iteratorStart < iteratorEnd) 
    {
        if (inputString[iteratorStart] != inputString[iteratorEnd]) 
        {
            return 0;
        }
        iteratorStart++;
        iteratorEnd--;
    }
    return 1;
}

int main() 
{
    char *inputString;
    int stringLength;

    printf("Enter the length of the string: ");
    scanf("%d", &stringLength);

    inputString = (char *)malloc((stringLength + 1) * sizeof(char));

    printf("Enter the string: ");
    getchar();
    for (int iteratorI = 0; iteratorI < stringLength; iteratorI++) 
    {
        scanf("%c", &inputString[iteratorI]);
    }
    inputString[stringLength] = '\0';

    if (isPalindrome(inputString, stringLength)) 
    {
        printf("The string is a palindrome.\n");
    } 
    else 
    {
        printf("The string is not a palindrome.\n");
    }

    free(inputString);

    return 0;
}
