#include<stdio.h>
#include<string.h>

char * maior_sub (char *str1, char *str2){

    int shift = 0;
    int contagem;
    char *achou = strstr(str2,str1[shift]);

    while(str1[shift]!='\0'){
                if (str1[shift]= *achou+shift)
                shift++;
                else printf('%d',*achou);

    }
}


int main()
{

    char string1[] = "ACCTGAACTCCCCCC";

    char string2[] = "ACCTAGGACCCCCC";

    char * maior = maior_sub(* string1,* string2);

    printf("%d",*maior);

}
