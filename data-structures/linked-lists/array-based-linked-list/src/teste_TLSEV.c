#include "TLSEV.h"

int main(void){
  TLSEV *l = TLSEV_inicializa();
  int elem;
  do{
    scanf("%d", &elem);
    if(elem < 0) break;
    TLSEV_insere(l, elem);
  }while(1);
  TLSEV_imprime(l);
  scanf("%d", &elem);
  TNO *resp = TLSEV_busca(l, elem);
  if(resp) printf("elem = %d\tprox = %d\n", resp->info, resp->prox);
  TLSEV_imprime(l);
  scanf("%d", &elem);
  TLSEV_retira(l, elem);
  TLSEV_imprime(l);
  TLSEV_libera(l);
  return 0;
} 
