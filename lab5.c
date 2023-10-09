#include <stdio.h>
#include <stdlib.h>

int  input()
{
    int  new_num;
    while ((scanf("%d", &new_num) != 1) || (new_num<=0) || (new_num > 100)) // проверка ввода
    {
        printf("format is not correct\nenter again\n");
        while ((getchar()) != '\n');
    }
    return new_num;
}


void ggl(int age)  // год, года или лет
{
        if ((age % 10 == 1) && (age % 100 != 11))
    {
        printf("%d год", age);
    }
    else if ((age >= 2 && age < 5) || ((age % 100 > 20) && (age % 10 >= 2 && age % 10 < 5)))
    {
        printf("%d года", age);
    }
    else
    {
        printf("%d лет", age);
    }
}

void sover(int age) // функция отвещающие за совершеннолетие
{
    int sov;
    sov= 18 - age;
    if (sov == 0)
    {
        printf("Вы совершеннолетний\n");
    }
    else if (sov > 0)
    {
        printf("Вам до совершеннолетия: ");
        ggl(sov);
        printf("\n");
    }
    else if (sov <0)
    {
        printf("Вы совершеннолетний уже ");
        ggl(abs(sov));
        printf("\n");
    }
}

void pens(int age)  // функция отвечающая за пенсию
{
    int pen;
    pen= 60 - age;
    if (pen == 0)
    {
        printf("Вы пенсионер\n");
    }
    else if (pen > 0)
    {
        printf("Вам до пенсии: ");
        ggl(pen);
        printf("\n");
    }
    else if (pen <0)
    {
        printf("Вы на пенсии ");
        ggl(abs(pen));
        printf("\n");
    }
}

int main()
{

    int age;
    age = input();
    printf("Ваш возраст:");
    ggl(age);
    printf("\n");
    sover(age);
    pens(age);
}