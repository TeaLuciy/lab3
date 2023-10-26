#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;
    int cw = 0;  //  слова
    int cl = 1;  //  строки
    int ca = 0;  //  все символы
    int flag = 0;
    int cc =0;  //   управляющие символы
    int calpha=0; // все лат. буквы
    int cd=0; //     цифры
    int cop =0; //   знаки операций

    while ((c = getchar()) != EOF)
    {
        putchar(c);
        if (c< ' ' || c == 127)
        {
            cc+=1;
        }
        if (isalpha(c))
        {
            calpha+=1;
        }
        if (isdigit(c))
        {
            cd+=1;
        }
        if ((c>='!' && c <= '/') || (c >= ':' && c <='@') || (c>= '[' && c < 'a') || (c >'z' && c < 127 || c>=248 && c <=252))
        {
            cop++;
        }
        //fflush(stdout);
        if (isalnum(c) == 0)
        {

            if (isspace(c) && flag)
            {
                cw += 1;
                flag = 0;
            }
            if (c == '\n')
            {
                cl += 1;
            }
            ca += 1;
        }
        else
        {
            ca += 1;
            flag = 1;
        }
    }

    if (c == EOF && flag)
    {
        cw += 1;
    }
    printf("\ncw=%d\ncl=%d\nca=%d\ncc=%d\ncalpha=%d\ncd=%d\ncop=%d\n", cw, cl, ca, cc, calpha, cd, cop);
}
