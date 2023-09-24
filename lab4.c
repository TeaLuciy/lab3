#include <stdio.h>
#include <math.h>
int nextfib(int f1, int f2)
{
    return f1+f2;
}


int fib[10]={1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
int main()
{
    int fib1=1, fib2=1, fib3=2, z;
    double tochnost, c, new_relation, old_relation;

    for(int i=0; i<5; i++) {
    fib1 = fib2;
    fib2 = fib3;
    fib3 = nextfib(fib1, fib2);
    printf( "%d\n", fib3);
    }
    return 0;
    scanf("%lg", &tochnost);

    printf("%f, %f, %f", fib1, fib2, fib3);

   // do
   // {
   //     old_relation = fib2/fib1;
   //     new_relation = fib3/fib1;
   // 
   // } while (new_relation - old_relation > tochnost);
    
    

}