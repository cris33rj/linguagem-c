#include <stdio.h>

int main (void){
  int segundos;
  int minutos;
  int horas;


  scanf("%d",&segundos);
  horas = segundos/3600;
  minutos = segundos%3600/60;
  segundos = segundos%60;



  printf("Valor por pessoa: %d %d %d",horas, minutos,segundos);
  return 0;
}
