// Rotate the elements of a matrix by 90 degrees anticlockwise.
#include <stdio.h>

void main()
{
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    printf("Original Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }

    for (int i = 0; i < 3 / 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[2 - i][j];
            mat[2 - i][j] = temp;
        }
    }

    printf("Matrix after rotation:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}