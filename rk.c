#include <stdio.h>

long long  input()
{
    long long  new_num;
    while ((scanf("%lld", &new_num) != 1) || (new_num<=0)) // проверка ввода
    {
        printf("формат не верен\nввeдитe снова\n");
        int c;
        while ((c = getchar()) != '\n');
    }
    return new_num;
}

long long newbase( long long base)
{
    long long count;
    count = base;  
        while(count != 0)   // удвоенние колличества знаков
    {
        count=count/10;    
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
    printf("ответ: %lld\n", result);
}