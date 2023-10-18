#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 1024
#define TOCHN 10

double input() // ввод переводимого числа
{
    double new_num;
    while ((scanf("%lf", &new_num) != 1) ) // проверка ввода
    {
        printf("format is not correct\nenter again\n");
        while ((getchar()) != '\n');
    }
    return new_num;
}

int inputss()  // ввод сс
{
    int new_num;
    while ((scanf("%d", &new_num) != 1) || (new_num < 2) || (new_num > 16) ) // проверка ввода
    {
        printf("format is not correct\nenter again\n");
        while ((getchar()) != '\n');
    }
    return new_num;
}

char digit(int n)   //перевод цифры в сс
{
    char sixt[2];
    int x=1;
    snprintf(sixt, sizeof(sixt), "%X", n);

    return sixt[0];
}

void perevodcel(int cel, char *curr, int ss, int sign)  // перевод целой части в сс
{
    double ost;

    while (cel > 0)
    {
        ost=cel%ss;
        curr--;
        *curr = digit(ost);
        cel=cel/ss;
    }
    if (sign == -1) // добавление знака
    {
        curr--;
        *curr='-';
    }
    
    printf("%s", curr);

}

void perevoddrobn(double drobn, char *mid, int ss) // перевод дробной части в сс
{
    *mid='.';
    char *currdrob = mid;
    float ost = 1;
    int count =0;
    while ( ost != 0)
    {
        if (count == TOCHN)
        {
            currdrob++;
            *currdrob = '.';
            currdrob++;
            *currdrob = '.';
            break;
        }
        count++;
        ost = drobn*ss;
        currdrob++;
        if (ost!=0)
        {
            *currdrob = digit(ost);
        }
        drobn = ost - (int)ost;
    }
    printf("%s", mid);

}

void perevod(double num, int ss)
{
    double drobn;
    int sign,cel;
    char celss[BUFF_SIZE];
    char *mid, *curr, *currdrob;
    memset(celss, 0, sizeof(celss)); // заполнение строчки нулями
    mid = celss + BUFF_SIZE/2; // середина строчки celss
    curr = mid;
    currdrob = mid + 1; 
    sign = copysignf(1, num); // знак числа
    num = fabs(num);
    cel = (int)num;  // целая часть числа
    drobn = (num - cel); // дробная часть числа
    perevodcel(cel, curr, ss, sign);

    if (drobn !=0)
    {
        perevoddrobn(drobn, mid++, ss);
    }
    

}



int main()
{
    double num;
    int ss;





    num=input();
    ss=inputss();
    perevod(num, ss);
    return 0;

}
