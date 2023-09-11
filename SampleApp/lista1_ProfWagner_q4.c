#include <stdio.h>

int main (void){
  float valor;
  float percentual;
  int pessoas;
  float total;
  float individual;


  scanf("%f%f%d",&valor,&percentual,&pessoas);
  total = valor+(valor*percentual);
  individual = total/pessoas;



  printf("Valor por pessoa: %f",individual);
  return 0;
}
