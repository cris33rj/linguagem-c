#include "TLSE.h"


TLSE* TLSE_insere(TLSE *l, PAC * novo_paci){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = novo_paci;
  return novo;
}

void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%s ", p->info->nome);
    p = p->prox;
  }
}

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  }
}

TLSE* TLSE_retira(TLSE *l, PAC * paci){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info->nome != paci->nome)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* TLSE_busca(TLSE * l, PAC *paci){
  TLSE *p = l;
  while((p) && (p->info->nome != paci->nome)) p = p->prox;
  return p;
}

