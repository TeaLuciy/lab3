#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFL 256

void process( char* a, char* b)
{
    int j=0;
    for ( int i = 0; i <=strlen(b); i++)
    {   if ((b[i] != ' ') && (b[i] != '\t') && (b[i] != '\n'))
        {
            a[j] = b[i];
            j++;
        }
    }
}

void main()
{
    char** strings = NULL;
    char buff[BUFL];
    int strings_size = 0;
    int strings_cnt = 0;
    while(fgets(buff, BUFL, stdin))
    {

        if (strings_cnt == strings_size)
        {
            strings_size++;
            strings = realloc(strings, strings_size * sizeof(char*));
            strings[strings_cnt]=malloc((strlen(buff)+1) * sizeof(char));
            process(strings[strings_cnt], buff);
            strings_cnt++;
        }
    }
    for(int i = 0; i < strings_cnt; i++)
    {printf("%s\n", strings[i]);}


}