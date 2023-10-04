#include <stdio.h>


unsigned long long  input()
{
    unsigned long long  new_num;
    while ((scanf("%llu", &new_num) != 1) || (new_num<=0) || (new_num > 0x6DF37F67)) // проверка ввода
    {
        printf("format is not correct\nenter again\n");
        while ((getchar()) != '\n');
    }
    return new_num;
}

unsigned long long newbase(unsigned long long base)
{
    unsigned long long count;
    count = base;  
        while(count != 0)   // удвоенние колличества знаков
    {
        count=count/10;    
        base=base*10; 
    }
    return base;
}

int main()
{
    unsigned long long base, result;
    base = input();
    //printf("size=%d; %ull\n", sizeof(base), base);
    result = base;
    result += newbase(base);  
    printf("answer: %llu\n", result);
}


//18446744073709551615   =  ffffffff
//18446744071844674407
//1844674407             =  6DF37F67      максимальное число которое можно удвоить