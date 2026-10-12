#include "TP.h"

/*
 typedef struct pilha TP;
 TP *TP_inicializa (void);
 void TP_push (TP *p, int v);
 int TP_pop (TP *p);
 int TP_vazia (TP *p);
 void TP_libera (TP *p);
*/

void ordena(TP *p){
  TP *aux = TP_inicializa(), *q = TP_inicializa();
  while(!TP_vazia(p)) TP_push(aux, TP_pop(p));
  while(!TP_vazia(aux)){
    int maior = TP_pop(aux);
    while(!TP_vazia(aux)){
       int x = TP_pop(aux);
       if(x <= maior) TP_push(q, x);
       else{
         TP_push(q, maior);
         maior = x;
       }
    }
    TP_push(p, maior);
    while(!TP_vazia(q)) TP_push(aux, TP_pop(q));
  }
  TP_libera(aux);
  TP_libera(q); 
}

int main(void){
  TP *p = TP_inicializa();
  printf("Insira elementos maiores ou iguais a zero para inclusao na pilha...\n");
  do{
    int n;
    scanf("%d", &n);
    if(n < 0) break;
    TP_push(p, n);
  }while(1);
  printf("Antes de ordenar...\n");
  TP_imprime(p);
  ordena(p);
  printf("Depois de ordenar...\n");
  TP_imprime(p);
  TP_libera(p);
  return 0;  
}
