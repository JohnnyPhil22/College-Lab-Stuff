// Check whether the given matrix is Sparse matrix or not.
#include <stdio.h>

void main()
{
    int row, col;
    printf("Enter number of rows and columns in matrix: ");
    scanf("%d %d", &row, &col);

    int arr[row][col], i, j, elem;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter element: ");
            scanf("%d", &elem);
            arr[i][j] = elem;
        }
    }

    int count0, countn0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
            {
                count0++;
            }
            else
            {
                countn0++;
            }
        }
    }

    if (count0 > countn0)
    {
        printf("It is sparse matrix\n");
    }
    else
    {
        printf("It is not a sparse matrix\n");
    }
}