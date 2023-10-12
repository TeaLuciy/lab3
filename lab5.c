#include <stdio.h>
#include <stdlib.h>

int input()
{
    float new_num;
    while ((scanf("%f", &new_num) != 1) || (new_num <= 0) || (new_num > 100)) // проверка ввода
    {
        printf("format is not correct\nenter again\n");
        while ((getchar()) != '\n');
    }
    return new_num;
}

void ggl(int age) // год, года или лет
{

    /*
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
    */

    switch (age)
    {
        case 11:
        case 12:
        case 13:
        case 14:
            printf("%d лет\n", age);
            break;
        default :
            switch (age % 10)
            {
            case 1:
                printf("%d год\n", age);
                break;
            case 2:
            case 3:
            case 4:
                printf("%d года\n", age);
                break;
            default:
                printf("%d лет\n", age);
                break;
            }
    }
}

void sover(int age) // функция отвещающие за совершеннолетие
{
    int sov;
    sov = 18 - age;
    if (sov == 0)
    {
        printf("Вы совершеннолетний");
    }
    else if (sov > 0)
    {
        printf("Вам до совершеннолетия: ");
        ggl(sov);
    }
    else if (sov < 0)
    {
        printf("Вы совершеннолетний уже ");
        ggl(abs(sov));
    }
    printf("\n");
}

void pens(int age) // функция отвечающая за пенсию
{
    int pen;
    pen = 60 - age;
    if (pen == 0)
    {
        printf("Вы пенсионер");
    }
    else if (pen > 0)
    {
        printf("Вам до пенсии: ");
        ggl(pen);
    }
    else if (pen < 0)
    {
        printf("Вы на пенсии ");
        ggl(abs(pen));
    }
    printf("\n");
}

int main()
{

    int age;
    printf("Введите ваш возраст: ");
    age = input();
    printf("Ваш возраст: ");
    ggl(age);
    printf("\n");
    sover(age);
    pens(age);


    /*
    for (size_t i = 0; i < 100; i++)
    {
        ggl(i);
        printf(", ");
    }
    */
    
    
}