#include<stdio.h>
#include<stdlib.h>

void readMatrix(int **matrix, int row, int col) 
{
    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        for (int iteratorJ = 0; iteratorJ < col; iteratorJ++) 
        {
            printf("Enter the value at (%d,%d) :\n", iteratorI + 1, iteratorJ + 1);
            scanf("%d", (*(matrix + iteratorI) + iteratorJ));
        }
    }
}

void binarySearch(int *arr, int low, int high, int value)
{
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        if (arr[mid] == value) 
        {
            printf("Value %d is found at index %d \n", value, mid);
            return;
        } 
        else if (arr[mid] < value) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    printf("Value %d not found in the row\n", value);
}

void searchMatrix(int **matrix, int row, int col, int value) 
{
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        printf("Searching in row %d:\n", iteratorI + 1);
        binarySearch(matrix[iteratorI], 0, col - 1, value);
    }
}

void sortMatrix(int **matrix, int row, int col)
{
    int *tempArray = (int *)malloc(row * col * sizeof(int));
    int iteratorK = 0;

    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        for (int iteratorJ = 0; iteratorJ < col; iteratorJ++) 
        {
            *(tempArray + iteratorK) = *(*(matrix + iteratorI) + iteratorJ);
            iteratorK++;
        }
    }

    for (int iteratorI = 0; iteratorI < row * col - 1; iteratorI++) 
    {
        for (int iteratorJ = iteratorI + 1; iteratorJ < row * col; iteratorJ++) 
        {
            if (*(tempArray + iteratorI) > *(tempArray + iteratorJ)) 
            {
                int tempValue = *(tempArray + iteratorI);
                *(tempArray + iteratorI) = *(tempArray + iteratorJ);
                *(tempArray + iteratorJ) = tempValue;
            }
        }
    }

    iteratorK = 0;
    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        for (int iteratorJ = 0; iteratorJ < col; iteratorJ++)
        {
            *(*(matrix + iteratorI) + iteratorJ) = *(tempArray + iteratorK);
            iteratorK++;
        }
    }

    printf("\nSorted Matrix:\n");
    for (int iteratorI = 0; iteratorI < row; iteratorI++)
    {
        for (int iteratorJ = 0; iteratorJ < col; iteratorJ++) 
        {
            printf("%d ", *(*(matrix + iteratorI) + iteratorJ));
        }
        printf("\n");
    }

    free(tempArray);
}

int main() 
{
    int row, col;
    printf("Enter number of rows :\n");
    scanf("%d", &row);
    printf("Enter number of columns :\n");
    scanf("%d", &col);

    int **matrix = (int **)malloc(row * sizeof(int *));
    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        *(matrix + iteratorI) = (int *)malloc(col * sizeof(int));
    }

    readMatrix(matrix, row, col);

    int value;
    printf("Enter the value you want to search in matrix: \n");
    scanf("%d", &value);

    sortMatrix(matrix, row, col);
    searchMatrix(matrix, row, col, value);

    for (int iteratorI = 0; iteratorI < row; iteratorI++) 
    {
        free(matrix[iteratorI]);
    }
    free(matrix);

    return 0;
}
