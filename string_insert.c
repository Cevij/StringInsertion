#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(char *, char *, int);
char *sub(char *, int, int);

int main(int arg,char *array[100])
{
    char mainStr[100], sub[100];
    int position;
    char *prt, *prt2, *prtNum;
    

    prt = array[1];
    prt2 = array[3];
    prtNum = array[2];


    sscanf(prt, "%s", mainStr);
    sscanf(prtNum, "%d", &position);
    sscanf(prt2, "%s", sub);

    insert(mainStr, sub, position);

    printf("%s\n", mainStr);

    return 0;
}

void insert(char *a, char *b, int position)
{
    char *f, *e;
    int length;

    length = sizeof(a);

    if(length<position)
    {
        printf("an error occured: exseeds bounds\n");
        exit(0);
    }

    f = sub(a, 1, position - 1);
    e = sub(a, position, length - position + 1);

    strcpy(a, "");
    strcat(a, f);
    free(f);
    strcat(a, b);
    strcat(a, e);
    free(e);
}

char *sub(char *string, int position, int length)
{
    char *pointer;
    int c;

    pointer = malloc(length + 1);

    if (pointer == NULL)
        exit(EXIT_FAILURE);

    for (c = 0; c < length; c++)
        *(pointer + c) = *((string + position - 1) + c);

    *(pointer + c) = '\0';

    return pointer;
}