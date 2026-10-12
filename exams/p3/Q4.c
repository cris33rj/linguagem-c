#include <limits.h>
#include "TARVB.h"

int* div_k (TARVB* a, int k, int *n){
   // int  * resp;
if(a){
    int i;
    for(i=0; i<=a->nchaves-1; i++){
      div_k(a->filho[i],k, n++);
      if(k%(a->chave[i])==0){

            printf("=======> IMPRIMINDO N %d\n",*n);
      printf("%d\n", a->chave[i]);
      printf("&&&&&&&&&&&&&&IMPRIMIU");
      //resp[*n] = a->chave[i];
      }
    }
    div_k(a->filho[i],k, n++);
  }

  return n;
}




int main(int argc, char *argv[]){
  TARVB *arvore = TARVB_Inicializa();
  int t;
  do{
    scanf("%d", &t);
    if((t >= 2) && (t <= 4)) break;
  }while(1);

  int num;
  do{
    scanf("%d", &num);
    if(num <= 0) break;
    arvore = TARVB_Insere(arvore, num, t);
  }while(1);
  TARVB_Imprime(arvore);


  if(arvore){
    int n, k, i;
    printf("vai fazer o scanf");
    scanf("%d", &k);
    printf("fez o scanf");
    int *resp = div_k (arvore, k, &n);
    if(resp){
      printf("tem resp");
      for(i = 0; i < n; i++) printf("%d ", resp[i]);
      printf("\n");
      free(resp);
    }
  }

  TARVB_Libera(arvore);
  return 0;
}
