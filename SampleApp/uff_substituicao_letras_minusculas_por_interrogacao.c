#include<stdio.h>
#include<stdlib.h>


char *codifica(char *palavra);

int main(){

char palavra[30];

fgets(palavra,30,stdin);

char *novaPalavra = codifica(palavra);

printf("%s\n",palavra);
printf("%s",novaPalavra);
}


char *codifica(char * palavra){
char *nova = (char *) malloc(sizeof(char)*30);

for (int i=0; i<30; i++){
    if (palavra[i]>=97 && palavra[i]<=122)
        nova[i] = '?';
    else nova[i] = palavra[i];
}

return nova;
}
