#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSymmetric(int **matrix, int n)
{
    for (int iteratorI = 0; iteratorI < n; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < n; iteratorJ++)
        {
            if (matrix[iteratorI][iteratorJ] != matrix[iteratorJ][iteratorI])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int row, col;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &row);
    col = row;

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        matrix[iteratorI] = (int *)malloc(col * sizeof(int));
    }

    printf("Enter elements of the matrix:\n");
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < col; iteratorJ++)
        {
            printf("Enter element at (%d, %d): ", iteratorI + 1, iteratorJ + 1);
            scanf("%d", &matrix[iteratorI][iteratorJ]);
        }
    }

    if (isSymmetric(matrix, row))
    {
        printf("The matrix is symmetric.\n");
    }
    else
    {
        printf("The matrix is not symmetric.\n");
    }

    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        free(matrix[iteratorI]);
    }
    free(matrix);

    return 0;
}
