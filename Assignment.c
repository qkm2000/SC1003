	/*edit*/

/*custom header*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

	/*end_edit*/
	/*edit*/
/* Write your code here */
typedef struct
{
    int id;
    char pname[20];
    char cname[20];
} card;

void listNameCards(card list[], int count);
void addNameCard(card list[], int *count);
void removeNameCard(card list[], int *count);
void getNameCard(card list[], int count);
void sort(card list[], int count);

int main()
{
    card list[5];

    int input = 0, count = 0;
    printf("NTU NAME CARD HOLDER MANAGEMENT PROGRAM:\n");
    printf("1: listNameCards()\n");
    printf("2: addNameCard()\n");
    printf("3: removeNameCard()\n");
    printf("4: getNameCard()\n");
    printf("5: quit\n");
    do
    {
        printf("Enter your choice:\n");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
            printf("listNameCards():\n");
            if (count == 0)
            {
                printf("The name card holder is empty\n");
                continue;
            }
            else
            {
                listNameCards(list, count-1);
                continue;
            }

            case 2:
            printf("addNameCard():\n");
            addNameCard(list, &count);
			sort(list, count);
            continue;

            case 3:
            printf("removeNameCard():\n");
            removeNameCard(list, &count);
            continue;

            case 4:
            printf("getNameCard():\n");
			getNameCard(list, count);
            continue;

            case 5:
            printf("quit\n");
            continue;
        }
    } while (input!=5);
}

void listNameCards(card list[], int count)
{
    for (int i = 0; i <= count; i++)
    {
		printf("nameCardID: %d\n",list[i].id);
		printf("personName: %s\n",list[i].pname);
		printf("companyName: %s\n",list[i].cname);
    }
    return;
}

void addNameCard(card list[], int *count)
{
    int tempint;
    printf("Enter nameCardID: \n");
    scanf("%d", &tempint);

    printf("Enter personName: \n");
    fgetc(stdin);
    char tempname1[20];
    fgets(tempname1, 20, stdin);
    tempname1[strlen(tempname1)-1] = 0;
    
    printf("Enter companyName: \n");
    char tempname2[20];
    fgets(tempname2, 20, stdin);
    tempname2[strlen(tempname2)-1] = 0;
    
	if (*count==5)
	{
		printf("The name card holder is full\n");
		return;
	}
    
    for (int i = 0; i < *count; i++)
    {
        if (list[i].id == tempint)
        {
            printf("The nameCardID has already existed\n");
            return;
        }
    }
    list[*count].id = tempint;
    strcpy(list[*count].pname,tempname1);
    strcpy(list[*count].cname,tempname2);
    *count = *count + 1;
    printf("The name card has been added successfully\n");
    return;
}

void removeNameCard(card list[], int *count)
{
	printf("Enter personName:\n");
    char removed[20];
    fgetc(stdin);
    fgets(removed, 20, stdin);
    removed[strlen(removed)-1] = 0;
	if (*count == 0)
	{
		printf("The name card holder is empty\n");
		return;
	}
	for (int i = 0; i < *count; i++)
	{
        // convert list name to lowercase
        char lowlistname[20];
        strcpy(lowlistname,list[i].pname);
	    for(int j=0; j<strlen(lowlistname); j++) //convert all characters of list name to lowercase
        {
            lowlistname[j] = tolower(lowlistname[j]);
        }
        // convert target name to lowercase
        char lowtargname[20];
        strcpy(lowtargname,removed);
	    for(int j=0; j<strlen(lowtargname); j++) //convert all characters of targ name to lowercase
        {
            lowtargname[j] = tolower(lowtargname[j]);
        }
		if (strcmp(lowtargname,lowlistname)==0) // if found
		{
		    printf("The name card is removed\n");
			printf("nameCardID: %d\n",list[i].id);
			printf("personName: %s\n",list[i].pname);
			printf("companyName: %s\n",list[i].cname);
			for (int j = i; j < *count; j++)
			{
				list[i] = list[j];
			}
			*count = *count - 1;
			return;
		}
	}
    printf("The target person name is not in the name card holder\n");
    return;
}

void getNameCard(card list[], int count)
{
	printf("Enter personName:\n");
    char search[20];
    fgetc(stdin);
    fgets(search, 20, stdin);
    search[strlen(search)-1] = 0;
	for (int i = 0; i < count; i++)
	{
        // convert list name to lowercase
        char lowlistname[20];
        strcpy(lowlistname,list[i].pname);
	    for(int j=0; j<strlen(lowlistname); j++) //convert all characters of list name to lowercase
        {
            lowlistname[j] = tolower(lowlistname[j]);
        }
        // convert target name to lowercase
        char lowtargname[20];
        strcpy(lowtargname,search);
	    for(int j=0; j<strlen(lowtargname); j++) //convert all characters of targ name to lowercase
        {
            lowtargname[j] = tolower(lowtargname[j]);
        }
		if (strcmp(lowtargname,lowlistname)==0)
		{
            printf("The target person name is found\n");
			printf("nameCardID: %d\n",list[i].id);
			printf("personName: %s\n",list[i].pname);
			printf("companyName: %s\n",list[i].cname);
			return;
		}
	}
	printf("The target person name is not found\n");
    return;
}

void sort(card list[], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count-i-1; j++)
		{
			if (list[j].id>list[j+1].id)
			{
				card temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}