#include <stdio.h>
#include <math.h>
double input(double a)
{
    while ((scanf("%lf", &a) != 1) || (a<=0)) // проверка ввода
    {
        printf("vvedite snova\n");
        int c;
        while ((c = getchar()) != '\n')
        {
        }
    }
    return a;
}
int nextfib(int f1, int f2)
{
    return f1 + f2;
}

double relation(int fib1, int fib2)
{
    return 1.0 * fib2 / fib1;
}

double approximate(double accuracy)
{
    int fib1, fib2, fib3;
    fib1 = 1;
    fib2 = 1;
    fib3 = 2;
    
    do
    {
        printf("%d, %d, %d\n", fib1, fib2, fib3);
        fib1 = fib2;
        fib2 = fib3;
        fib3 = nextfib(fib1, fib2);
    } while (fabs(relation(fib1, fib2) - relation(fib2, fib3)) > accuracy);

    return relation(fib2, fib3);
}

int main()
{
    double accuracy, golden_ratio, appr;
    printf("accuracy=");
    accuracy = input(accuracy);
    // scanf("%lg", &accuracy);
    golden_ratio = ((1 + sqrt(5)) / 2); // formula
    appr = approximate(accuracy);
    printf("%g\nAbsolute=%.10lf\n", appr, golden_ratio);
    printf("absolute error=%g\n", fabs(golden_ratio - appr));
    printf("relative error=%g\n", fabs(golden_ratio - appr) / appr);
}