#include <stdio.h>
#include <math.h>
double aproximate(double t)
{
    
}
int nextfib(int f1, int f2)
{
    return f1 + f2;
}

int fib[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
int main()
{
    int fib1 = 1, fib2 = 1, fib3 = 2;
    double tochnost, new_relation, old_relation;

    scanf("%lg", &tochnost);

    do
    {
        old_relation = 1.0 * fib2 / fib1;
        new_relation = 1.0 * fib3 / fib2;

        fib1 = fib2;
        fib2 = fib3;
        fib3 = nextfib(fib1, fib2);
    } while (fabs(old_relation - new_relation) > tochnost);

    printf("%g\nAbsolute=%.10lf\n", new_relation, ((1+sqrt(5))/2));
}