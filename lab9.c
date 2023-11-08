#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int reverse(int x)
{
    if (x == 3)
    {
        return 0;
    }
    if (x == 0)
    {
        return 3;
    }
    else
    {
        return 1;
    }
}
int main()
{
    srand(time (NULL));


    int x;
    int a[8][8] = {0};
    int b[8]={0};
    int mx_score = 0;
    int mx_name = 0;
    for (int i = 0; i <= 7; i++)        // создание массива
    {
        for (int j = 0; j < i; j++)
        {
            if (i != j)
            {
                x = rand() % 3;
                if (x==2)
                {
                    x=3;
                }
                a[i][j] = x ;
                a[j][i] = reverse(x);
            }
        }
    }
    for (int i = 0; i <= 7; i++)
    {
        printf("%d %d %d %d %d %d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], a[i][6], a[i][7]);
    }




    for (int i = 0; i<=7; i++)
    {


        for(int j = 0; j<=7; j++)
        {
            b[i]+=a[i][j];
        }


        if (b[i] > mx_score)
        {
            mx_score = b[i];
        }

    }

    for (int i = 0; i <= 7; i++)
    {
        if (b[i] == mx_score)
        {
            printf("%d ", i+1);
        }
    }


    printf("\n%d %d %d %d %d %d %d %d\n", b[0], b[1], b[2], b[3], b[4], b[5], b[6], b[7]);

}