#include <stdio.h>

const int SIZE = 10;

void transpose(int ar[][SIZE], int matrixsize);

int main()
{
    int ar[SIZE][SIZE];
    int matrixsize;
    printf("Enter the size of the matrix: ");
    scanf("%d", &matrixsize);
    for (int i = 0; i < matrixsize; i++)
    {
        printf("Enter data for row %d: ", i+1);
        for (int j = 0; j < matrixsize; j++)
        {
            scanf("%d", &ar[i][j]);
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < matrixsize; i++)
    {
        for (int j = 0; j < matrixsize; j++)
        {
            printf("%d  ", ar[i][j]);
        }
        printf("\n");
    }

    transpose(ar, matrixsize);
    
    printf("Transposed Matrix:\n");
    for (int i = 0; i < matrixsize; i++)
    {
        for (int j = 0; j < matrixsize; j++)
        {
            printf("%d  ", ar[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void transpose(int ar[][SIZE], int matrixsize)
{
    for (int i = 0; i < matrixsize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = ar[i][j];
            ar[i][j] = ar[j][i];
            ar[j][i] = temp;
        }
    }
    return;
}