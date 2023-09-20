#include <stdio.h>
#include <time.h>

int c[12]= {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int day, month, year, ti;
int main() {
    
    ti=time(NULL);
    printf("%d:", ((ti/3600)+3)%24);//часы
    printf("%d:", ti/60%60);//минуты
    printf("%d\n",ti%60);//секунды
    scanf("%d %d %d", &day, &month, &year);
    //printf("%d\n%d\n%d\n", day, month, year);
    if (((year%4==0 && year%100!=0) || (year%400 ==0)) && month >2)
    {
        int ans=1+day+c[month-1];
        printf("%d\n", ans );
    }
    else
    {
        int ans=day+c[month-1];
        printf("%d\n", ans );
    }
    //for (int i=0; i < 12; ++i){printf("%d", c[i]);}
    
    return 0;
}