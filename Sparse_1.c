#include <stdio.h>
void addSparse(int A[][3], int B[][3], int C[][3])
{
    int i = 1, j = 1, k = 1;

    if (A[0][0] != B[0][0] || A[0][1] != B[0][1])
    {
        printf("\nAddition not possible!\n");
        return;
    }
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    while (i <= A[0][2] && j <= B[0][2])
    {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1])
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
            k++;
        }
        else if ((A[i][0] < B[j][0]) ||
                 (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
            k++;
        }
        else
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
            k++;
        }
    }
    while (i <= A[0][2])
   {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }
    while (j <= B[0][2])
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }
    C[0][2] = k - 1;
    printf("\nResultant Sparse Matrix (Addition):\n");
    for (i = 0; i <= C[0][2]; i++)
        printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);
}
void transposeSparse(int A[][3], int T[][3])
{
    int rowTerms[20] = {0}, startPos[20];
    int i, j;
    int numCols = A[0][1];
    int numTerms = A[0][2];
    T[0][0] = A[0][1];
    T[0][1] = A[0][0];
    T[0][2] = numTerms;
    for (i = 1; i<=numTerms; i++)
        rowTerms[A[i][1]]++;
    startPos[0] = 1;
    for (i = 1; i < numCols; i++)
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];
    for (i = 1; i <= numTerms; i++)
    {
        j = startPos[A[i][1]]++;
        T[j][0] = A[i][1];
        T[j][1] = A[i][0];
        T[j][2] = A[i][2];
    }
    printf("\nTranspose of Sparse Matrix:\n");
    for (i = 0; i <= T[0][2]; i++)
        printf("%d %d %d\n", T[i][0], T[i][1], T[i][2]);
}
int main()
{
    int A[20][3], B[20][3], C[40][3], T[40][3];
    int i;

    printf("Enter rows, columns and non-zero elements of Matrix A: ");
    scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]);

    printf("Enter row column value:\n");
    for(i = 1; i <= A[0][2]; i++)
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);

    printf("\nEnter rows, columns and non-zero elements of Matrix B: ");
    scanf("%d %d %d", &B[0][0], &B[0][1], &B[0][2]);

    printf("Enter row column value:\n");
    for(i = 1; i <= B[0][2]; i++)
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);

    addSparse(A, B, C);

    transposeSparse(C, T);

    return 0;
}
