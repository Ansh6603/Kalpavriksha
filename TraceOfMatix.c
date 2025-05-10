#include<stdio.h>
#include<stdlib.h>

void readMatrix(int **matrix, int row, int col)
{
    for(int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for(int iteratorJ = 0; iteratorJ < col; iteratorJ++)
        {
            printf("Enter the value at (%d,%d): ", iteratorI + 1, iteratorJ + 1);
            scanf("%d", (*(matrix + iteratorI) + iteratorJ));
        }
        printf("\n");
    }
}

void diagonalSum(int **matrix, int row, int col)
{
    int diagonalSum = 0;
    int antiDiagonalSum = 0;
    int totalDiagonalSum = 0;

    for(int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        diagonalSum += *(*(matrix + iteratorI) + iteratorI);
        totalDiagonalSum += *(*(matrix + iteratorI) + iteratorI);

        antiDiagonalSum += *(*(matrix + iteratorI) + (col - 1 - iteratorI));
        if(iteratorI != (col - 1 - iteratorI)) 
        {
            totalDiagonalSum += *(*(matrix + iteratorI) + (col - 1 - iteratorI));
        }
    }

    printf("Diagonal Sum Of Matrix: %d\n", diagonalSum);
    printf("Ant Diagonal Sum of Matrix: %d\n", antiDiagonalSum);
    printf("Total Diagonal Sum Of Matrix: %d\n", totalDiagonalSum);
}

int main()
{
    int row, col;
    printf("Enter the row of Matrix\n");
    scanf("%d", &row);
    col = row;  

    int **matrix = (int **)malloc(row * sizeof(int *));
    for(int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        matrix[iteratorI] = (int *)malloc(col * sizeof(int));
    }

    readMatrix(matrix, row, col);
    diagonalSum(matrix, row, col);

    for(int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        free(matrix[iteratorI]);
    }
    free(matrix);

    return 0;
}
