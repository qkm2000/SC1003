#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char name[20];
    int telno; //5 digit int
} phonebook;

void print (phonebook list[], int size);
int  readin(phonebook list[]);
void search(phonebook list[], int size, char *target);

int main()
{
    phonebook list[100];
    char t[20], *p;
    int size = 0, choice;
    printf("Select one of the following options: \n");
    printf("1. readin()\n");
    printf("2. search()\n");
    printf("3. printf()\n");
    printf("4. exit()\n");
    do {
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        getchar();
        switch (choice)
        {
        case 1:
            size = readin(list); // use fgets
            continue;
        case 2:
            if (size == 0)
            {
                printf("Empty Phonebook\n");
                continue;
            }
            printf("Enter search name:\n");
            fgets(t, 20, stdin);
            if (p=strchr(t,'\n')) *p = '\0';
            search(list, size, t);
            continue;
        case 3:
            print(list, size);
            continue;
        case 4:
            printf("Thank you for using the program\n");
            continue;
        default:
            printf("Invalid choice\n");
            continue;
        }
    } while(choice != 4);
    return 0;
}


void print (phonebook list[], int size)
{
    if (size == 0)
    {
        printf("Empty Phonebook\n");
        return;
    }
    for (int i = 0; i < size; i ++)
    {
        printf("Name: %s   telno: %d\n", list[i].name, list[i].telno);
    }
    return;
}


int readin(phonebook list[])
{
    int size = 0;
    char tempname[20], *p;
    int temptel;
    while (1)
    {
        printf("Enter name: \n");
        fgets(tempname, 20, stdin);
        if (p=strchr(tempname,'\n')) *p = '\0';
        if (strcmp(tempname,"#")==0)
        {
            return size;
        }
        strcpy(list[size].name, tempname);
        printf("Enter telno: \n");
        scanf("%d", &temptel);
        getchar();
        list[size].telno = temptel;
        size += 1;
    }
    return size;
}


void search(phonebook list[], int size, char *target)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(list[i].name,target)==0)
        {
            printf("Name: %s   telno: %d\n", list[i].name, list[i].telno);
            return;
        }
    }
    printf("Not found\n");
    return;
}