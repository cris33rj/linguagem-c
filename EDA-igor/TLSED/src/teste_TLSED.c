#include "TLSED.h"

int main(void){
  TLSED *l = TLSED_inicializa();
  int x;
  do{
    printf("Digite um numero maior ou igual a zero para inserir na lista (numeros negativos interrompem a insercao)... ");
    scanf("%d", &x);
    if(x < 0) break;
    TLSED_ins_ini(l, x);
    TLSED_imprime(l);
    printf("\n");
  }while(1);
  TLSED_imprime(l);
  printf("\n");

  printf("Digite um numero a ser retirado da lista... ");
  scanf("%d", &x);
  TLSED_retira(l, x);
  TLSED_imprime(l);
  printf("\n");

  TLSED_libera(l);
  return 0;
}
