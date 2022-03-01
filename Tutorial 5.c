// // Question 1
// #include <stdio.h>
// #include <math.h>
//
// typedef struct
// {
//     double radius;
//     double x;
//     double y;
// } circle ;
//
// int intersect (circle c1, circle c2);
// int contain (circle c1, circle c2);
//
// int main()
// {
//     circle c1, c2;
//     printf("Enter C1 Radius\n");
//     scanf("%d", &c1.radius);
//     printf("Enter C1 x position:\n");
//     scanf("%d", &c1.x);
//     printf("Enter C1 y position:\n");
//     scanf("%d", &c1.y);
//     printf("Enter C2 Radius\n");
//     scanf("%d", &c2.radius);
//     printf("Enter C2 x position:\n");
//     scanf("%d", &c2.x);
//     printf("Enter C2 y position:\n");
//     scanf("%d", &c2.y);
//     if (intersect(c1,c2) == 1)
//     {
//         printf("C1 and C2 intersect\n");
//     }
//     else
//     {
//         printf("C1 and C2 do not intersect\n");
//     }
//     if (contain(c1,c2) == 1)
//     {
//         printf("C1 contains C2\n");
//     }
//     else
//     {
//         printf("C1 does not contain C2\n");
//     }
//     return 0;
// }
//
// int intersect(circle c1, circle c2)
// {
//     int tempx = c1.x - c2.x;
//     int tempy = c1.y - c2.y;
//     int temprad = c1.radius + c2.radius;
//     int dist = sqrt((tempx)*(tempx)+(tempy)*(tempy));
//     if (dist <= temprad)
//     {
//         return 1;
//     }
//     return 0;
// }
//
// int contain(circle c1, circle c2)
// {
//     int tempx = c1.x - c2.x;
//     int tempy = c1.y - c2.y;
//     int dist = sqrt((tempx)*(tempx)+(tempy)*(tempy));
//     if (c1.radius >= c2.radius+dist)
//     {
//         return 1;
//     }
//     return 0;
// }


// Question 2
// #include <stdio.h>
// #include <math.h>
// #include <string.h>
//
// typedef struct
// {
//     float operand1, operand2;
//     char op;    // char to store operator
// } beexpression;
//
// float compute1 (beexpression expr);
// float compute2 (beexpression *expr);
//
// int main()
// {
//     beexpression expr;
//     printf("Enter the operator:\n");
//     scanf("%c", &expr.op);
//     printf("Enter the first number:\n");
//     scanf("%f", &expr.operand1);
//     printf("Enter the second number:\n");
//     scanf("%f", &expr.operand2);
//     printf("%.2f\n",compute1(expr));
//     printf("%.2f\n",compute2(&expr));
//     return 0;
// }
//
// float compute1 (beexpression expr)
// {
//     float result;
//     if (expr.op == '+')
//     {
//         result = expr.operand1 + expr.operand2;
//     }
//     if (expr.op == '-')
//     {
//         result = expr.operand1 - expr.operand2;
//     }
//     if (expr.op == '*')
//     {
//         result = expr.operand1 * expr.operand2;
//     }
//     if (expr.op == (int)'/')
//     {
//         result = expr.operand1 / expr.operand2;
//     }
//     return result;
// }
//
// float compute2 (beexpression *expr)
// {
//     float result;
//     if (expr->op == '+')
//     {
//         result = expr->operand1 + expr->operand2;
//     }
//     if (expr->op == '-')
//     {
//         result = expr->operand1 - expr->operand2;
//     }
//     if (expr->op == '*')
//     {
//         result = expr->operand1 * expr->operand2;
//     }
//     if (expr->op == (int)'/')
//     {
//         result = expr->operand1 / expr->operand2;
//     }
//     return result;
// }


// Question 3
// #include <stdio.h>
// #include <string.h>
//
// typedef struct
// {
//     int id;
//     int total;
//     int taken;
// } leave;
//
// void getinput(leave list[], int *n);
// int maytake(leave list[], int id, int want, int n);
// void printlist(leave list[], int n);
//
// int main()
// {
//     leave list[10];
//     int choice, n = 0;
//     while (1)
//     {
//         printf("Leave record system\n");
//         printf("1. getinput()\n");
//         printf("2. maytake()\n");
//         printf("3. printlist()\n");
//         printf("4. quit()\n");
//         printf("Enter your choice:\n");
//         scanf("%d", &choice);
//         int id, want, result;
//         switch(choice)
//         {
//             case 1:
//                 getinput(list, &n);
//                 continue;
//             case 2:
//                 printf("Enter ID:\n");
//                 scanf("%d", &id);
//                 printf("Enter the number of days you would like to take:\n");
//                 scanf("%d", &want);
//                 result = maytake(list, id, want, n);
//                 if (result == 1) // can take
//                 {
//                     printf("Leave approved\n");
//                 }
//                 else if (result == 0)
//                 {
//                     printf("Leave NOT approved\n");
//                 }
//                 else
//                 {
//                     printf("ID not found\n");
//                 }
//                 continue;
//             case 3:
//                 printlist(list, n);
//                 continue;
//             case 4:
//                 printf("Quitting program...\n");
//                 return 0;
//         }
//     }
//     return 0;
// }
//
// void getinput(leave list[], int *n)
// {
//     *n = 0;
//     int id = 0, flag = 0;
//     while (*n < 10)
//     {
//         flag = 0;
//         printf("Enter Employee ID (-1 to quit):\n");
//         scanf("%d",&id);
//         if (id == -1) // if -1, quit
//         {
//             return;
//         }
//         for (int j = 0; j < *n; j++) // compare with past data
//         {
//             if (id == list[j].id) // if found, flag = 1
//             {
//                 printf("This employee has been entered before\n");
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0) // flag == 0 means new data, need to input
//         {
//             list[*n].id = id;
//             printf("Enter Employee total leave:\n");
//             scanf("%d",&list[*n].total);
//             printf("Enter Employee leave taken:\n");
//             scanf("%d",&list[*n].taken);
//             *n = *n + 1;
//         }      
//     }
//     return;
// }
//
// int maytake(leave list[], int id, int want, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         if (list[i].id == id)
//         {
//             int left = list[i].total - list[i].taken;
//             if (left > 0)
//             {
//                 list[i].taken += want;
//                 return 1;
//             }
//             return 0;
//         }
//     }
//     return -1;
// }
//
// void printlist(leave list[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int left = list[i].total - list[i].taken;
//         printf("ID: %d, total leave: %d,", list[i].id, list[i].total);
//         printf(" taken: %d, left with: %d\n", list[i].taken, left);
//     }
//     return;
// }