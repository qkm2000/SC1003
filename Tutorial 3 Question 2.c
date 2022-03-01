#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int collect(int N);
void print(int num[], int N);

int main()
{
    int N;
    int ar[100];
    int num[9];
    N = collect(N);
    
    // getting the numbers
    for (int i = 0; i < N; i++)
    {
        ar[i] = rand()%100;
    }

    /*
    // displaying numbers for debugging
    for (int i = 0; i < N; i++)
    {
        printf("ar[%d] = %d\n", i, ar[i]);
    }
    */

    // setting all num[i] values = 0
    for (int i = 0; i < 10; i++)
    {
        num[i] = 0;
    }

    // adding instances into num[i]
    for (int i = 0 ; i<N; i++)
    {
        // convert items into multiples of 10 and add into num[10]
        num[ar[i]/10]++;
    }
    print(num, N);
    return 0;
}


int collect(int N)
{
    printf("Enter the number of numbers :\n");
    scanf("%d", &N);
    return N;
}

void print(int num[], int N)
{
    //printf("0-9   |");
    for (int i = 0; i < 10; i++)
    {
        if (i==0)
        {
            printf("%d-%d     |", i*10, i*10+9);
        }
        else
        {
            printf("%d-%d   |", i*10, i*10+9);
        }
        for (int j = 0; j < num[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
