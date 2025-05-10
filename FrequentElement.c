#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VAL 1000

void readMatrix(int **matrix, int row, int col) 
{
    char line[100];
    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        printf("Enter row %d :\n", iteratorI + 1);
        fgets(line, sizeof(line), stdin);
        int num = 0;
        int iteratorJ = 0;
        int index = 0;

        while (line[index] != '\0' && iteratorJ < col)
        {
            if (line[index] >= '0' && line[index] <= '9') 
            {
                num = num * 10 + (line[index] - '0');
            } else if (line[index] == ' ' || line[index] == '\n') 
            {
                if (iteratorJ < col) 
                {
                    matrix[iteratorI][iteratorJ] = num;
                    iteratorJ++;
                }
                num = 0;
            }
            index++;
        }
    }
}

void mostFrequentElement(int **matrix, int row, int col) 
{
    int freq[MAX_VAL] = {0};
    int maxCount = 0;
    int maxValue = 0;

    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        for (int iteratorJ = 0; iteratorJ < col; iteratorJ++) 
        {
            int element = matrix[iteratorI][iteratorJ];
            freq[element]++;
            if (freq[element] > maxCount) 
            {
                maxCount = freq[element];
            }
        }
    }

    printf("Most Frequent Elements in Matrix with frequency %d: ", maxCount);
    for (int iteratorI = 0; iteratorI < MAX_VAL; iteratorI++) 
    {
        if (freq[iteratorI] == maxCount) 
        {
            printf("%d ", iteratorI);
        }
    }
    printf("\n");
}

int main() {
    int row, col;

    printf("Enter Row of Matrix: \n");
    scanf("%d", &row);
    printf("Enter Column of Matrix: \n");
    scanf("%d", &col);
    getchar();

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }

    readMatrix(matrix, row, col);
    mostFrequentElement(matrix, row, col);

    for (int i = 0; i < row; i++) 
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
