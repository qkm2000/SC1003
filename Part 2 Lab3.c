// Question 1

/*
#include <stdio.h>
#define INIT_VALUE -1000

int find(int size, int ar[], int target);
int main()
{
    int ar[20];
    int size, i, target, result = INIT_VALUE;
    printf("Enter array size: \n");
    scanf("%d", &size);   
    printf("Enter %d data: \n", size);
    for (i=0; i<=size-1; i++)   
        scanf("%d", &ar[i]);
    printf("Enter the target number: \n");
    scanf("%d", &target);    
    result = find(size, ar, target);
    if (result == -1)
        printf("find(): Not found\n");
    else  
        printf("find(): %d", result);
    return 0;
}

int find(int size, int ar[], int target)
{
    for (int i = 0; i<size-1; i++)
    {
        if (ar[i] == target)
        {
            return i;
        }
    }
    return -1;
}
*/

// Question 2
/*
#include <stdio.h>
#define SIZE 3
void swap2Rows(int ar[][SIZE], int r1, int r2);
void swap2Cols(int ar[][SIZE], int c1, int c2);
void display(int ar[][SIZE]);
int main()
{
    int array[SIZE][SIZE];
    int row1, row2, col1, col2;    
    int i,j;        
    int choice;
    
    printf("Select one of the following options: \n");
    printf("1: getInput()\n");      
    printf("2: swap2Rows()\n");
    printf("3: swap2Cols()\n");
    printf("4: display()\n");
    printf("5: exit()\n");  
    do 
    {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:  
                printf("Enter the matrix (3x3): \n");
                for (i=0; i<SIZE; i++)
                for (j=0; j<SIZE; j++)
                    scanf("%d", &array[i][j]);  D
                break;
            case 2:   
                printf("Enter two rows for swapping: \n");
                scanf("%d %d", &row1, &row2);     
                swap2Rows(array, row1, row2);
                printf("The new array is: \n");       
                display(array);
                break;
            case 3:   
                printf("Enter two columns for swapping: \n");       
                scanf("%d %d", &col1, &col2);
                swap2Cols(array, col1, col2);
                printf("The new array is: \n");       
                display(array);
                break;
            case 4:   
                display(array);
                break;
        }
    } while (choice < 5);  
    return 0;
}
void display(int ar[][SIZE])
{
    int l,m;
    for (l = 0; l < SIZE; l++) {
        for (m = 0; m < SIZE; m++)
            printf("%d ", ar[l][m]);
        printf("\n");
   }
}
void swap2Rows(int ar[][SIZE], int r1, int r2)
{
    for (int i = 0; i < SIZE-1; i++)
    {
        int temp = ar[r1-1][i];
        ar[r1-1][i] = ar[r2-1][i];
        ar[r2-1][i] = temp;
    }
    return;
}
void swap2Cols(int ar[][SIZE], int c1, int c2)
{
    for (int i = 0; i < SIZE-1; i++)
    {
        int temp = ar[i][c1-1];
        ar[i][c1-1] = ar[i][c2-1];
        ar[i][c2-1] = temp;
    }
    return;
}
*/


// Question 3 (optional)
#include <stdio.h>
void printReverse1(int ar[], int size);
void printReverse2(int ar[], int size);
void reverseAr1D(int ar[], int size);
int main()
{
    int ar[80];
    int size, i;
       
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i=0; i <= size-1; i++)
        scanf("%d", &ar[i]);
    printReverse1(ar, size);    
    printReverse2(ar, size);
    reverseAr1D(ar, size);
    printf("reverseAr1D()   = ");
    if (size > 0) {
        for (i=0; i<size; i++)
            printf("%d ", ar[i]);
    }
    return 0;
}    
void printReverse1(int ar[], int size)  
{
    printf("printReverse1() = ");
    for (int i = size-1; i >= 0; i--)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
    return;
}

void printReverse2(int ar[], int size)
{
    int *ptr = &ar[size-1];
    printf("printReverse2() = ");
    while (ptr > ar - 1)
    {
        printf("%d ", *ptr);
        ptr -= 1;
    }
    printf("\n");
    return;
}

void reverseAr1D(int ar[], int size)
{
    int *left = ar;
    int *right = &ar[size-1];
    while (left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;
        left ++;
        right --;
    }
    return;
}