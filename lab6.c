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

char digit(int n)
{
    switch (n)
    {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'a';
    case 11:
        return 'b';
    case 12:
        return 'c';
    case 13:
        return 'd';
    case 14:
        return 'e';
    case 15:
        return 'f';
    default:
        return '*';
    }
}

#define BUFF_SIZE 1024

int main()
{
    double num, drobn;
    int cel;
    int ss;
    char celss[BUFF_SIZE];
    char *mid, *curr;

    memset(celss, 0, sizeof(celss));
    mid = celss + BUFF_SIZE/2;
    curr = mid;

    num=input();
    cel = (int)num;
    drobn = (num - cel);
    printf("%d %g\n", cel, drobn );

    ss=inputss();
    while (cel > 0)
    {
        int ost=cel%ss;
        curr--;
        *curr = digit(ost);
        cel=cel/ss;
    }
    printf("%s\n", curr);


    return 0;

}
