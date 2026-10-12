#include <stdio.h>
#include <string.h>


int igual(char *s1, char *s2){
int resultado = strcmp(s1,s2);
printf("%d",resultado);
return resultado;

}

int main(void){

char s1[] = "Oi meu nome e cristiano";
char s2[] = "Oi meu nome e Cristiano";

int result = igual(s1,s2);
printf("%d",result);

}
