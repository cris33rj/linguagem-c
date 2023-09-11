#include<stdio.h>
#include<string.h>

void retira_inicio_n (char *str, int n);

int main(){

char palavra[30];
int prefixo;

//fgets(palavra,30,stdin);
scanf("%30[^\n]",palavra);
scanf("%d",&prefixo);


if (prefixo>strlen(palavra)-1){
    printf("Erro");
    return 0;}

retira_inicio_n(palavra,prefixo);

}

void retira_inicio_n(char *str, int n){
    str += 3;

    printf("%s",str);


    }




