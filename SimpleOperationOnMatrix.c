#include<stdio.h>
#include<stdlib.h>
void findSum(int **matrix,int row,int col)
{
    int sum=0;
    for(int iteratorI=0;iteratorI<row;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<col;iteratorJ++)
        {
            sum+=*(*(matrix+iteratorI)+iteratorJ);
        }
    }
    printf("Sum of All Elements of matrix : %d \n",sum);
}
void findRowSum(int **matrix,int row,int col)
{
    for(int iteratorI=0;iteratorI<row;iteratorI++)
    {
        int rowSum=0;
        for(int iteratorJ=0;iteratorJ<col;iteratorJ++)
        {
            rowSum+=*(*(matrix+iteratorI)+iteratorJ);
        }
        printf("Sum of Row %d Elements : %d \n",iteratorI+1,rowSum);
    }
}
void findColumnSum(int **matrix,int row,int col)
{
    for(int iteratorJ=0;iteratorJ<col;iteratorJ++)
    {
        int colSum=0;
        for(int iteratorI=0;iteratorI<row;iteratorI++)
        {
            colSum+=*(*(matrix+iteratorI)+iteratorJ);
        }
        printf("Sum of Column %d Elements : %d \n",iteratorJ+1,colSum);
    }
}
int main()
{
    int row, col;
    printf("Enter number of row:\n");
    scanf("%d", &row);
    printf("Enter number of column:\n");
    scanf("%d", &col);
    int **matrix = (int **)malloc(row*sizeof(int *));
    for (int iteratorI = 0; iteratorI < row;iteratorI++)
    {
        matrix[iteratorI] = (int *)malloc(col * sizeof(int));
    }
    printf("Enter values of matrix\n");
    for(int iteratorI=0;iteratorI<row;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<col;iteratorJ++)
        {
            printf("matrix[%d][%d]:\n",iteratorI+1,iteratorJ+1);
            scanf(" %d",&matrix[iteratorI][iteratorJ]);
        }
    }
    printf("Matrix : \n");
    for(int iteratorI=0;iteratorI<row;iteratorI++)
    {
        for(int iteratorJ=0;iteratorJ<col;iteratorJ++)
        {
            printf("%d ",matrix[iteratorI][iteratorJ]);
        }
        printf("\n");
    }
    findSum(matrix,row,col);
    findRowSum(matrix,row,col);
    findColumnSum(matrix,row,col);
    for(int iteratorI=0;iteratorI<row;iteratorI++)
    {
        free(matrix[iteratorI]);
    }
    free(matrix);
    return 0;
}