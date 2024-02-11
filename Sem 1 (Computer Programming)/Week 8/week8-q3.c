// Write a program in C multiply two matrices
#include <stdio.h>

void multiplyMatrices(int A[3][2], int B[2][4], int result[3][4])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int mat1[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    int mat2[2][4] = {
        {7, 8, 9, 10},
        {11, 12, 13, 14}};

    int resmat[3][4];

    multiplyMatrices(mat1, mat2, resmat);

    printf("Matrix A:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    printf("\nResult Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", resmat[i][j]);
        }
        printf("\n");
    }
}