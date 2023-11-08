#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8



void output(int b[SIZE])
{
    for (int i =0; i < SIZE; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}

void output_matrix(int a[SIZE][SIZE])
{
    for (int i =0; i < SIZE; i++)
    {
        if (i>=9)
        {
            printf("team %d   ", i+1);
        }
        else
        {
            printf("team %d    ", i+1);
        }
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}   

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

void create(int a[SIZE][SIZE])
{
    int x;

    for (int i = 0; i <= SIZE - 1; i++) // создание массива
    {
        for (int j = 0; j < i; j++)
        {
            if (i != j)
            {
                x = rand() % 3;
                if (x == 2)
                {
                    x = 3;
                }
                a[i][j] = x;
                a[j][i] = reverse(x);
            }
        }
    }
}

int scores(int b[SIZE], int a[SIZE][SIZE])
{
    int mx_score = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            b[i] += a[i][j];
        }

        if (b[i] > mx_score)
        {
            mx_score = b[i];
        }
    }
    return mx_score;
}

void leaders(int mx_score, int b[SIZE])
{
     for (int i = 0; i < SIZE; i++)
       {
           if (b[i] == mx_score)
           {
               printf("team %d ", i+1);
           }
       }
}

    int main()
{
    int x;
    srand(time(NULL));
    int a[SIZE][SIZE] = {0};
    int b[SIZE] = {0};

    create(a);
    output_matrix(a);
    x=scores(b, a);
    leaders(x, b);
    printf("                    with %d score \n\n", x);
    output(b);

}