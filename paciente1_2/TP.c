#include "TLSE.h"
#include "TP.h"

struct pilha{
  TLSE *topo;
};

TP *TP_inicializa(void){
  TP *p = (TP *)malloc(sizeof(TP));
  p->topo = NULL;
  return p;
}

int TP_vazia(TP *p){
  return (p->topo == NULL);
}

void TP_push(TP *p,PAC * paci){
  p->topo = TLSE_insere(p->topo, paci);
  /*
  TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
  novo->info = elem;
  novo->prox = p->topo;
  p->topo = novo;
  */
}

PAC * TP_pop(TP *p){
  if (!TP_vazia(p)){
    TLSE *aux = p->topo;
    PAC * paci = aux->info;
    p->topo = aux->prox;
    free(aux);
    return paci;
  }
  else{ // pilha vazia
    exit(1);
  }
}

void TP_libera(TP *p){
  TLSE_libera(p->topo);
  /*
  TLSE *q = p->topo,*r ;
  while(q){
    r = q;
    q = q->prox;
    free(r);
  }
  */
  free(p);
}

void TP_imprime(TP *p){
  TP *aux = TP_inicializa();
  int ind = 1;
  while (!TP_vazia(p)){
    PAC * paci = TP_pop(p);
    printf("%d -> %s ->%d\n", ind++, paci->nome,paci->tempo);
    TP_push(aux,paci);
  }
  while(!TP_vazia(aux)) TP_push(p, TP_pop(aux));
  TP_libera(aux);
}
