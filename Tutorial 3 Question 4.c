#include <stdio.h>
const int SIZE = 10;
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

    // adding up the columns
    for (int i = 0; i<matrixsize; i++)
    {
        int temp = 0;
        for (int j = 0; j < matrixsize; j++)
        {
            temp += ar[j][i];
        }
        ar[i][i] = temp;
    }

    // replacing the bottom half to 0
    for (int i = 0; i<matrixsize; i++)
    {
        for (int j = 0; j<i; j++)
        {
            ar[i][j] = 0;
        }
    }

    printf("Manipulated Matrix:\n");
    for (int i = 0; i < matrixsize; i++)
    {
        for (int j = 0; j < matrixsize; j++)
        {
            printf("%d  ", ar[i][j]);
        }
        printf("\n");
    }
}