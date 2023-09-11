#include <stdio.h>

int main (void){
  int num, neg, pos, quant;

  neg = 0;
  pos = 0;

  do{
  printf("informe o numero:\n");
  scanf("%d",&num);
  quant++;
  if (num > 0)
    pos++;
  else
    neg++;
  }
  while(quant<5);

  printf("quant negativos: %d --- quant. positivos: %d",neg,pos);
  return 0;

}
