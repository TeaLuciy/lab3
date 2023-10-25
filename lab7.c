#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;
    int cw = 0;
    int cl = 1;
    int ca = 0;
    int flag = 0;

    while ((c = getchar()) != EOF)
    {
        //putchar(c);
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
    printf("\ncw=%d\ncl=%d\nca=%d\n", cw, cl, ca);
}

