// Use user-defined functions to perform the following operations on matrices:
/// a. Addition of two matrices.
#include <stdio.h>

void add_matrices(int row, int col, int arr1[row][col], int arr2[row][col])
{
    int i, j, sum[row][col];
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("\nSum matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int arr1[rows][cols], i, j;
    printf("\nMatrix 1:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element in (%d,%d): ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }

    int arr2[rows][cols];
    printf("\nMatrix 2:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element in (%d,%d): ", i + 1, j + 1);
            scanf("%d", &arr2[i][j]);
        }
    }
    add_matrices(rows, cols, arr1, arr2);
}
/// b. Multiplication of two matrices.
#include <stdio.h>

void prod_matrices(int row1, int col1, int arr1[row1][col1], int row2, int col2, int arr2[row2][col2])
{
    int i, j, k, prod[row1][col2];
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            prod[i][j] = 0;
            for (k = 0; k < col1; k++)
            {
                prod[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    int l, m;
    printf("\nProduct matrix:\n");
    for (l = 0; l < row1; l++)
    {
        for (m = 0; m < col2; m++)
        {
            printf("%d ", prod[l][m]);
        }
        printf("\n");
    }
}

void main()
{
    printf("Matrix 1:\n");
    int row1, col1;
    printf("Enter number of rows: ");
    scanf("%d", &row1);
    printf("Enter number of columns: ");
    scanf("%d", &col1);
    int arr1[row1][col1], i, j;
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("Enter element in (%d,%d): ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nMatrix 2:\n");
    int row2, col2;
    printf("Enter number of rows: ");
    scanf("%d", &row2);
    printf("Enter number of columns: ");
    scanf("%d", &col2);
    int arr2[row2][col2], k, l;
    for (k = 0; k < row2; k++)
    {
        for (l = 0; l < col2; l++)
        {
            printf("Enter element in (%d,%d): ", k + 1, l + 1);
            scanf("%d", &arr2[k][l]);
        }
    }
    prod_matrices(row1, col1, arr1, row2, col2, arr2);
}

/// c. Computation of transpose of a matrix.
#include <stdio.h>

void transpose_matrix(int row, int col, int arr1[row][col])
{
    int i, j, arr2[col][row];
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            arr2[i][j] = arr1[j][i];
        }
    }
    int k, l;
    printf("\nTransposed matrix:\n");
    for (k = 0; k < col; k++)
    {
        for (l = 0; l < row; l++)
        {
            printf("%d ", arr2[k][l]);
        }
        printf("\n");
    }
}

void main()
{
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int arr1[rows][cols], i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter element in (%d,%d): ", i + 1, j + 1);
            scanf("%d", &arr1[i][j]);
        }
    }
    transpose_matrix(rows, cols, arr1);
}