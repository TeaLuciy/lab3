#include <stdio.h>
#include <math.h>


int nextfib(int f1, int f2)
{
    return f1 + f2;
}

double new_relation(int fib2, int fib3)
{
    return 1.0 * fib3 / fib2;
}

double old_relation(int fib1, int fib2)
{
    return 1.0 * fib2 / fib1;
}


double approximate(double accuracy)
{   
    int fib1, fib2, fib3;
    fib1=1;
    fib2=1;
    fib3=2;
    do
    {
        fib1 = fib2;
        fib2 = fib3;
        fib3 = nextfib(fib1, fib2);
    } while (fabs(old_relation(fib1, fib2) - new_relation(fib2, fib3)) > accuracy);

    return new_relation(fib2, fib3);

}

int main()
{
    double accuracy, golden_ratio, appr;
    printf("tochnost=");
    scanf("%lg", &accuracy);
    golden_ratio = ((1+sqrt(5))/2);  // formula 
    appr = approximate(accuracy);
    printf("%.10g\nAbsolute=%.10lf\n", appr, golden_ratio);
    printf("pogreshnost=%g\n", golden_ratio - appr);
}