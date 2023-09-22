#include <stdio.h>
#include <math.h>

int Dotric(double D, double a, double b)
{
    double x1, x2;
    x1 = (-b) / (2 * a);
    x2 = pow(-D, 0.5) / (2 * a);
    if (b != 0)
    {
        printf("%lg+%lg*i\n %lg-%lg*i", x1, x2, x1, x2);
    }
    else
    {
        printf("%lg*i -%lg*i\n", x2, x2);
    }
}

int Dnol(double D, double a, double b)
{
    double x1;
    x1 = (-b) / (2 * a);
    printf("%lg\n", x1);
}

int Basa(double D, double a, double b)
{
    double x1, x2;
    x1 = (-b + pow(D, 0.5)) / (2 * a);
    x2 = (-b - pow(D, 0.5)) / (2 * a);
    printf("%lg %lg\n", x1, x2);
}

void output(double a, double b, double c)
{
    printf("%lgx^2", a);
    if (b < 0)
    {
        printf("-%lgx", b);
    }
    else if (b > 0)
    {
        printf("+%lgx", b);
    }                           // красивый вывод данного уравнения
    if (c < 0)
    {
        printf("-%lg", c);
    }
    else if (c > 0)
    {
        printf("+%lg", c);
    }
    printf("=0\n");
}

void input(double *a, double *b, double *c)
{
    while ((scanf("%lf %lf %lf", a, b, c) != 3) || (a == 0)) // проверка ввода
    {
        printf("vvedite snova\n");
        int c;
        while ((c = getchar()) != '\n')
        {
        }
    }
}

//---------------------------------------------------------------------------------------

int main()
{
    double a, b, c, D, x1, x2, x11, x12;
    int n = 0;
    printf("ax^2+bx+c\n");
    printf("vvedite koef \n");
    input(&a, &b, &c);

    output(a, b, c); // красивый вывод данного уравнения
    D = b * b - 4 * a * c;

    if (D < 0) // дискриминант <0 ==> i
    {
        Dotric(D, a, b);
    }
    else if (D == 0) // дискриминант 0 ==> один корень
    {
        Dnol(D, a, b);
    }
    else // два обычных корня
    {
        Basa(D, a, b);
    }
}