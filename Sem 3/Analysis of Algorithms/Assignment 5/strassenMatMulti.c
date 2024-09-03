// Q2: Strassen's Matrix Multiplication
#include <stdio.h>
#include <stdlib.h>

int **alloc_mat(int n)
{
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    return mat;
}

void add_mats(int n, int **A, int **B, int **C)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub_mats(int n, int **A, int **B, int **C)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

int **strassen(int n, int **A, int **B)
{
    if (n == 1)
    {
        int **C = alloc_mat(1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n / 2;
    int **C = alloc_mat(n);
    int **A11 = alloc_mat(k), **A12 = alloc_mat(k), **A21 = alloc_mat(k), **A22 = alloc_mat(k);
    int **B11 = alloc_mat(k), **B12 = alloc_mat(k), **B21 = alloc_mat(k), **B22 = alloc_mat(k);
    int **S1 = alloc_mat(k), **S2 = alloc_mat(k), **S3 = alloc_mat(k), **S4 = alloc_mat(k);
    int **S5 = alloc_mat(k), **S6 = alloc_mat(k), **S7 = alloc_mat(k), **S8 = alloc_mat(k);
    int **S9 = alloc_mat(k), **S10 = alloc_mat(k);
    int **P1, **P2, **P3, **P4, **P5, **P6, **P7;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    sub_mats(k, B12, B22, S1);
    add_mats(k, A11, A12, S2);
    add_mats(k, A21, A22, S3);
    sub_mats(k, B21, B11, S4);
    add_mats(k, A11, A22, S5);
    add_mats(k, B11, B22, S6);
    sub_mats(k, A12, A22, S7);
    add_mats(k, B21, B22, S8);
    sub_mats(k, A11, A21, S9);
    add_mats(k, B11, B12, S10);

    P1 = strassen(k, A11, S1);
    P2 = strassen(k, S2, B22);
    P3 = strassen(k, S3, B11);
    P4 = strassen(k, A22, S4);
    P5 = strassen(k, S5, S6);
    P6 = strassen(k, S7, S8);
    P7 = strassen(k, S9, S10);

    int **C11 = alloc_mat(k), **C12 = alloc_mat(k), **C21 = alloc_mat(k), **C22 = alloc_mat(k);
    int **temp1 = alloc_mat(k), **temp2 = alloc_mat(k);

    add_mats(k, P5, P4, temp1);
    sub_mats(k, temp1, P2, temp2);
    add_mats(k, temp2, P6, C11);

    add_mats(k, P1, P2, C12);

    add_mats(k, P3, P4, C21);

    add_mats(k, P5, P1, temp1);
    sub_mats(k, temp1, P3, temp2);
    sub_mats(k, temp2, P7, C22);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    free(A11), free(A12), free(A21), free(A22);
    free(B11), free(B12), free(B21), free(B22);
    free(S1), free(S2), free(S3), free(S4), free(S5), free(S6), free(S7), free(S8), free(S9), free(S10);
    free(P1), free(P2), free(P3), free(P4), free(P5), free(P6), free(P7);
    free(C11), free(C12), free(C21), free(C22);
    free(temp1), free(temp2);

    return C;
}

void main()
{
    int n, i, j, value;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    int **arr1 = alloc_mat(n), **arr2 = alloc_mat(n), **out;

    printf("\nFor matrix 1:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element: ");
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("\nFor matrix 2:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element: ");
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nThe first matrix is: ");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%d\t", arr1[i][j]);
    }
    printf("\n\nThe second matrix is: ");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%d\t", arr2[i][j]);
    }

    out = strassen(n, arr1, arr2);

    printf("\n\nProduct achieved using Strassen's algorithm: ");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%d\t", out[i][j]);
    }
    printf("\n");
}
