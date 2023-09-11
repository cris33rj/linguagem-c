#include "TLSEV.h"

TLSEV *TLSEV_inicializa(void){
  TLSEV *l = (TLSEV*) malloc(sizeof(TLSEV));
  l->n = 1;
  l->ppl = 0;
  l->prim = -1;
  l->nelem = 0;
  l->vet = (TNO**) malloc(sizeof(TNO*));
  l->vet[0] = NULL;
  return l;
}

TNO * TLSEV_busca(TLSEV *l, int elem){
  int ind = l->prim;
  while((ind != -1) && (l->vet[ind]->info != elem)) ind = l->vet[ind]->prox;
  if(ind == -1) return NULL;
  return l->vet[ind];
}

void TLSEV_insere(TLSEV *l, int elem){
  l->vet[l->ppl] = (TNO *) malloc(sizeof(TNO));
  l->vet[l->ppl]->info = elem;
  l->vet[l->ppl]->prox = l->prim;
  l->prim = l->ppl;
  l->nelem++;
  if(l->n == l->nelem){
    l->vet = (TNO**)realloc(l->vet, 2 * l->n * sizeof(TNO*));
    int i;
    for(i = l->n; i < l->n * 2; i++) l->vet[i] = NULL;
    l->ppl = l->n;
    l->n *= 2;
    return;
  }
  int pos;
  do{
    pos = rand() % l->n;
    if((pos >= 0) && (l->vet[pos] == NULL)) break;
  }while(1);
  l->ppl = pos;
}

void TLSEV_imprime(TLSEV *l){
  int ind = l->prim;
  while(ind != -1){
    printf("elem = %d (%d)\tprox = %d\n", l->vet[ind]->info, ind, l->vet[ind]->prox);
    ind = l->vet[ind]->prox;
  }
}

void TLSEV_libera(TLSEV *l){
  int ind = l->prim;
  while(ind != -1){
    int temp = ind;
    ind = l->vet[ind]->prox;
    free(l->vet[temp]);
  }
  free(l->vet);
  free(l);
}

void TLSEV_retira(TLSEV *l, int elem){
  int ind = l->prim, ant = -1;
  while((ind != -1) && (l->vet[ind]->info != elem)){
    ant = ind;
    ind = l->vet[ind]->prox;
  }
  if(ind == -1) return;
  if(ant == -1) l->prim = l->vet[ind]->prox;
  else l->vet[ant]->prox = l->vet[ind]->prox;
  free(l->vet[ind]);
  l->vet[ind] = NULL;
  l->nelem--;
}
