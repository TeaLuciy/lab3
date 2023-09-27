#include <stdio.h>
#include <math.h>


int nextfib(int f1, int f2)
{
    return f1 + f2;
}


double approximate(double t)
{   
    int fib1, fib2, fib3;
    double new_relation, old_relation;
    fib1=1;
    fib2=1;
    fib3=2;
    do
    {
        old_relation = 1.0 * fib2 / fib1;
        new_relation = 1.0 * fib3 / fib2;

        fib1 = fib2;
        fib2 = fib3;
        fib3 = nextfib(fib1, fib2);
    } while (fabs(old_relation - new_relation) > t);

    return new_relation;

}

int main()
{
    double tochnost, new_relation, old_relation;

    scanf("%lg", &tochnost);

    printf("%.10g\nAbsolute=%.10lf\n", approximate(tochnost), ((1+sqrt(5))/2));
}