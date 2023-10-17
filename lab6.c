#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double input()
{
    double new_num;
    while ((scanf("%lf", &new_num) != 1) ) // проверка ввода
    {
        printf("format is not correct\nenter again\n");
        while ((getchar()) != '\n');
    }
    return new_num;
}

int inputss()
{
    int new_num;
    while ((scanf("%d", &new_num) != 1) || (new_num < 2) || (new_num > 16) ) // проверка ввода
    {
        printf("format is not correct\nenter again\n");
        while ((getchar()) != '\n');
    }
    return new_num;
}

char digit(int n)     // переделать через sprintf
{
    char sixt[2];
    int x=1;
    snprintf(sixt, sizeof(sixt), "%X", n);

    return sixt[0];
}

#define BUFF_SIZE 1024

int main()
{


    double num, drobn;
    int cel;
    int ss;
    char celss[BUFF_SIZE];
    char *mid, *curr, *currdrob;

    memset(celss, 0, sizeof(celss));
    mid = celss + BUFF_SIZE/2;
    curr = mid;
    currdrob = mid + 1;


    num=input();
    cel = (int)num;
    drobn = (num - cel);
    printf("%d %g\n", cel, drobn );



    double ost;
    ss=inputss();
    while (cel > 0)
    {
        ost=cel%ss;
        curr--;
        *curr = digit(ost);
        cel=cel/ss;
    }
    printf("%s\n", curr);
    



    *mid = '.';



    ost = 1;
    int count =0;
    while ( ost != 0)
    {
        if (count == 10)
        {
            mid++;
            *mid = '.';
            mid++;
            *mid = '.';
            break;
        }
        count++;
        ost = drobn*ss;
        mid++;
        if (ost!=0)
        {
            *mid = digit(ost);
        } else {
            *mid = '0';
        }
        drobn = ost - (int)ost;
    }
    printf("%s\n", curr);
    return 0;

}
