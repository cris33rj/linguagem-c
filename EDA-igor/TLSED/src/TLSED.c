#include "TLSED.h"

TLSED* TLSED_inicializa(void){
  TLSED *novo = (TLSED *) malloc(sizeof(TLSED));
  novo->ini = novo->fim = NULL;
  novo->nelem = 0;
  return novo;
}

void TLSED_ins_ini(TLSED *l, int elem){
  TNO *novo = (TNO *) malloc(sizeof(TNO));
  novo->info = elem;
  novo->prox = l->ini;
  l->ini = novo;
  if(!l->fim) l->fim = novo;
  l->nelem++;
}

void TLSED_imprime(TLSED *l){
  TNO *p = l->ini;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  }
}

void TLSED_libera(TLSED *l){
  TNO *p = l->ini, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  }
  free(l);
}

TNO* TLSED_busca(TLSED *l, int elem){
  TNO *resp = l->ini;
  while((resp) && (resp->info != elem)) resp = resp->prox;
  return resp;
}

void TLSED_retira(TLSED *l, int elem){
  TNO *ant = NULL, *p = l->ini;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return;
  if(!ant){
    l->ini = l->ini->prox;
    if(!l->ini) l->fim = NULL; 
  }
  else ant->prox = p->prox;
  l->nelem--;
  free(p);
}

