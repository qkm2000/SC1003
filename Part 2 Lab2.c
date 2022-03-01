#include <stdio.h>
int  numDigits1(int num);
void numDigits2(int num, int *result);
int  digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int  square1(int num);
void square2(int num, int *result);

int main()
{
    int choice;
    int number, digit, result = 0;
    do{
        printf("\nPerform the following functions ITERATIVELY:\n");
        printf("1:  numDigits1()\n");
        printf("2:  numDigits2()\n");
        printf("3:  digitPos1()\n");
        printf("4:  digitPos2()\n");
        printf("5:  square1()\n");
        printf("6:  square2()\n");
        printf("7:  quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
        case 1: // numDigits1
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("numDigits1(): %d\n", numDigits1(number));
            continue;
        case 2: // numDigits2
            printf("Enter the number: \n");
            scanf("%d", &number);
            numDigits2(number,&result);
            printf("numDigits2(): %d\n", result);
            continue;
        case 3: // digitPos1
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("Enter the digit: \n");
            scanf("%d", &digit);
            printf("digitPos1(): %d\n", digitPos1(number, digit));
            continue;
        case 4: // digitPos2
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("Enter the digit: \n");
            scanf("%d", &digit);
            digitPos2(number, digit, &result);
            printf("digitPos2(): %d\n", result);
            continue;
        case 5: // square1
            printf("Enter the number: \n");
            scanf("%d", &number);
            printf("square1(): %d\n", square1(number));
            continue;
        case 6: // square2
            printf("Enter the number: \n");
            scanf("%d", &number);
            square2(number, &result);
            printf("square2(): %d\n", result);
            continue;
        case 7: // quit
            return 0;
        }
    } while (choice < 7);
    return 0;
}


int numDigits1(int num)
{
    int count = 0;
    while (num!=0)
    {
        count++;
        num = num/10;
    }
    return count;
}

void numDigits2(int num, int *result)
{
    *result = 0;
    while (num!=0)
    {
        *result+=1;
        num = num/10;
    }
    return;

}

int digitPos1(int num, int digit)
{
    int count = 0;
    while (num != 0)
    {
        if (num%10 == digit)
        {
            count += 1;
            return count;
        }
        count += 1;
        num = num/10;
    }
    return 0;
}

void digitPos2(int num, int digit, int *result)
{
    *result = 0;
    while (num != 0)
    {
        if (num%10 == digit)
        {
            *result += 1;
            return;
        }
        *result += 1;
        num = num/10;
    }
    *result = 0;
    return;
}

int square1(int num)
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        count += (2*i+1);
    }
    return count;
}

void square2(int num, int *result)
{
    *result = 0;
    for (int i = 0; i < num; i++)
    {
        *result += (2*i+1);
    }
    return;
}
