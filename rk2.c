#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE1 6
#define SIZE2 5

void output_matrix(int a[SIZE1][SIZE2])
{
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            if (a[i][j] >= 0)
            {
                if (a[i][j] > 9)
                {
                    printf(" %d  ", a[i][j]);
                }
                else
                {
                    printf(" %d   ", a[i][j]);    //вывод матрицы
                }
            }
            else
            {
                if (a[i][j] < -9)
                {
                    printf("%d  ", a[i][j]);
                }
                else
                {
                    printf("%d   ", a[i][j]);
                }
            }
        }
        printf("\n");
    }
    printf("\n");
}

void create(int a[SIZE1][SIZE2])
{
    int ini[21];
    int x;
    for (int f = -10; f <= 10; f++)
    {
        ini[f+10] = f;
    }

    for (int i = 0; i < SIZE1; i++) // создание матрицы
    {
        for (int j = 0; j < SIZE2; j++)
        {

            x = rand() % 21;
            a[i][j] = ini[x];
        }
    }
}
void sort(int a[SIZE1][SIZE2])
{
    for (int j =0; j < SIZE2; j++)
    {
        for (int i =0; i < SIZE1; i++)
        {
            for (int k = i +1; k < SIZE1; k++)
            if ( a[i][j] < a[k][j])
            {
                int temp = a[i][j];
                a[i][j] = a[k][j];
                a[k][j] = temp;
            }
        }
    }
}

int min(int a[SIZE1][SIZE2])
{
    int min = 100000;
    for (int i = 0; i < SIZE2; i++)
    {
        if (a[5][i] < min)
        {
            min = a[5][i];
        }
    }
    return min;
}
 void change(int a[SIZE1][SIZE2])
 {
    int x = min(a);
    for (int i = 0; i < SIZE1; i++)
    {
        for (int j = 0; j < SIZE2; j++)
        {
            if (a[i][j] < 0)
            {
                a[i][j] = x;
            }
        }
    }
 }

int main()
{
    int x;
    srand(time(NULL));
    int a[SIZE1][SIZE2] = {0};
    create(a);
    output_matrix(a);
    sort(a);
    output_matrix(a);
    printf("%d\n\n", min(a));
    change(a);
    output_matrix(a);
}