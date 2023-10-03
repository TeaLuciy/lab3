#include <stdio.h>
#include <math.h>

long long  input()
{
    long long  a;
    while ((scanf("%lld", &a) != 1) || (a<=0)) // проверка ввода
    {
        printf("vvedite snova\n");
        int c;
        while ((c = getchar()) != '\n');
    }
    return a;
}

long long newbase( long long base)
{
    long long c;
    c = base;
        while(c != 0)
    {
        c=c/10;
        base=base*10;
    }
}

int main()
{
     long long base, result;
    base = input();
    //printf("size=%d; %lld\n", sizeof(base), base);
    result = base;
    result += newbase(base);
    printf("%lld\n", result);
}