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

int main()
{
    double num, drobn;
    int cel;
    int ss;
    char celss[1024];
    char celss1[1024];


    num=input();
    cel = (int)num;
    drobn = (num - cel);
    printf("%d %g\n", cel, drobn );
    celss[0] = 0;

    ss=inputss();
    while (cel > 0)
    {
        int ost=cel%ss;
        sprintf(celss1, "%d%s", ost, celss);
        strcpy(celss, celss1);
        cel=cel/ss;
        printf("cel: %d, celss: %s\n", cel, celss);
    }
    printf("%s\n", celss);


    return 0;

}
