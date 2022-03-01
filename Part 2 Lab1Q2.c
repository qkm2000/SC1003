#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value = 0, sum = 0, counter, numlines;
    float avg;
    printf("Enter number of lines: \n");
    scanf("%d", &numlines);
    for (int i =0; i < numlines; i++)
    {
        sum = 0; counter = 0;
        printf("Enter line %d\n", i+1);
        scanf("%d", &value);
        while (value != -1)
        {
            sum = sum + value;
            counter++;
            scanf("%d", &value);
        }
        avg = (float)sum/(float)counter;
        printf("avg = %.2f\n", avg);
    }
}
