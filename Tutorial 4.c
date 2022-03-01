// Question 1
// #include  <stdio.h>
// #include  <string.h>
// #define  M1  "How are ya, sweetie?"
// char M2[40] = "Beat the clock.";
// char *M3 = "chat";
// int main()
// {
//     char words[80], *p;
//     printf(M1);
//     puts(M1);
//     puts(M2);
//     puts(M2+1);
//     fgets(words, 80, stdin); // user inputs :  win a toy. 
//     if (p=strchr(words,'\n')) *p = '\0';  
//     puts(words);
//     scanf("%s", words+6); // user inputs :  snoopy. 
//     puts(words);
//     words[3] = '\0';
//     puts(words);
//     while (*M3)  puts(M3++);
//     puts(--M3);
//     puts(--M3);
//     M3 = M1;
//     puts(M3);
//     return 0;
// }

// Question 2
//
// if str[x] = c, then z count += 1
// else copy the char into the next position
//
// counts and removes the char c from the original string
// if no copies of c are found, return 0 and original string


// Question 3
// what are they asking? i dont understand the question
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>
// char *strncpy(char s1[40], char s2[40], int n);
// int main()
// {
//     char *s1, *s2;
//     int n;
//     printf("Enter the string: \n");
//     fgets(s2, 40, stdin);
//     printf("Enter the number of characters: \n");
//     scanf("%d", &n);
//     *s1 = strncpy(s1, s2, n);
//     printf("%s", s1);
//     return 0;
// }

// char *strncpy(char *s1, char *s2, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (isdigit(s2[i])==0 && isalpha(s2[i])==0 && i>n)
//         {
//             s1[i] = '\0';
//         }
//         else
//         {
//             s1[i] = s1[i];
//         }
//     }
//     return *s1;
// }


// Question 4
#include <stdio.h>
int stringcmp(char *s1, char *s2);
int main()
{
    char s1[40], s2[40];
    printf("Enter a source string:\n");
    fgets(s1, 40, stdin);
    printf("Enter a target string:\n");
    fgets(s2, 40, stdin);
    int result = stringcmp(s1, s2);
    if (result == 0)
    {
        printf("They are equal\n");
    }
    else if (result > 0)
    {
        printf("Greater\n");
    }
    else
    {
        printf("Smaller\n");
    }
    return 0;
}

int stringcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i]>s2[i])
        {
            return 1;
        }
        else if (s1[i]<s2[i])
        {
            return -1;
        }
        i++;
    }
    return 0;
}