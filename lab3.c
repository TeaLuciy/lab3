#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, D, x1, x2, x11, x12;
    int n = 0;
    printf("ax^2+bx+c\n");
    printf("vvedite koef \n");
    while ((scanf("%f %f %f", &a, &b, &c ) !=3 ) || (a == 0)) // проверка ввода
    {
        printf("vvedite snova\n");
        int c;
        while((c=getchar()) != '\n'){}
    }

    printf("%gx^2",a);
    if(b<0){printf("-%gx", b);}
    else if (b>0){printf("+%gx", b);}  // красивый вывод данного уравнения 
    if(c<0){printf("-%g", c);}
    else if(c>0){printf("+%g", c);}
    printf("=0\n");

    D = b*b -4*a*c;

    if (D<0) // дискриминант <0 ==> i
    {
        x11 = (-b)/(2*a);
        x12 = pow(-D,0.5)/(2*a);
        if (b!=0) {printf("%g+%g*i\n %g-%g*i", x11, x12, x11, x12);}
        else {printf("%g*i -%g*i", x12, x12);}
        
    }
    else if (D==0) // дискриминант 0 ==> один корень 
    {
        x1 = (-b)/(2*a);
        printf("%g", x1);
    }
    else // два обычных корня
    {
        x1= (-b+pow(D,0.5))/(2*a);
        x2 = (-b-pow(D,0.5))/(2*a);
        printf("%g %g", x1, x2);
    } 
    
}