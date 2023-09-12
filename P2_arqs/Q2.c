#include "TLSE.h"

void misc(TLSE *l, int n){
    TLSE *ptr, * prev, *temp;


    if(n%2!=0){
        ptr = l;
        while (ptr!=NULL){
            if(ptr->info=n){
                temp = ptr->prox;
                ptr->prox = temp->prox;
                ptr = ptr->prox;

            } else {
                ptr =ptr->prox;
                prev = prev->prox;
            }
        }

    }

    if(n%2==0){
        prev = l;
        ptr = prev->prox;
        while(ptr->prox!=NULL){
            if(ptr->prox->info=n){
                temp=ptr;
                prev->prox=temp->prox;
                ptr = ptr->prox;
            }else {
                prev = prev->prox;
                ptr = ptr->prox;
            }


        }
    }
}

int main(void){
  TLSE *l = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l = TLSE_insere(l, n);
  }while(1);

  scanf("%d", &n);
  misc(l, n);
  TLSE_imprime(l);
  printf("\n");

  TLSE_libera(l);
  return 0;
}
