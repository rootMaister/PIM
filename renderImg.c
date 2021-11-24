#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

char renderImg(FILE *x)
{

    //FILE *img = fopen(x, "r");

    char *imgRendered[1000];

    system("cls");

    while (!feof(x))
    {
        fgets(imgRendered, 1000, x);
        printf("%s\n", imgRendered);
    }

    system("pause");

}