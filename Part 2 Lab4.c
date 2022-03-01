// Question 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sweepSpace1(char *str);
char *sweepSpace2(char *str);

int main()
{
    char str[80], str2[80],*p;
    printf("Enter the string:\n");
    fgets(str, 80, stdin);
    if (p=strchr(str,'\n')) *p='\0';
    strcpy(str2,str);
    printf("sweepSpace1(): %s\n", sweepSpace1(str));
    printf("sweepSpace2(): %s\n", sweepSpace2(str2));
    return 0;
}

char *sweepSpace1(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i]==' ')
        {
            for (int j = i; j < strlen(str); j++)
            {
                str[j] = str[j+1];
            }
        }
    }
    return str;
}
char *sweepSpace2(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i]==' ')
        {
            for (int j = i; j < strlen(str); j++)
            {
                *(str+j) = *(str+j+1);
            }
        }
    }
    return str;
}

// Question 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
#define INIT_VALUE 999


void printNames(char nameptr[][80], int size);
void readNames(char nameptr[][80], int *size);
int findTarget(char *target, char nameptr[][80], int size);


int main()
{
    char nameptr[SIZE][80], t[40], *p;
    int size, result = INIT_VALUE;
    int choice;

    printf("Select one of the following optinos: \n");
    printf("1: readNames()\n");
    printf("2: findTarget()\n");
    printf("3: printNames()\n");
    printf("4: exit()\n");
    do{
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                readNames(nameptr, &size);
                break;
            case 2:
                printf("Enter target name: \n");    
                scanf("\n");
                fgets(t, 80, stdin);
                if (p=strchr(t,'\n')) *p = '\0';  
                result = findTarget(t, nameptr, size);
                printf("findTarget(): %d\n",  result);   
                break;     
            case 3:
                printNames(nameptr, size);
                break;
        }
    } while (choice < 4);       
    return 0;
}


void printNames(char nameptr[][80], int size)
{
int i;
for (i=0; i<size; i++)  
    printf("%s ", nameptr[i]);
printf("\n");
}


void readNames(char nameptr[][80], int *size)
{
    printf("Enter size:\n");
    scanf("%d", size);
    printf("Enter %d names:\n", *size);
    for (int i = 0; i < *size; i++)
    {
        scanf("%s", &nameptr[i]);
    }
    return;
}


int findTarget(char *target, char nameptr[][80], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(target,nameptr[i])==0)
        {
            return i;
        }
    }
    return -1;
}