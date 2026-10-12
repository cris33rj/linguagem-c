#include<stdio.h>
#include<string.h>

int cic (char *str1, char *str2)
{

    char *busca = strstr(strupr(str1),strupr(str2));

    if(busca)
        return 1;
    else return 0;

}



int main()
{

    char frase[] = "O senhor e o meu pastor e nada me faltara";

    char substring[] = "deus";

    int achou = cic(frase,substring);

    printf("%d",achou);

}
