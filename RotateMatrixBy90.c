#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix, int N)
{
    for (int iteratorI = 0; iteratorI < N; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < N; iteratorJ++)
        {
            printf("Enter the value at (%d,%d)\n", iteratorI + 1, iteratorJ + 1);
            scanf("%d", &*(*(matrix + iteratorI) + iteratorJ));
        }
    }
}

void transposeMatrix(int **matrix, int N)
{
    for (int iteratorI = 0; iteratorI < N; iteratorI++)
    {
        for (int iteratorJ = iteratorI + 1; iteratorJ < N; iteratorJ++)
        {
            int *element1 = *(matrix + iteratorI) + iteratorJ;
            int *element2 = *(matrix + iteratorJ) + iteratorI;
            int tempValue = *element1;
            *element1 = *element2;
            *element2 = tempValue;
        }
    }
}

void inverseMatrix(int **matrix, int N)
{
    for (int iteratorI = 0; iteratorI < N; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < N / 2; iteratorJ++)
        {
            int *a = *(matrix + iteratorI) + iteratorJ;
            int *b = *(matrix + iteratorI) + (N - iteratorJ - 1);
            int tempValue = *a;
            *a = *b;
            *b = tempValue;
        }
    }
}

void printMatrix(int **matrix, int N)
{
    for (int iteratorI = 0; iteratorI < N; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < N; iteratorJ++)
        {
            printf("%d ", *(*(matrix + iteratorI) + iteratorJ));
        }
        printf("\n");
    }
}

int main()
{
    int N;
    printf("Enter size of N \n");
    scanf("%d", &N);

    int **matrix = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        matrix[i] = (int *)malloc(N * sizeof(int));
    }

    printf("Enter the matrix that need to be rotated \n");
    readMatrix(matrix, N);
    transposeMatrix(matrix, N);
    inverseMatrix(matrix, N);
    printf("The rotated matrix is: \n");
    printMatrix(matrix, N);

    for (int i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
