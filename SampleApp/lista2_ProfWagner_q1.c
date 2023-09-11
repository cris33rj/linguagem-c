#include <stdio.h>

int main (void){
  int a, b, c, maior, menor;

  scanf("%d%d%d",&a,&b,&c);

  if (a >  b)
    maior = a;
    else maior = b;

  if(c > maior)
      maior = c;

  if (a < b)
    menor = a;
    else menor = b;

  if (c < menor)
    menor = c;

  printf("menor: %d --- maior: %d",menor,maior);

}
