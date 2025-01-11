#include <stdio.h>
#include <stdlib.h>
void readInputString(char *inputString)
{
    int iteratorI = 0;
    char character;
    while ((character = getchar()) != '\n' && character != EOF)
    {
        inputString[iteratorI++] = character;
    }
    inputString[iteratorI] = '\0';
}
int stringLength(char *inputString)
{
    int length = 0;
    while (inputString[length] != '\0')
    {
        length++;
    }
    return length;
}
int countRow(char *inputString, int length)
{
    int row = 0;
    for (int i = 1; i < length - 1; i++)
    {
        if (inputString[i] == '[')
        {
            while (i < length && inputString[i] != ']')
            {
                i++;
            }
            if (inputString[i] == ']')
            {
                row++;
            }
        }
    }
    return row;
}
int countCol(char *inputString, int length)
{
    int col = 0;
    for (int i = 0; i < length; i++)
    {
        if (inputString[i] == '[')
        {
            while (i < length && inputString[i] != ']')
            {
                if (inputString[i] == ' ')
                {
                    col++;
                }
                i++;
            }
            col++;
            break;
        }
    }
    return col;
}
void numberFromString(int *array, int length, char *inputString)
{
    int iteratorJ = 0;
    for (int iteratorI = 0; iteratorI < length; iteratorI++)
    {
        if ((inputString[iteratorI] >= '0' && inputString[iteratorI] <= '9') || (inputString[iteratorI] == '-' && inputString[iteratorI + 1] >= '0' && inputString[iteratorI] <= '9'))
        {
            int currentNumber = 0;
            int sign = 1;
            if (inputString[iteratorI] == '-')
            {
                sign = -1;
                iteratorI++;
            }
            while (iteratorI < length && (inputString[iteratorI] >= '0' && inputString[iteratorI] <= '9'))
            {
                currentNumber = currentNumber * 10 + (inputString[iteratorI] - '0');
                iteratorI++;
            }
            array[iteratorJ++] = sign * currentNumber;
        }
    }
}
void fillMatrix(int matrix[100][100], int row, int col, int *array)
{
    int iteratorI = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = array[iteratorI++];
        }
    }
}
int main()
{
    char inputString[200];
    readInputString(inputString);
    int length = stringLength(inputString);
    int rowCount = countRow(inputString, length);
    int colCount = countCol(inputString, length);
    int array[200];
    numberFromString(array, length, inputString);
    int matrix[100][100];
    fillMatrix(matrix, rowCount, colCount, array);
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            printf("%d ", matrix[i][j]);
        }
    }
}