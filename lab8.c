#include <stdio.h>
#include <math.h>
#define ACCURACY 0.000001
#define PERFECT 0.46061145580745
int difsgn(float a, float b)
{
    if (copysignf(1,a) != copysignf(1,b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
float mid(float a, float b) //[a;b]
{
    float c;
    c =(a + b) / 2;
    return c;
}
float f(float a)
{
    return sin(3 * a) - exp(3 * a) + 3 ;
}

int main()
{
    float a = -1;
    float b = 0;
    float c = 1;

    while (fabs(f(b)) > ACCURACY)
    {
        printf("%f\n", f(b));
        b = mid(a,c);
        printf("%f    %f\n", f(a), f(b));
        if (difsgn(f(a),f(b)))
        {
            c=b;
        }
        else
        {
            a=b;
        }
    } 

    printf("fb= %f\nb= %f\n", f(b), b);
    printf("perfect= %f\n", PERFECT);
    return 0;
}
/*

-1 1

(+)0 (-)1

(+)0 (-)0.5



*/