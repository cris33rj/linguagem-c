#include "TP.h"

//TP *radx(TP* p, int x){}

int main(void){
  printf("Digite os elementos da pilha… Quando for fornecido um número negativo, a pilha não receberá mais elementos…\n");
  TP *p = TP_inicializa();
  while(1){
    int aux;
    scanf("%d", &aux);
    if(aux < 0) break;
    TP_push(p, aux);
  }

  int x;
  scanf("%d", &x);
  //TP *resp = radx(p, x);
  //TP_imprime(resp);
  //TP_libera(resp);
  TP_libera(p);
  return 0;
}
