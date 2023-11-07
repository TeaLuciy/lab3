#include <stdio.h>
#include <stdlib.h>

int reverse(int x)
{
    if (x == 2)
    {
        return 0;
    }
    if (x == 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int x;
    int a[8][8] = {0};
    for (int i = 0; i <= 7; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i != j)
            {
                x = rand() % 3; 
                a[i][j] = x ;
                a[j][i] = reverse(x);
            }
        }
    }
    for (int i = 0; i <= 7; i++)
    {
        printf("%d %d %d %d %d %d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4], a[i][5], a[i][6], a[i][7]);
    }
}